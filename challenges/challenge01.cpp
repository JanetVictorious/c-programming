#include <assert.h>


void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void swap(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
}


int main(void)
{
    char a = 'a';
    char b = 'b';
    swap(&a, &b);
    assert(a == 'b');
    assert(b == 'a');
    swap(a, b);
    assert(a == 'a');
    assert(b == 'b');
}