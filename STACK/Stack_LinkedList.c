#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_LinkedList.h"

NodePtr sll_createStack(){
	return NULL;
}

bool sll_isEmpty(NodePtr stack){
	return (stack == NULL);
}

bool sll_stack_push(NodePtr *stack, int elem) {
    NodePtr temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return false; 
    }
    temp->data = elem;
    temp->next = NULL;

    if (sll_isEmpty(*stack)) {
        *stack = temp;
    } else {
        NodePtr trav = *stack;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = temp;
    }

    return true;
}



bool sll_stack_pop(NodePtr *stack){
    if(sll_isEmpty(*stack)){
        printf("Stack Linked List is empty.\n");
        return false;
    }
    else{
    	NodePtr trav = *stack;
        if((*stack)->next == NULL){
            free(*stack);
            *stack = NULL;
        }
        else{
            NodePtr prev = NULL;
            NodePtr trav = *stack;
            while(trav->next != NULL){
                prev = trav;
                trav = trav->next;
            }
            prev->next = NULL;
            free(trav);
        }
        return true;
    }
}


int sll_stack_peek(NodePtr stack){
    if(sll_isEmpty(stack)){
        printf("Stack Linked List is Empty\n");
        return 0;
    } else {
        NodePtr trav = stack;
        while(trav->next!= NULL){
            trav = trav->next;
        }
        return trav->data;
    }
}

void sll_display(NodePtr *stack) {
    if (sll_isEmpty(*stack)) {
        printf("Stack Linked List is Empty\n");
        return;
    }

    NodePtr temp = sll_createStack();
    NodePtr trav = *stack;

	printf("\nDISPLAY: \n");
	while (trav != NULL) {
	    int elem = trav->data;
	    printf("%d\n", elem);
	    sll_stack_push(&temp, elem);
	    trav = trav->next;
	}
	
	while (!sll_isEmpty(temp)) {
	    int elem = sll_stack_peek(temp);
	    sll_stack_push(&stack, elem);
	    sll_stack_pop(&temp);
	}
}



void sll_visualize(NodePtr stack) {
    if (sll_isEmpty(stack)) {
        printf("Stack Linked List is Empty.\n");
    } else {
    	printf("\nVISUALIZE");
        printf("\n INDEX        VALUE\n");
        int index = 0;
        NodePtr trav = stack;
        while (trav != NULL) {
            printf("   %d          %d", index, trav->data);
            if (trav->next == NULL) {
                printf("        <-- TOP");
            }
            printf("\n");
            trav = trav->next;
            index++;
        }
        printf("\n");
    }
}


void sll_stack_evenNumber(NodePtr *stack) {
    NodePtr evenStack = sll_createStack();
    NodePtr tempStack = sll_createStack();

    while (!sll_isEmpty(*stack)) {
        int elem = sll_stack_peek(*stack);
        sll_stack_pop(stack);  

        if (elem % 2 == 0) {
            sll_stack_push(&evenStack, elem);
        } else {
            sll_stack_push(&tempStack, elem);
        }
    }

    while (!sll_isEmpty(tempStack)) {
        int elem = sll_stack_peek(tempStack);
        sll_stack_pop(&tempStack);
        sll_stack_push(stack, elem);
    }

    printf("\nEVEN NUMBERS:");
    sll_visualize(evenStack);

    while (!sll_isEmpty(evenStack)) {
        sll_stack_pop(&evenStack);
    }
}

