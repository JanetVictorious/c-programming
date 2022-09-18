# Operators

C offers us a wide variety of operators that we can use to operate on data.

In particular, we can identify various groups of operators:

* arithmetic operators
* comparison operators
* logical operators
* compound assignment operators
* bitwise operators
* pointer operators
* structure operators
* miscellaneous operators

---

## Arithmetic operators

This macro group is separating binary operators and unary operators.

Binary operators work using two operands:

| Operator | Name | Example|
|:--------:|:----:|:------:|
| `=`      | Assignment | `a = b` |
| `+`      | Addition | `a + b` |
| `-`      | Subtraction | `a - b` |
| `*`      | Multiplication | `a * b` |
| `/`      | Division | `a / b` |
| `%`      | Modulo | `a % b` |

Unary operators only take one operand:

| Operator | Name | Example|
|:--------:|:----:|:------:|
| `+`      | Unary plus | `+a` |
| `-`      | Unary minus | `-a` |
| `++`      | Increment | `a++` or `++a` |
| `--`      | Decrement | `a--` or `--a` |

The difference between `a++` and `++a` is that `a++` increments the a variable after using it. `++a` increments the a variable before using it.

For example (see `increment1.c`):

```c
#include <stdio.h>

int main(void) {
    int a = 2;
    int b;
    b = a++;
    printf("b is %d, a is %d\n", b, a); /* b is 2, a is 3 */
    b = ++a;
    printf("b is %d, a is %d\n", b, a); /* b is 4, a is 4 */
}
```
