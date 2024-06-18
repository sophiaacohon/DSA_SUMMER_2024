#include <stdio.h>
#include <stdbool.h>
#include "CircularQueue.h"

void initQueue(CircularQ *q){
	q->front = -1;
	q->rear = -1;
}

bool isEmpty(CircularQ q){
	return ((q.rear + 1) % MAX-1 == q.front)? true: false;
}

bool isFull (CircularQ q){
	return ((q.rear + 2 ) % MAX-1  == q.front)? true : false;
}

void enqueue(CircularQ *q, int n){
	printf("ENQUEUE!! \n");
	printf("FRONT: %d\n", q->front);
	printf("REAR: %d\n", q->rear);
	if(isFull(*q)){
		printf("Circular Queue is full.\n");
	}
	else if(isEmpty(*q)){
		q->front = 0;
		q->rear = 0;
		q->data[q->rear] = n;
	}
	else if(q->rear == MAX-1){
		q->rear = 0;
		q->data[q->rear] = n;
	}
	q->rear++;
	q->data[q->rear] = n;
	
	
}

void dequeue(CircularQ *q){
	printf("DEQUEUE\n");
    printf("FRONT: %d\n", q->front);
    printf("REAR: %d\n", q->rear);
    
    if(isEmpty(*q)){
        printf("Circular Queue is Empty.\n");
        return;
    }
    
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % MAX;
    }
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
		printf("%d     %d", i, q->data[i]);
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
