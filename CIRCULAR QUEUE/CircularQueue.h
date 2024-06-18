#ifndef CIRCULARQUEUE
#define CIRCULARQUEUE

#include <stdbool.h>
#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
} CircularQ;

void initQueue(CircularQ *q);

bool isEmpty(CircularQ q);

bool isFull(CircularQ q);

void enqueue(CircularQ *q, int n);

void dequeue(CircularQ *q);

int front(CircularQ *q);

int rear(CircularQ *q);

void visualize(CircularQ *q);

#endif
