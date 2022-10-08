#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

struct ListItem
{
    uint32_t value;
    struct ListItem *next;
};

struct ListItem *first;

void setup()
{
    struct ListItem *prev = malloc(sizeof(struct ListItem));
    first = prev;
    prev->value = 0;
    for (int i = 0; i < 10; i++)
    {
        prev->value = i;
        prev->next = malloc(sizeof(struct ListItem));
        prev = prev->next;
    }
}

void printList()
{
    struct ListItem *current = first;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}

void revert()
{

}

void test()
{
    struct ListItem *prev = first;
    for (int i = 9; i >= 0; i--)
    {
        assert(prev->value == i);
        prev = prev->next;
    }
}

void cleanup()
{
    struct ListItem *current = first;
    while (current != NULL)
    {
        struct ListItem *toDelete = first;
        current = current->next;
        free(toDelete);
    }
}

int main(void)
{
    setup();
    printList();
    revert();
    printList();
    //test();
    cleanup();
    return 0;
}
