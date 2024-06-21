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

void display(SET s){
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
	printf("}");
}
