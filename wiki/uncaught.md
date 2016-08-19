---
layout: wiki
title: What happens when an exception cannot be caught?
---

# Uncaught Exceptions

When an exception is thrown, the exception handling framework looks for the appropriate `catch` block that can handle the exception. The system **unwinds** the call chain of the program and executes the `finally` blocks it finds.

When no `catch` block is able to handle an exception, the system eventually gets to the `main` function of the program. This situation is called an ***uncaught exception***.

# Uncaught Handler

When the exception context is set up, you can pass it an **uncaught handler** which will be executed in the event of an uncaught exception.

An uncaught handler is just an ordinary function wich receives the uncaught exception. This function might take care of cleaning up before termination, but it's not allowed to try and recover the current exception context.

There exists a convenience function to be used as the default uncaught handler, called `e4c_print_exception`. This function simply prints information regarding the exception to `stderr`, and then exits.

# Terminating

After the uncaught handler has been executed, either the program or the current thread will be terminated right away.

  - When the library is in **thread-unsafe** mode, the entire program will exit with a status code `EXIT_FAILURE`.
  - However, if the library is in **thread-safe** mode, then only the **offending** thread will be terminated with a status value `PTHREAD_CANCELED` and the program may continue.

If the canceled thread happens to be the last thread of the application, then the exit status code will be implementation-defined (read `pthread_exit` documentation).

----

<https://raw.githubusercontent.com/guillermocalvo/exceptions4c/master/etc/img/logo/exceptions4c_128.png>