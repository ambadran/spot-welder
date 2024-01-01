#include "tasks_sim.h"


// ************************ func_data_t Functions start *********************** //

func_data_t null_func_data(void) {

  func_data_t func_data = {NULL, };

  return func_data;

}

func_data_t void_func_data(func_ptr_t func_ptr) {

  func_data_t func_data = {func_ptr, };

  return func_data;

}

func_data_t uint8_func_data(func_ptr_t func_ptr, uint8_t value) {

  func_arg_t func_arg;
  func_arg.type = ARG_UINT8;
  func_arg.value.uint8_val = value;

  func_data_t func_data = {func_ptr, func_arg};

  return func_data;

}
// ************************* func_data_t Functions end ************************ //

// **************************************** TASK MANAGER IMPLEMENTATION START ************************************* //

void init_tasks(tasks_t* tasks) {

  // no use ?!?!
  /* if (tasks == NULL) { */
  /*   return; */
  /* } */

  tasks->size_periods = 0;
  tasks->size_funcs = 0;

  for (int i = 0; i < MAXIMUM_TASK_NUM; ++i) {
    tasks->funcs[i] = null_func_data();
    tasks->periods[i] = 0;   // Initialize priorities to 0 or any default value suitable for your context
  }

}

// highest value is the smallest time value
void push_task(tasks_t* tasks, uint16_t period, func_data_t func_data) {
    if (tasks->size_funcs == MAXIMUM_TASK_NUM) {
        // Handle queue overflow
        printf("OVERFLOW ERROR!! \n");
        return;
    }

    if (tasks->size_funcs == 0) {
      // TMR Value must be changed!
      TMR1 = PRELOAD(period);

      // Insert the new element
      tasks->funcs[0] = func_data;
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
      tasks->funcs[tasks->size_funcs] = func_data;
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
        tasks->funcs[i] = tasks->funcs[i - 1];
    }

    // Insert the new func element
    tasks->funcs[insertPos] = func_data;

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

void pop_task_push_func_queue_update_TMR(tasks_t* tasks, func_queue_t* func_queue) {

  if (tasks->size_funcs == 0) {

      // Handle empty queue
      return;

  //TODO: use % not if
  } else if (tasks->size_funcs == 1) {

    // The last element is the one to be popped
    push_func_q(func_queue, tasks->funcs[tasks->size_funcs-1]);
    tasks->size_funcs--;

  } else {

    // The last element is the one to be popped
    push_func_q(func_queue, tasks->funcs[tasks->size_funcs-1]);
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
    func_queue->funcs[i] = null_func_data();
  }

}

void push_func_q(func_queue_t* func_queue, func_data_t func_data) {

  if (func_queue->size == MAXIMUM_TASK_NUM) { printf("Trying to push a full queue!\n"); return; }

  // Insert the new func element
  func_queue->rear = (func_queue->rear + 1) % MAXIMUM_TASK_NUM;  // The % doesn't affect rear values, but when it reaches maximum it resets the value :D

  // Adding the data to the underlying func_data_t array
  func_queue->funcs[func_queue->rear] = func_data;

  // Updating size of func array
  func_queue->size++;

}

func_data_t pop_func_q(func_queue_t* func_queue) {

  if (func_queue->size == 0) { 
    printf("Trying to pop an empty queue!\n"); 
    return null_func_data(); 
  }

  func_data_t func_data = func_queue->funcs[func_queue->front];
  func_queue->front = (func_queue->front + 1) % MAXIMUM_TASK_NUM;
  func_queue->size--;

  return func_data;

}
// **************************************** TASK HOLDER IMPLEMENTATION FINISH ************************************* //


// ******************************************* PSEUDO-FUNCTIONS FOR TESTING **************************************** //
void func1() { printf("func1 run\n"); }
void func2() { printf("func2 run\n"); }
void func3(uint8_t arg) { printf("func3 run: %d\n", arg); }
void func4() { printf("func4 run\n"); }
void func5() { printf("func5 run\n"); }
void func6(uint8_t arg) { printf("func6 run: %d\n", arg); }
void func7(uint8_t arg) { printf("func7 run: %d\n", arg); }
// ****************************************************************************************************************** //


// ************************************* VISUALIZING THE DATA STRUCTURES ******************************************** //
void print_func_name(func_ptr_t func_ptr) {

    char* functionName = "N/A";
    for (int j = 0; j < functionLookupTableSize; ++j) {
        if (func_ptr == functionLookupTable[j].function) {
            functionName = functionLookupTable[j].name;
            break;
        }
    }
    printf("Function Name: %s\n", functionName);

}

char* get_func_name(func_ptr_t func_ptr) {

    char* functionName = "N/A";
    for (int j = 0; j < functionLookupTableSize; ++j) {
        if (func_ptr == functionLookupTable[j].function) {
            functionName = functionLookupTable[j].name;
            break;
        }
    }
    return functionName;

}


void print_tasks(const tasks_t *pq) {
    if (pq == NULL || pq->size_funcs == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue Contents @ (f_size %d) and (p_size %d):\n", pq->size_funcs, pq->size_periods);
    printf("|");
    for (int i = 0; i < MAXIMUM_TASK_NUM; ++i) {

        char* functionName = get_func_name(pq->funcs[i].func_ptr);

        if (i<pq->size_funcs) {
          printf("%s\t|", functionName);
        } else {
          printf("<%s>\t|", functionName);
        }
    }

    printf("\n|");
    for (int i = 0; i < MAXIMUM_TASK_NUM; ++i) {
        if (i<pq->size_periods) {
          printf("%d\t|", pq->periods[i]);
        } else {
          printf("<%d>\t|", pq->periods[i]);
        }
    }
    printf("\n\n");
}

void printQueue(const func_queue_t *q) {
    if (q == NULL) {
        printf("Queue pointer is NULL.\n");
        return;
    }

    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Function Queue Contents:\n");
    printf("|");
    int index = q->front;
    for (int i = 0; i < q->size; ++i) {
        char* functionName = get_func_name(q->funcs[index].func_ptr);
        /* char* functionName = get_func_name(&func1); */
        printf("\t%s\t|", functionName);

        index = (index + 1) % MAXIMUM_TASK_NUM;
    }
    printf("\n\n");
}
// ****************************************************************************************************************** //

int main() {
  printf("Starting..\n\n\n");
  

  tasks_t tasks;
  init_tasks(&tasks);

  func_queue_t func_queue;
  init_func_queue(&func_queue);

  // happenning in Main Routine, funcx is button press, charge, discharge sequence, ..
  TMR1 = 2875; // starting at a random TMR1 value
  push_task(&tasks, 200, void_func_data(&func1));
  printf("Pushed Task: func1, period: 200\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  TMR1 = PRELOAD(150);
  push_task(&tasks, 350, void_func_data(&func2));
  printf("Pushed Task: func2, period: 350\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  TMR1 = PRELOAD(120);
  // IMP: I casted the &func3 from (uint8_t) argument to (void*)
  push_task(&tasks, 350, uint8_func_data((func_ptr_t)&func3, 23)); 
  printf("Pushed Task: func3, period: 350\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  TMR1 = PRELOAD(100);
  push_task(&tasks, 400, void_func_data(&func4));
  printf("Pushed Task: func3, period: 400\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  // TMR1 FINISH, ISR called
  printf("\n\nPopping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // return to Main Loop after ISR
  printf("\n\nTMR value after ISR: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  while(func_queue.size != 0) {
    printf("Popping func_queue in Main Loop\n");
    /* printf("Popped: %s\n", get_func_name(pop_func_q(&func_queue))); */
    printf("executing popped function!\n");

    func_data_t func_data = pop_func_q(&func_queue);
    switch (func_data.func_arg.type) {

      case ARG_VOID:
        func_data.func_ptr(NULL);
        break;

      case ARG_UINT8:
        func_data.func_ptr(func_data.func_arg.value.uint8_val);
        break;

      default:
        // DEAL WITH UNDEFINED FUNC TYPES
        break;

    }

    printQueue(&func_queue);
  }

  // adding more tasks after poping some
  printf("\n\n");
  printf("TMR after overflow: %d\n", TMR1);
  printf("Adding more tasks now:\n");
  push_task(&tasks, 650, void_func_data(&func5));
  printf("Pushed Task: func5, period: 50\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  // TMR1 FINISH, ISR called
  printf("\n\nTMR1 OVERFLOW, ISR called\n");
  printf("Popping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // TMR1 FINISH, ISR called
  printf("\n\nTMR1 OVERFLOW, ISR called\n");
  printf("Popping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // TMR1 FINISH, ISR called
  printf("\n\nTMR1 OVERFLOW, ISR called\n");
  printf("Popping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // TMR1 FINISH, ISR called
  printf("\n\nTMR1 OVERFLOW, ISR called\n");
  printf("Popping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // adding more tasks after poping some
  printf("\n\n");
  printf("TMR after overflow: %d\n", TMR1);
  printf("Adding more tasks now:\n");
  // IMP: I casted the &func3 from (uint8_t) argument to (void*)
  push_task(&tasks, 230, uint8_func_data((func_ptr_t)&func6, 54));
  printf("Pushed Task: func6, period: 230\n");
  printf("TMR1: %d, preloaded: %d\n", TMR1, PRELOAD(TMR1));
  print_tasks(&tasks);

  // TMR1 FINISH, ISR called
  printf("\n\nTMR1 OVERFLOW, ISR called\n");
  printf("Popping a task and pushing to function queue\n");
  pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
  print_tasks(&tasks);
  printQueue(&func_queue);

  // return to Main Loop after ISR
  printf("\n\nMain Loop Now running\n");
  while(func_queue.size != 0) {
    printf("Popping func_queue in Main Loop\n");
    /* printf("Popped: %s\n", get_func_name(pop_func_q(&func_queue))); */
    printf("executing popped function!\n");

    func_data_t func_data = pop_func_q(&func_queue);
    switch (func_data.func_arg.type) {

      case ARG_VOID:
        func_data.func_ptr(NULL);
        break;

      case ARG_UINT8:
        func_data.func_ptr(func_data.func_arg.value.uint8_val);
        break;

      default:
        // DEAL WITH UNDEFINED FUNC TYPES
        break;

    }

    printQueue(&func_queue);

  }

  return 0;
}
