#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CircularQ cq;
	initQueue(&cq);
	visualize(&cq);
	enqueue(&cq, 10);
	printf("FRONT: %d\n", front(&cq));
	visualize(&cq);
	enqueue(&cq, 20);
	enqueue(&cq, 30);
	enqueue(&cq, 40);
	enqueue(&cq, 50);
	dequeue(&cq);
	printf("FRONT: %d\n", front(&cq));
	printf("REAR: %d\n", rear(&cq));
	visualize(&cq);
	enqueue(&cq, 60);
	enqueue(&cq, 70);
	enqueue(&cq, 80);
	enqueue(&cq, 90);
	printf("FRONT: %d\n", front(&cq));
	printf("REAR: %d\n", rear(&cq));
	visualize(&cq);
	enqueue(&cq, 100);
	enqueue(&cq, 110);
	printf("FRONT: %d\n", front(&cq));
	printf("REAR: %d\n", rear(&cq));
	visualize(&cq);
	enqueue(&cq, 120);
	dequeue(&cq);
	dequeue(&cq);
	dequeue(&cq);
	printf("FRONT: %d\n", front(&cq));
	printf("REAR: %d\n", rear(&cq));
	visualize(&cq);
	dequeue(&cq);
	enqueue(&cq, 130);
	enqueue(&cq, 140);
	enqueue(&cq, 150);
	printf("FRONT: %d\n", front(&cq));
	printf("REAR: %d\n", rear(&cq));
	visualize(&cq);
	
	return 0;
}
