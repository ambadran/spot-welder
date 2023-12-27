#ifndef TASKS_H
#define TASKS_H

typedef void (*func_ptr_t)();
#define NULL (func_ptr_t)0

typedef enum {
    ARG_VOID,
    ARG_UINT8
} ArgType;

typedef union {
    uint8_t uint8_val;
    // Add other types if needed
} ArgValue;

typedef struct {
    ArgType type;
    ArgValue value;
} func_arg_t;
extern const func_arg_t void_func_arg;

typedef struct {
  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  func_arg_t func_args[MAXIMUM_TASK_NUM];
  int8_t size;
  int8_t front;
  int8_t rear;
} func_queue_t;
func_queue_t func_queue;

typedef struct {

  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  func_arg_t func_args[MAXIMUM_TASK_NUM];
  uint16_t periods[MAXIMUM_TASK_NUM];
  uint8_t size_periods;
  uint8_t size_funcs;

} tasks_t;
tasks_t tasks;

func_arg_t init_uint8_func_arg(uint8_t value);
void init_tasks(tasks_t* tasks);
void push_task(tasks_t* tasks, func_ptr_t func_ptr, uint16_t period, func_arg_t func_arg);
void pop_task_push_func_queue_update_TMR(tasks_t* tasks, func_queue_t* func_queue);
func_ptr_t pop_task(tasks_t *tasks);
void pop_and_exec_task(tasks_t *tasks);

void init_func_queue(func_queue_t* func_queue);
void push_func_q(func_queue_t* func_queue, func_ptr_t func_ptr, func_arg_t func_arg);
func_ptr_t pop_func_q(func_queue_t* func_queue);

void tasks_init(void);

#endif
