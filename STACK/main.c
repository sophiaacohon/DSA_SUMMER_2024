#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"
#include "Stack_Array.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int option;
	
	do{
		printf("1. CREATE STACK");
		printf("2. INITALIZE STACK")';
		printf("3. PUSH STACK")
		printf("4. POP STACK");
		printf("Enter option: ");
		scanf("%d" &option);
	}while(option != 0);
	createStack();
	
	
	return 0;
}
