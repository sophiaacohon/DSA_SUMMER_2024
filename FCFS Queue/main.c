#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FCFS_Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ProcessQueue q;
	initQueue(&q);
	int n, a, b, i;
	printf("How many processes would you like to add?");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Process %d: \n", i+1);
		printf("Enter arrival time: ");
		scanf("%d", &a);
		printf("Enter burst time: ");
		scanf("%d", &b);
		// add the function call to create a new node and add new data to it
		//then add the function call to enqueue the node into the queue
	}
	//next, i want to show the process nodes added into the queue
	//then i want to sort the process nodes according to arrival time
	// and start computing for ET, CT, WT, TAT, also the avg WT and avg TAT
	// and then show the complete and computed process table.
	//welp, the wifi aint working.
	return 0;
}
