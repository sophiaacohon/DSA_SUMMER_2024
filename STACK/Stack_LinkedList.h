#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

#include<stdbool.h>
#define MAX 10

typedef struct node{
	int data;
	struct node *next;
} SLL, *SLLPtr;

bool isEmpty(SLLPtr s);

void initSLLStack(SLLPtr *s);

bool sll_stack_push(SLLPtr *s, int elem);
bool sll_stack_pop(SLLPtr *s);
int sll_stack_peek(SLLPtr s);

void display(SLLPtr s);

void visualize(SLLPtr s);

void sll_stack_evenNumber(SLLPtr *s);

#endif
