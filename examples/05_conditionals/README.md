# Conditionals

Any programming language provides the programmers the ability to perform choices.

We want to do X in some cases, and Y in other cases.

We want to check data, and make choices based on the state of that data.

C provides us 2 ways to do so.

The first is the `if` statement, with its `else` helper, and the second is the `switch` statement.

---

## if

In an `if` statement, you can check for a condition to be true, and then execute the block provided in the curly brackets:

```c
int a = 1;

if (a == 1) {
    /* do something */
}
```

You can append an `else` block to execute a different block if the original condition turns out to be false:

```c
int a = 1;

if (a == 1) {
    /* do something */
} else {
    /* do something else */
}
```

Beware of one common source of bugs - always use the comparison operator `==` in comparisons, and not the assignment operator `=`. If you don't, the `if` conditional check will always be true, unless the argument is `0`, for example if you do:

```c
int a = 0;

if (a = 0) {
    /* never invoked */
}
```

Because the conditional check will look for a boolean result (the result of a comparison), and the `0` number always equates to a false value. Everything else is true, including negative numbers.

You can have multiple else blocks by stacking together multiple if statements:

```c
int a = 1;

if (a == 2) {
    /* do something */
} else if (a == 1) {
    /* do something else */
} else {
    /* do something else again */
}
```

Another example (see `if_condition1.c`):

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Conversion string into int */
    int a;
    a = atoi(argv[1]);

    printf("Argument passed: arg1 = %d\n", a);


    if (a == 1) {
        printf("First if condition, a = %d\n", a);
    } else if (a == 2) {
        printf("First else condition, a = %d\n", a);
    } else {
        printf("Second else condition, a = %d\n", a);
    }
}
```

The output could look something like this:

```bash
$ ./if_condition1 1
> Argument passed: arg1 = 1
> First if condition, a = 1

$ ./if_condition1 2
> Argument passed: arg1 = 2
> First else condition, a = 2

$ ./if_condition1 3
> Argument passed: arg1 = 3
> Second else condition, a = 3

$ ./if_condition1 test
> Argument passed: arg1 = 0
> Second else condition, a = 0
```

---

## switch

If you need to do too many if / else / if blocks to perform a check, perhaps because you need to check the exact value of a variable, then `switch` can be very useful to you.

You can provide a variable as condition, and a series of `case` entry points for each value you expect (see `switch_condition1.c`):

```c
int a = 1;

switch (a) {
    case 0:
        /* do something */
        break;
    case 1:
        /* do something else */
        break;
    case 2:
        /* do something else */
        break;
}
```
