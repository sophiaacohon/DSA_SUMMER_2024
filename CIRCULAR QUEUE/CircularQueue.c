#include <stdio.h>
#include <stdbool.h>
#include "CircularQueue.h"

void initQueue(CircularQ *q){
	q->front = -1;
	q->rear = -1;
}

bool isEmpty(CircularQ q){
	return ((q.rear + 1) % MAX-1 == q.front);
}

bool isFull (CircularQ q){
	return ((q.rear + 2 ) % MAX-1  == q.front);
}

void enqueue(CircularQ *q, int n) {
    if (isFull(*q)) {
        printf("Circular Queue is full.\n");
        return;
    }
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = n;

    printf("Enqueued value: %d \n", n);
}

void dequeue(CircularQ *q) {
    if (isEmpty(*q)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    int dequeuedValue = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    
    printf("Dequeued value: %d\n", dequeuedValue);/*
    if (!isEmpty(*q)) {
        printf("FRONT: %d\n", q->front);
        printf("FRONT VALUE: %d\n", q->data[q->front]);
    } //debug */
}

int front(CircularQ *q){
	return q->data[q->front];
}

int rear(CircularQ *q){
	return q->data[q->rear];
}

void visualize(CircularQ *q){
	int i;
	if(isEmpty(*q)){
		printf("Circular Queue is Empty.\n");
	}
	printf("INDEX     VALUE\n");
	for(i=q->front; ; i = (i + 1) % MAX){
		printf("  %d        %d", i, q->data[i]);
		if(i == q->front){
			printf("     <--- FRONT");
		}
		else if(i == q->rear){
			printf("     <--- REAR");
		}
		printf("\n");
		if(i == q->rear){
			break;
		}
	}
}
