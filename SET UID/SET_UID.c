#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "SET_UID.h"


void initSet(SET s){
	int i;
	for(i=0; i<MAX; i++){
		s[i] = 0;
	}
}

void displaySet(SET s){
	int i;
	printf("{");
	for(i =0; i<MAX; i++){
		if(i == MAX-1){
			printf("%d", s[i]);
		}
		else{
			printf("%d, ", s[i]);
		}
	}
	printf("}\n");
	for(i =0; i<MAX; i++){
		if(s[i] == 1){
			printf(" %d ", i);
		}
		else{
			printf("   ");
		}
	}
	printf("\n");
}

void insertElement(SET *s, int n){
	if(n >= 0 && n < MAX){
		(*s)[n] = 1;
	}
	else{
		printf("Out of bounds.\n");
		return;
	}
}

void deleteElement(SET *s, int n){
	if(n >= 0 && n < MAX){
		(*s)[n] = 0;
	}
	else{
		printf("Out of bounds.\n");
		return;
	}
}

void unionSet(SET *A, SET *B){
	SET C;
	initSet(C);
	int i;
	for(i=0; i<MAX; i++){
		C[i] = (*A)[i] | (*B)[i];
	}
	printf("\nA UNION B \n");
	displaySet(C);
	//union: elements in A and elements in B are present in set C.
}

void intersectionSet(SET *A, SET *B){
	SET C;
	initSet(C);
	int i;
	for(i=0; i<MAX; i++){
		C[i] = (*A)[i] & (*B)[i];
	}
	printf("\nA INTERSECTION B\n");
	displaySet(C);
}
//intersection: the elements that are present in both A and B will be inserted in set C


void differenceSet(SET *A, SET *B){
	SET C;
	initSet(C);
	int i;
	for(i=0; i<MAX; i++){
		if((*A)[i] == 1 && (*B)[i] == 0){
			C[i] = 1;
		}
	}
	displaySet(C);
}
//elements present in A only will be present in set C


