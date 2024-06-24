#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
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
	//printf("Made a node\n"); //debug
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
		//printf("temp AT: %d", temp->data.AT);
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
    if (isEmpty(q)){
    	printf("Queue is Empty.\n");
    	return;
	} 

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

ProcessQueue calculate(ProcessQueue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return *q; 
    }
    
    ProcessQueue calculatedList;
    initQueue(&calculatedList);
    
    int begin = 0; // Initialize begin inside the loop for the first iteration
    double totalTAT = 0.0;
    double totalWT = 0.0; 
    int numProcesses = 0; // Keep track of the number of processes processed
    
    NodePtr trav = q->front;
    while(trav!= NULL){
        trav->data.ET = (begin >= trav->data.AT)? begin : trav->data.AT;

        trav->data.CT = trav->data.ET + trav->data.BT;
        
        begin = trav->data.CT;
        
        trav->data.TAT = trav->data.CT - trav->data.AT;
        
        trav->data.WT = trav->data.TAT - trav->data.BT;

        totalTAT += trav->data.TAT;
        totalWT += trav->data.WT;
        
        enqueue(&calculatedList, trav);

        trav = trav->next;
        numProcesses++; // Increment the count of processed processes
    }
    
    // Ensure we don't divide by zero and handle cases where the queue is empty
    if(numProcesses > 0) {
        double avgTAT = totalTAT / numProcesses;
        double avgWT = totalWT / numProcesses;
        
        printf("\nCalculated Table: \n");
        visualize(&calculatedList);
        
        printf("Average Turnaround Time: %.2f\n", avgTAT);
        printf("Average Waiting Time: %.2f\n", avgWT);
    } else {
        printf("No processes were processed.\n");
    }
    
    calculatedList.front = calculatedList.front->next;
    calculatedList.rear = calculatedList.rear->next;
    
    return calculatedList;
}

