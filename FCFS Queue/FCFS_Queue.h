#ifndef FCFS_QUEUE
#define FCFS_QUEUE

#include <stdbool.h>
typedef struct{
	int pID; //process ID
	int AT; //arrival time
	int BT; //burst time
	int ET; //execution time
	int CT; //completion time
	int TAT; //turn around time
	int WT; //waiting time
} Process;

typedef struct node{
	Process data;
	struct node *next;
} Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
} ProcessQueue;

void initQueue(ProcessQueue *q);

bool isEmpty(ProcessQueue *q);

NodePtr peek(ProcessQueue *q);

NodePtr addProcess(int a, int b, int ID);

void enqueue(ProcessQueue *q, NodePtr newNode);

NodePtr dequeue(ProcessQueue *q);

void visualize(ProcessQueue *q);

void sort(ProcessQueue *q);

ProcessQueue calc(ProcessQueue *q);

#endif
