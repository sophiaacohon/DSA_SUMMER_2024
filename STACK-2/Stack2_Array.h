#ifndef STACK2_ARRAY
#define STACK2_ARRAY

#include<stdbool.h>
#define MAX 10

typedef struct{
	int data[MAX];
	int top;
} StackArrayList;

bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);

//initialize
StackArrayList createStack(); //create an empty list, set your top to 0 or -1
void initStack(StackArrayList *s);


//operations
bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

void display(StackArrayList s);
//using push pop peek

void visualize(StackArrayList s);
//index   data
//  0      G      TOP

//traversal with for loop is not allowed


//others
// create a function that would get all even numbers and return as a new stack removing from the old stack
//

void stack_evenNumber(StackArrayList *s);



#endif
