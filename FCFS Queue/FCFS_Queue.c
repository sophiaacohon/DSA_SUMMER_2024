#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FCFS_Queue.h"

void initQueue(ProcessQueue *q){
	q = malloc(sizeof(ProcessQueue));
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(ProcessQueue *q){
	return (q->front == NULL && q->rear == NULL);
}

ProcessQueue addProcess(ProcessQueue *q, int a, int b);

void visualize(ProcessQueue *q);

void enqueue(ProcessQueue *q);

void dequeue(ProcessQueue *q);

void sort(ProcessQueue *q);

