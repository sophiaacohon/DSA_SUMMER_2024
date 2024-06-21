#ifndef FCFS_QUEUE
#define FCFS_QUEUE

#include <stdbool.h>
typedef struct{
	int AT; //arrival time
	int BT; //burst time
	int ET; //execution time
	int CT; //completion time
	int TAT; //turn around time
	int WT; //waiting time
} Process;

typedef struct node{
	Process PCB;
	struct node *next;
} Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
} ProcessQueue;

void initQueue(ProcessQueue *q);

bool isEmpty(ProcessQueue *q);

void enqueue(ProcessQueue *q, int a, int b);

void dequeue(ProcessQueue *q);

void sort(ProcessQueue *q);


#endif
