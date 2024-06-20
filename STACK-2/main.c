#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack2_Array.h"
#include "Stack2_LinkedList.h"
//#include "Stack_Array.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	printf("STACK USING ARRAYS\n");
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
	printf("\n");
	visualize(stack);
	
	printf("\nSTACK USING LINKED LISTS\n");
	NodePtr sll = sll_createStack();
	sll_visualize(sll);
	sll_stack_push(&sll, 21);
	sll_visualize(sll);
	sll_stack_push(&sll, 43);
	sll_visualize(sll);
	sll_stack_push(&sll, 1);
	sll_visualize(sll);
	sll_stack_pop(&sll);
	sll_visualize(sll);
	printf("PEEK: %d\n", sll_stack_peek(sll));
	sll_visualize(sll);
	sll_stack_push(&sll, 88);
	sll_stack_push(&sll, 99);
	sll_stack_push(&sll, 102);
	sll_stack_push(&sll, 61);
	sll_stack_push(&sll, 4);
	sll_stack_push(&sll, 94);
	sll_visualize(sll);
	sll_stack_evenNumber(&sll);
	printf("PEEK: %d\n", sll_stack_peek(sll));
	sll_visualize(sll);

	
	return 0;
}
