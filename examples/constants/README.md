# Constants

A constant is declared similarly to variables, except it is prepended with the `const` keyword, and you always need to specify a value.

Example:

```c
const int age = 37;
```

This is perfectly valid C, although it is common to declare constants uppercase, like this:

```c
const int AGE = 37;
```

It's just a convention, but one that can greatly help you while reading or writing a C program as it improves readability.

> Uppercase name means constant, lowercase name means variable.

Another way to define constants is by using this syntax:

```c
#define AGE 37
```

In this case, you don't need to add a type, and you don't also need the `=` equal sign, and you omit the semicolon at the end.
