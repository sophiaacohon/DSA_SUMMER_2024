#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack_Array.h"

StackArrayList createStack(){
	StackArrayList s;
	s->top = -1;
}

/*
void initStack(StackArrayList *s){
	s->top = -1;
}*/

bool isEmpty(StackArrayList s){
	if(s.top == -1){
		return true;
	}
}

bool isFull(StackArrayList s){
	if(s.top == MAX){
		return true;
	}
}

bool stack_push(StackArrayList *s, int elem){
	if(isFull(s)){
		printf("Stack is Full");
		return
	}
	else{
		s->data[s->data[s->top++]] == elem;
	}
}

bool stack_pop(StackArrayList *s){
	if(isEmpty(s)){
		printf("Stack is Empty");
	}
	else{
		s->data[s->data[s->top--]]
	}
}

int stack_peek(StackArrayList s){
	if(isEmpty){
		return;
	}
	else{
		printf("%d", s->data[s->top]);
	}
	
}

void display(StackArrayList s){
	//peek pop push help help
}

void visualize(StackArrayList s){
	int i;
	printf(" INDEX        VALUE     ");
	for(i = 0; i< s.top; i++){
		if(i == s.top){
			printf("   %d        %d        TOP\n", i, s[i]);
		}
		printf("   %d        %d\n")
	}
}

void stack_evenNumber(StackArrayList *s){
	
}

