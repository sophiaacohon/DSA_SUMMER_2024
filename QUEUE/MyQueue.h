#ifndef MYQUEUE_H
#define MYQUEUE_H

#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
} Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
} Queue;

void initQueue(Queue *q);

bool isEmpty(Queue *q);

void enqueue(Queue *q, int n);

void dequeue(Queue *q);

int front(Queue *q);

int rear(Queue *q);

#endif
