#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AdjList.h"

#define ROW 5
#define COL 5
#define NODE 65

char** initList(int row){
	int i, j;
	char** arr = (char**)malloc(row * sizeof(char*));
	if(arr == NULL){
		printf("Memory allocated for list failed.");
		exit(1);
	}
	for(i=0; i<row; i++){
		arr[i]=  (char*)malloc(COL * sizeof(char));
		if(arr == NULL){
			printf("Memory allocated for list failed.");
			exit(1);
		}
		for(j=0; j<5; j++){
			arr[i][j] = '\0';
		}
	}
	return arr;
}

void insertList(char v1, char v2, char** list){
	int idx = (int)v1 - NODE;
	//int idx2 = (int)v2 - 65;
	int j;
	for(j=0; j<COL; j++){
		if(list[idx][j] == '\0'){
			list[idx][j] = v2;
			break;
		}
	}
}

void displayList(int row, char** list){
	int i, j;
	int n = NODE;
	printf("DISPLAYING THE ADJACENCY LIST: \n");
	printf(" [\n");
	for(i=0; i<ROW; i++){
		printf("   \"%c\": [ ", n);
		int printed = 0;
		for(j=0; j<COL; j++){
			if(list[i][j] != '\0'){
				if(printed > 0){
					printf(", ");
				}
				printf("%c", list[i][j]);
				printed++;
			}
		}
		printf(" ],\n");
		n++;
	}
	printf(" ]\n");
}
