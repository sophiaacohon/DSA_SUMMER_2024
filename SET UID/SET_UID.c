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
	printf("SET: ");
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
	printf("\n");
}

void insertMember(SET s, int n){
	if(n > MAX || n < 0){
		printf("Out of bounds.\n");
		return;
	}
	s[n] = 1;
	/*
	int i, m;
	printf("\nHow many members would you like to add? ");
	scanf("%d", &m);
	if(m>MAX){
		printf("Number of members exceeds maximum number of members.\n");
		return;
	}
	int mem[m];
	//fflush(stdin);
	printf("\nInsert %d members: \n", m);
	for(i=0; i<m; i++){
		printf("Member no. %d: ", i+1);
		scanf("%d", &mem[i]);
	}
	for (i = 0; i < m; i++) {
		s[mem[i]] = 1;
    }
    // its better to add int parameter than user input this lol
    */
}

void deleteMember(SET s, int n){
	if(n > MAX || n < 0){
		printf("Out of bounds.\n");
		return;
	}
	s[n] = 0;
	/*
	int i, d;
	printf("How many members would you like to delete? ");
	scanf("%d", &d);
	if(d>MAX){
		printf("Number of members to be deleted exceeds maximum number of elements in a set.\n");
		return;
	}
	int del[d];
	printf("Enter element numbers to delete: ");
	for(i=0; i<d; i++){
		printf("Member no. %d: ", i+1);
		scanf("%d", &del[i]);
	}
	for(i=0; i<d; i++){
		s[del[i]] = 0;
	}
	// change this and add int parameter
	*/
}

void Union(SET A, SET B){
	SET C;
	initSet(C);
	int i;
	//will add insert member function here
	//need to change function parameters and function body to adjust to parameters
	//union: elements in A and elements in B are present in set C.
}

void intersection(SET A, SET B);
//intersection: the elements that are present in both A and B will be inserted in set C
//im tired

void difference(SET A, SET B);
//elements present in A only will be present in set C
// fdssdjfsfssdksfsdsfjhsdfsd

