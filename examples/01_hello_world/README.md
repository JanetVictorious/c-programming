# Hello, World! program

See file `hello.c`:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!");
}
```

We first import the `stdio` library (the name stands for standard input-output library). This library gives us access to input/output functions.

C is a very small language at its core, and anything that's not part of the core is provided by libraries. Some of those libraries are built by normal programmers, and made available for others to use. Some other libraries are built into the compiler. Like `stdio` and others.

`stdio` is the library that provides the `printf()` function.

This function is wrapped into the `main()` function. The `main()` function is the entry point of any C program.

To run the program, simply run the following in the terminal:

```bash
gcc hello.c -o hello
./hello
```
