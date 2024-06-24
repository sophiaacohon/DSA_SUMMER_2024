#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "FCFS_Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ProcessQueue q;
	initQueue(&q);
	//NodePtr 
	int n, a, b, i;
	int ID = 65;
	printf("How many processes would you like to add? ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nProcess %c: \n", ID);
		printf("Enter arrival time: ");
		scanf("%d", &a);
		printf("Enter burst time: ");
		scanf("%d", &b);
		NodePtr newNode = addProcess(a, b, ID);
		if (newNode == NULL ){
			printf("Failed to create new node");
			return -1;
		}
		enqueue(&q, newNode);
		
		ID++;

	}
	printf("\nVisualization of Processes: \n");
	visualize(&q);
	
	sort(&q);
	printf("\nSorted According to Arrival Time: \n");
	visualize(&q);
	
	calculate(&q);

	return 0;
}
