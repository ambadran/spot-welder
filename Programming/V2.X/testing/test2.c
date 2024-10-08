void call_func(void (*func_ptr)()) {

  printf("from call_func()\n");
  func_ptr();

}
void call_func_with_arg(void (*func_ptr)(), int arg) {

  printf("from call_func()\n");
  func_ptr(arg);

}
