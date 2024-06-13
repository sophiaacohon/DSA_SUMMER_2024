#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"
#include "Stack_Array.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int option;
	
	do{
		printf("1. CREATE STACK\n");
		printf("2. INITALIZE STACK\n")';
		printf("3. PUSH STACK\n")
		printf("4. POP STACK\n");
		printf("5. DISPLAY STACK\n");
		printf("6. VISUALIZE STACK\n");
		printf("Enter option: ");
		scanf("%d" &option);
	}while(option != 0);
	createStack();
	
	
	return 0;
}
