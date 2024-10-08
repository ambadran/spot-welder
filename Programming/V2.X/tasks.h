#ifndef TASKS_H
#define TASKS_H

// **************************************** TASK MANAGER IMPLEMENTATION START ************************************* //
typedef void (*func_ptr_t)();

typedef struct {
  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  int8_t size;
  int8_t front;
  int8_t rear;
} func_queue_t;
func_queue_t func_queue;

typedef struct {

  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  uint16_t periods[MAXIMUM_TASK_NUM];
  uint8_t size_periods;
  uint8_t size_funcs;

} tasks_t;
tasks_t tasks;

void init_tasks(tasks_t* tasks);
void push_task(tasks_t* tasks,uint16_t period, func_ptr_t func_ptr);
void pop_task_push_func_queue_update_TMR(tasks_t* tasks, func_queue_t* func_queue);

void init_func_queue(func_queue_t* func_queue);
void push_func_q(func_queue_t* func_queue, func_ptr_t func_ptr);
func_ptr_t pop_func_q(func_queue_t* func_queue);

void tasks_module_init(void);

#endif
