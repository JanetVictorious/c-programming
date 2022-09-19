#include <stdio.h>

int main(int argc, char **argv) {
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; ++i) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
}

/*
Compile program by running:
gcc passing_arguments1.c -o passing_arguments1

Invoke program (and pass arguments) by running:
./passing_arguments1
./passing_arguments1 something
./passing_arguments1 something something_else
*/
