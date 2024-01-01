/*
 * File:   tasks.c
 * Author: mr-atom
 *
 * Created on December 23, 2023, 3:56 AM
 */

#include "includes.h"

// **************************************** TASK MANAGER IMPLEMENTATION START ************************************* //

void init_tasks(tasks_t* tasks) {

  // no use ?!?!
  /* if (tasks == NULL) { */
  /*   return; */
  /* } */

  tasks->size_periods = 0;
  tasks->size_funcs = 0;

  for (int i = 0; i < MAXIMUM_TASK_NUM; ++i) {
    tasks->func_ptrs[i] = NULL;
    tasks->periods[i] = 0;   // Initialize priorities to 0 or any default value suitable for your context
  }

}


// highest value is the smallest time value
void push_task(tasks_t* tasks, uint16_t period, func_ptr_t func_ptr) {
    if (tasks->size_funcs == MAXIMUM_TASK_NUM) {
        // Handle queue overflow
        /* printf("OVERFLOW ERROR!! \n"); */
        lcd_set_cursor(1, 1);
        lcd_write_string("tasks overflow");
        return;
    }

    if (tasks->size_funcs == 0) {
      // TMR Value must be changed!
      TMR1 = PRELOAD(period);

      // Insert the new element
      tasks->func_ptrs[0] = func_ptr;
      tasks->size_funcs++;

      return;
    }

    // handle if period > TMR1
    uint16_t preloaded_TMR1 = PRELOAD(TMR1);
    if (period <= preloaded_TMR1) {
      
      // TMR Value must be changed!
      TMR1 = PRELOAD(period);

      // Insert the new element
      tasks->periods[tasks->size_periods] = preloaded_TMR1 - period;
      tasks->size_periods++;
      tasks->func_ptrs[tasks->size_funcs] = func_ptr;
      tasks->size_funcs++;

      return;

    }

    // Start from the end (smallest period value) and find the position
    uint16_t cumulativeSum = preloaded_TMR1;
    uint16_t insertPos = 0;
    for (int8_t i = tasks->size_periods - 1; i >= 0; --i) {
        cumulativeSum += tasks->periods[i];
        if (cumulativeSum >= period) {
            // Found the position where the cumulative sum exceeds or equals the period
            insertPos = i + 1;
            break;
        }
    }

    // Shift func elements to make room for the new element
    for (int8_t i = tasks->size_funcs; i > insertPos; --i) {
        tasks->func_ptrs[i] = tasks->func_ptrs[i - 1];
    }

    // Insert the new func element
    tasks->func_ptrs[insertPos] = func_ptr;

    // Updating size of func array
    tasks->size_funcs++;

    // Shift period elements to make room for the new element
    for (int8_t i = tasks->size_periods; i > insertPos; --i) {
        tasks->periods[i] = tasks->periods[i - 1];
    }

    // Insert the new period element
    // if period is greater than all previous times combined
    if (period > cumulativeSum) {
      tasks->periods[insertPos] = period - cumulativeSum;
    } else {
      tasks->periods[insertPos] = period - cumulativeSum + tasks->periods[insertPos-1]; // last
      tasks->periods[insertPos-1] -= tasks->periods[insertPos]; // before last
    }
    // Updating size of period array
    tasks->size_periods++;

}

/* void push_extended_task(tasks_t* tasks, uint32_t period, func_ptr_t func_ptr) { */

/*   // accedentically passing a normal period to an extended period function */
/*   if (period < MAXIMUM_TMR_PERIOD) { */

/*     push_task(tasks, (uint16_t)period, func_ptr); */

/*   } else { */

/*     //TODO: develop and algorithm that will call push_task n times with correct periods to finish the long task */

/*   } */

/* } */

void pop_task_push_func_queue_update_TMR(tasks_t* tasks, func_queue_t* func_queue) {

  //TODO: use % not if
  if (tasks->size_funcs == 0) {

      // Handle empty queue

      return;

  } else if (tasks->size_funcs == 1) {

    // The last element is the one to be popped
    push_func_q(func_queue, tasks->func_ptrs[tasks->size_funcs-1]);
    tasks->size_funcs--;

  } else {

    // The last element is the one to be popped
    push_func_q(func_queue, tasks->func_ptrs[tasks->size_funcs-1]);
    TMR1 = PRELOAD(tasks->periods[tasks->size_periods-1]);

    tasks->size_funcs--;
    tasks->size_periods--;

  }

}

// **************************************** TASK MANAGER IMPLEMENTATION FINISH ************************************* //


// **************************************** TASK HOLDER IMPLEMENTATION START ************************************* //
void init_func_queue(func_queue_t* func_queue) {

  func_queue->size = 0;
  func_queue->front = 0;
  func_queue->rear = -1;
  for (int i = 0; i < MAXIMUM_TASK_NUM; ++i) {
    func_queue->func_ptrs[i] = NULL;
  }

}

void push_func_q(func_queue_t* func_queue, func_ptr_t func_ptr) {

  if (func_queue->size == MAXIMUM_TASK_NUM) { 
    /* printf("Trying to push a full queue!\n"); */ 
    return; 
  }

  // Insert the new func element
  func_queue->rear = (func_queue->rear + 1) % MAXIMUM_TASK_NUM;  // The % doesn't affect rear values, but when it reaches maximum it resets the value :D

  // Adding the data to the underlying func_ptr_t array
  func_queue->func_ptrs[func_queue->rear] = func_ptr;

  // Updating size of func array
  func_queue->size++;

}

func_ptr_t pop_func_q(func_queue_t* func_queue) {

  if (func_queue->size == 0) { 
    /* printf("Trying to pop an empty queue!\n"); */ 
    return NULL; 
  }

  func_ptr_t func_ptr = func_queue->func_ptrs[func_queue->front];
  func_queue->front = (func_queue->front + 1) % MAXIMUM_TASK_NUM;
  func_queue->size--;

  return func_ptr;

}
// **************************************** TASK HOLDER IMPLEMENTATION FINISH ************************************* //



void tasks_module_init(void) {

  init_tasks(&tasks);
  init_func_queue(&func_queue);

}
