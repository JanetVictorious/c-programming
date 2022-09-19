#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    /* Conversion string into int */
    int a;
    a = atoi(argv[1]);

    switch (a)
    {
    case 0:
        printf("Argument a is %d", a);
        break;
    
    case 1:
        printf("Argument a is %d", a);
        break;
    
    case 2:
        printf("Argument a is %d", a);
        break;
    
    default:
        printf("Argument a is %d", a);
        break;
    }
}
