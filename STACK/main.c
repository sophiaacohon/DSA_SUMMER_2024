#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"
//#include "Stack_Array.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList stack = createStack();
	stack_peek(stack);
	stack_push(&stack, 21);
	visualize(stack);
	stack_push(&stack, 43);
	stack_push(&stack, 1);
	stack_push(&stack, 88);
	stack_push(&stack, 99);
	visualize(stack);
	//stack_pop(&stack);
	visualize(stack);
	stack_push(&stack, 100);
	visualize(stack);
	stack_peek(stack);
	printf("DISPLAY: \n");
	display(stack);
	visualize(stack);
	stack_evenNumber(&stack);
	
	
	return 0;
}
