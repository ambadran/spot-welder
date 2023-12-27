  push_task(&tasks, &func1, 300, void_func_arg);
  push_task(&tasks, &func2, 200, void_func_arg);
  push_task(&tasks, &func4, 100, void_func_arg);
  push_task(&tasks, &func5, 130, void_func_arg);

  printQueue(&tasks);

  /* pop_task(&tasks)(); */
  /* pop_task(&tasks)(); */
  /* pop_and_exec_task(&tasks); */
  /* pop_and_exec_task(&tasks); */

  /* printQueue(&tasks); */

  push_task(&tasks, &func4, 250, void_func_arg);
  printQueue(&tasks);
  push_task(&tasks, &func5, 330, void_func_arg);
  push_task(&tasks, &func5, 730, void_func_arg);
  
  /* push_task(&tasks, &func6, 250, init_uint8_func_arg(23)); */
  /* push_task(&tasks, &func7, 350, init_uint8_func_arg(43)); */

  printQueue(&tasks);


