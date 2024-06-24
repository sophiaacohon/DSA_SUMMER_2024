#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FCFS_Queue.h"

void initQueue(ProcessQueue *q){
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(ProcessQueue *q){
	return (q->front == NULL && q->rear == NULL);
}

NodePtr peek(ProcessQueue *q){
	if(isEmpty(q)){
		printf("Queue is Empty.\n");
		return NULL;
	}
	else{
		printf("peek AT: %d", q->front->data.AT);
		return q->front;
	}
}

NodePtr addProcess(int a, int b, int ID){
	NodePtr newNode = malloc(sizeof(Node));
	printf("Made a node\n");
	newNode->data.pID = ID;
	newNode->data.AT = a;
	newNode->data.BT = b;
	newNode->data.CT = 0;
	newNode->data.ET = 0;
	newNode->data.TAT = 0;
	newNode->data.WT = 0;
	newNode->next = NULL;
	return newNode;
}

void enqueue(ProcessQueue *q, NodePtr newNode){
	
	if(isEmpty(q)){
		q->front = newNode;
		q->rear = newNode;
	}
	else{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

NodePtr dequeue(ProcessQueue *q){
	if(isEmpty(q)){
		printf("Queue is Empty.\n");
		return NULL;
	}
	else{
		NodePtr temp= q->front;
		q->front = q->front->next;
		
		if(q->front == NULL){
			q->rear == NULL;
		}
		
		temp->next = NULL;
		printf("temp AT: %d", temp->data.AT);
		return temp;
	}
}

void visualize(ProcessQueue *q){
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
    } else {
        NodePtr trav;
        printf("PROCESS ID\tAT\tBT\tET\tCT\tTAT\tWT\n");
        for (trav = q->front; trav!= NULL; trav = trav->next) {
            printf("%c\t\t%d\t%d\t%d\t%d\t%d\t%d\n", 
                   trav->data.pID, 
                   trav->data.AT, 
                   trav->data.BT, 
                   trav->data.ET, 
                   trav->data.CT, 
                   trav->data.TAT, 
                   trav->data.WT);
        }
    }
}

void sort(ProcessQueue *q) {
    if (isEmpty(q)) return;

    ProcessQueue sortedList;
    initQueue(&sortedList);

    NodePtr current = q->front;
    while (current!= NULL) {
        NodePtr next = current->next;
        current->next = NULL; 

        NodePtr temp = sortedList.front;
        NodePtr prev = NULL;
        while (temp!= NULL) {
            if (temp->data.AT < current->data.AT || 
                (temp->data.AT == current->data.AT && temp->data.pID < current->data.pID)) {
                prev = temp;
                temp = temp->next;
            } else {
                break;
            }
        }

        if (prev == NULL) {
            current->next = sortedList.front;
            sortedList.front = current;
        } else {
            current->next = prev->next;
            prev->next = current;
        }

        current = next;
    }

    q->front = sortedList.front;
    q->rear = sortedList.rear;
}


ProcessQueue calc(ProcessQueue *q){
	if(isEmpty(q)){
		return;
	}
	int begin = 0;
}

