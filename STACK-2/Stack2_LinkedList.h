#ifndef STACK2_LINKEDLIST
#define STACK_2LINKEDLIST

#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *NodePtr;

NodePtr sll_createStack();

bool sll_isEmpty(NodePtr head);

bool sll_stack_push(NodePtr *head, int elem);

bool sll_stack_pop(NodePtr *head);

int sll_stack_peek(NodePtr head);

void sll_display(NodePtr head);

void sll_visualize(NodePtr head);

void sll_stack_evenNumber(NodePtr *head);

#endif

