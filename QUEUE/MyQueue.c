#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyQueue.h"
 
void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;

}

bool isEmpty(Queue* q){
	if(q->front == NULL && q->rear == NULL){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(Queue *q, int n){
	NodePtr temp = malloc(sizeof(Node));
	temp->data = n;
	temp->next = NULL;
	if(isEmpty(*q) == true){
		q->front = temp;
		q->rear = temp;
	}
	else{
		q->rear->next = temp;
		q->rear = temp;
	}
}

void dequeue(Queue *q){
	NodePtr temp;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
}

int front(Queue *q){
	return q->front;
}

int rear(Queue *q){
	return q->rear;
}

