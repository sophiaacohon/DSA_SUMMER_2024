#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_Array.h"
#include "Stack_LinkedList.h"
//#include "Stack_Array.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
/*
	StackArrayList stack = createStack();
	stack_peek(stack);
	stack_push(&stack, 21);
	visualize(stack);
	stack_push(&stack, 43);
	stack_push(&stack, 1);
	stack_push(&stack, 88);
	stack_push(&stack, 99);
	visualize(stack);
	stack_pop(&stack);
	visualize(stack);
	stack_push(&stack, 100);
	visualize(stack);
	stack_peek(stack);
	printf("DISPLAY: \n");
	display(stack);
	visualize(stack);
	stack_evenNumber(&stack);
*/	
	
	NodePtr sll = sll_createStack();
	sll_visualize(sll);
	sll_stack_push(&sll, 10);
	sll_visualize(sll);
	sll_stack_push(&sll, 20);
	sll_visualize(sll);
	sll_stack_push(&sll, 30);
	sll_visualize(sll);
	sll_stack_pop(&sll);
	sll_visualize(sll);

	
	return 0;
}
