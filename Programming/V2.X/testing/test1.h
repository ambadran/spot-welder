#include <stdio.h>
#include <stdint.h>


#define PRELOAD(v) (65535 - v)
uint16_t TMR1; // for simulation


// **************************************** TASK MANAGER IMPLEMENTATION START ************************************* //
#define MAXIMUM_TASK_NUM 8
typedef void (*func_ptr_t)();

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

// should be with task holder implementation
typedef struct {
  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  func_arg_t func_args[MAXIMUM_TASK_NUM];
  int8_t size;
  int8_t front;
  int8_t rear;
} func_queue_t;

typedef struct {

  func_ptr_t func_ptrs[MAXIMUM_TASK_NUM];
  func_arg_t func_args[MAXIMUM_TASK_NUM];
  uint16_t periods[MAXIMUM_TASK_NUM];
  uint8_t size_periods;
  uint8_t size_funcs;

} tasks_t;


func_arg_t init_uint8_func_arg(uint8_t value);
void init_tasks(tasks_t* tasks);
void push_task(tasks_t* tasks, func_ptr_t func_ptr, uint16_t period, func_arg_t func_arg);
void pop_task_push_func_queue_update_TMR(tasks_t* tasks, func_queue_t* func_queue);
func_ptr_t pop_task(tasks_t *tasks);
void pop_and_exec_task(tasks_t *tasks);

void init_func_queue(func_queue_t* func_queue);
void push_func_q(func_queue_t* func_queue, func_ptr_t func_ptr, func_arg_t func_arg);
func_ptr_t pop_func_q(func_queue_t* func_queue);

void func1();
void func2();
void func3(int arg);
void func4();
void func5();
void func6(int arg);
void func7(int arg);

typedef struct {
    func_ptr_t function;
    const char* name;
} FunctionInfo;


FunctionInfo functionLookupTable[] = {
    {func1, "F1"},
    {func2, "F2"},
    {func3, "F3"},
    {func4, "F4"},
    {func5, "F5"},
    {func6, "F6"},
    {func7, "F7"}
    // Add more functions as needed
};
int functionLookupTableSize = sizeof(functionLookupTable) / sizeof(FunctionInfo);

void print_func_name(func_ptr_t func_ptr);
char* get_func_name(func_ptr_t func_ptr);
void print_tasks(const tasks_t *pq);
void printQueue(const func_queue_t *q);
