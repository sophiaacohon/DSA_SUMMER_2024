#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *NodePtr;

NodePtr sll_createStack();

bool sll_isEmpty(NodePtr stack);

bool sll_stack_push(NodePtr *stack, int elem);

bool sll_stack_pop(NodePtr *stack);
void sll_stack_peek(NodePtr stack);

void sll_display(NodePtr stack);
void sll_visualize(NodePtr stack);
void sll_stack_evenNumber(NodePtr *stack);

#endif

