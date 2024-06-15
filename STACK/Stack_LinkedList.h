#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} SLL, *SLLPtr;

typedef struct {
    SLLPtr top;
} StackLinkedList;

StackLinkedList createStack();

bool sll_isEmpty(StackLinkedList s);

bool sll_stack_push(StackLinkedList *s, int elem);
bool sll_stack_pop(StackLinkedList *s);
int sll_stack_peek(StackLinkedList s);

void sll_display(StackLinkedList s);
void sll_visualize(StackLinkedList s);
void sll_stack_evenNumber(StackLinkedList *s);

#endif

