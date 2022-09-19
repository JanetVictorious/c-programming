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
