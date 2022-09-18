#include <stdio.h>

int main(void) {
    int a = 2;
    int b;
    b = a++;
    printf("b is %d, a is %d\n", b, a);
    b = ++a;
    printf("b is %d, a is %d\n", b, a);
}
