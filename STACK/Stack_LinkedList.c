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
    }
    else{
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
    }
}


int sll_stack_peek(NodePtr stack);

void sll_display(NodePtr stack);


void sll_visualize(NodePtr stack) {
    if (sll_isEmpty(stack)) {
        printf("Stack Linked List is Empty.\n");
    } else {
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



void sll_stack_evenNumber(NodePtr *stack);

