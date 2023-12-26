#include <stdio.h>

void func1() { printf("func1\n"); }
void func2() { printf("func2\n"); }
void func3(int arg) { printf("func3: %d", arg); }

void call_func(void (*func_ptr)()) {

  printf("from call_func()\n");
  func_ptr();

}

void call_func_with_arg(void (*func_ptr)(), int arg) {

  printf("from call_func()\n");
  func_ptr(arg);

}



int main() {
  printf("\n\n\n");

  call_func(&func2); 

  call_func_with_arg(&func3, 16);

  return 0;
}
