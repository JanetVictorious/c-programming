# Variables and types

C is a statically typed language. This means that any variable has an associated type, and this type is known at compilation time.

When you create a variable in C, you have to specify the type of a variable at the declaration.

A variable name can contain any uppercase or lowercase letter, can contain digits and the underscore character, but it can't start with a  digit. `AGE` and `Age10` are valid variable names, `1age` is not.

In this example we initialize a variable `age` with type `int`:

```c
int age;
```

We can also initialize a variable at declaration, specifying the initial value:

```c
int age = 37;
```

Once you declare a variable, you are then able to use it in your program code. You can change its value at any time, using the `=` operator for example, like in `age = 100;` (provided the new value is of the same type).

The C built-in data types are `int`, `char`, `short`, `long`, `float`, `double`, `long double`.

Example:

```c
#include <stdio.h>

int main(void) {
    int age = 0;
    age = 37.2;
    printf("%u", age);
}
```

This will raise a warning at compile time and will convert the decimal value to integer.

Try by running:

```bash
$ gcc variable1.c -o variable1
> variable1.c:5:11: warning: implicit conversion from 'double' to 'int' > changes value from 37.2 to 37 [-Wliteral-conversion]
>     age = 37.2;
>         ~ ^~~~
> 1 warning generated.
```

and check the output:

```bash
$ ./variable1
> 37%
```

---

## Integer numbers

C provides us the following types to define integer values: `char`, `int`, `short`, `long`.

The `char` type is commonly used to store letters of the ASCII chart, but it can be used to hold small integers from -128 to 127. It takes at least 1 byte.

`int` takes at least 2 bytes. `short` takes at least 2 bytes. `long` takes at least 4 bytes.

As you can see, we are not guaranteed the same values for different environments. We only have an indication. The problem is that the exact numbers that can be stored in each data type depends on the implementation and the architecture.

We're guaranteed that `short` is not longer than `int`. And we're guaranteed `long` is not shorter than `int`.

The ANSI C spec standard determines the minimum values of each type, and thanks to it we can at least know what's the minimum value we can expect to have at our disposal.

If you are programming C on an Arduino, different board will have different limits.

On an Arduino Uno board, `int` stores a 2 byte value, ranging from `-32768` to `32767`. On a Arduino MKR 1010, `int` stores a 4 bytes value, ranging from `-2147483648` to `2147483647`. Quite a big difference.

On all Arduino boards, `short` stores a 2 bytes value, ranging from `-32768` to `32767`. `long` store 4 bytes, ranging from `-2147483648` to `2147483647`.

---

## Unsigned integers

For all the above data types, we can prepend `unsigned` to start the range at 0, instead of a negative number. This might make sense in many cases.

* `unsigned char` will range from `0` to at least `255`
* `unsigned int` will range from `0` to at least `65535`
* `unsigned short` will range from `0` to at least `65535`
* `unsigned long` will range from `0` to at least `4294967295`

---

## The problem with overflow

Given all those limits, a question might come up: how can we make sure our numbers do not exceed the limit? And what happens if we do exceed the limit?

If you have an `unsigned int` number at 255, and you increment it, you'll get 256 in return (see `unsigned_int.c`). As expected. If you have an `unsigned char` number at 255, and you increment it, you'll get 0 in return. It resets starting from the initial possible value.

If you have a `unsigned char` number at 255 and you add 10 to it, you'll get the number 9 (see `unsigned_char.c`):

```c
#include <stdio.h>

int main(void) {
    unsigned char j = 255;
    j = j + 10;
    printf("%u", j); /* 9 */
}
```

If you don't have a signed value, the behavior is undefined. It will basically give you a huge number which can vary, like in this case:

```c
#include <stdio.h>

int main(void) {
    char j = 127;
    j = j + 10;
    printf("%u", j); /* 4294967177 */
}
```

In other words, C does not protect you from going over the limits of a type. You need to take care of this yourself.

---

## Warnings when declaring the wrong type

When you declare the variable and initialize it with the wrong value, the `gcc` compiler should warn you:

```c
#include <stdio.h>

int main(void) {
    char j = 1000;
    printf("%u", j); /* 4294967272 */
}
```

```bash
$ gcc warning1.c -o warning1
> warning1.c:4:14: warning: implicit conversion from 'int' to 'char' changes value from 1000 to -24 [-Wconstant-conversion]
>     char j = 1000;
>          ~   ^~~~
> 1 warning generated.
```

And it also warns you in direct assignments:

```c
#include <stdio.h>

int main(void) {
    char j;
    j = 1000;
    printf("%u", j); /* 4294967272 */
}
```

```bash
$ gcc warning2.c -o warning2
> warning2.c:5:9: warning: implicit conversion from 'int' to 'char' changes value from 1000 to -24 [-Wconstant-conversion]
>     j = 1000;
>       ~ ^~~~
> 1 warning generated.
```

But not if you increase the number using, for example, `+=`:

```c
#include <stdio.h>

int main(void) {
    char j = 0;
    j += 1000;
    printf("%u", j); /* 4294967272 */
}
```

---

## Floating point numbers
