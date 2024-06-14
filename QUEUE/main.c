#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	Queue *q = malloc(sizeof(Queue));
	initQueue(q);
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	//front(q);
	printf("FRONT: %d\n", front(q));
	printf("REAR: %d\n", rear(q));
	dequeue(q);
	printf("FRONT: %d\n", front(q));
	enqueue(q, 40);
	printf("FRONT: %d\n", front(q));
	printf("REAR: %d\n", rear(q));
	
	return 0;
}
