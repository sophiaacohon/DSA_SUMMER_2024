#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack2_Array.h"

StackArrayList createStack() {
    StackArrayList s;
    s.top = -1;
    return s;
}

bool isEmpty(StackArrayList s) {
    return s.top == -1;
}

bool isFull(StackArrayList s) {
    return s.top == MAX - 1;
}

bool stack_push(StackArrayList *s, int elem) {
    if (isFull(*s)) {
        printf("Stack is Full.\n");
        return false;
    } else {
        s->data[++(s->top)] = elem;
        return true;
    }
}

bool stack_pop(StackArrayList *s) {
    if (isEmpty(*s)) {
        printf("Stack is Empty.\n");
        return false;
    } else {
        s->top--;
        return true;
    }
}

int stack_peek(StackArrayList s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return -1;
    } else {
        printf("TOP ELEMENT: %d\n", s.data[s.top]);
        return s.data[s.top];
    }
}

void display(StackArrayList s) {
    int elem;
    StackArrayList temp = createStack();
    while(!isEmpty(s)){
    	elem = s.data[s.top];
		stack_push(&temp, elem);
		printf("%d\n", elem);
		stack_pop(&s);	
	}
	while(!isEmpty(temp)){
		elem = temp.data[temp.top];
		stack_push(&s, elem);
		stack_pop(&temp);
	}
}

void visualize(StackArrayList s) {
    int i;
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("\n INDEX        VALUE\n");
        for (i = s.top; i >= 0; i--) {
            printf("   %d          %d", i, s.data[i]);
            if (i == s.top) {
                printf("        <-- TOP");
            }
            printf("\n");
        }
        printf("\n");
    }
}

void stack_evenNumber(StackArrayList *s) {
    StackArrayList evenStack = createStack();
    StackArrayList oddStack = createStack();
    int elem;

    while (!isEmpty(*s)) {
        elem = s->data[s->top];
        if (elem % 2 == 0) {
            stack_push(&evenStack, elem);
        } else {
            stack_push(&oddStack, elem);
        }
        stack_pop(s);
    }

    printf("Even Numbers:\n");
    while (!isEmpty(evenStack)) {
        elem = stack_peek(evenStack); 
        stack_pop(&evenStack);
    }
    printf("\n");

    while(!isEmpty(oddStack)){
    	stack_push(s, stack_peek(oddStack));
    	stack_pop(&oddStack);
	}
}

