#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyQueue.h"
 
void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(Queue* q){
	return(q->front == NULL && q->rear == NULL)?true:false;
}

void enqueue(Queue *q, int n){
	NodePtr temp = malloc(sizeof(Node));
	if(temp == NULL){
		printf("Memory not allocated");
	}
	temp->data = n;
	temp->next = NULL;
	if(isEmpty(q)){
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
	return (q->front != NULL)? q->front->data : -1;
}

int rear(Queue *q){
	return (q->rear != NULL)? q->rear->data : -1;
}

