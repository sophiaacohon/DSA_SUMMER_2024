#include <stdio.h>
#include <string.h>
#include "AdjMatrix.h"

#define ROW 5
#define COL 5
#define NODE 65

void initMatrix(int row, int col, int matrix[row][col]){
	int i, j;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			matrix[i][j] = 0;
		}
	}
}

void insertMatrixEdge(int matrix[ROW][COL], char v1, char v2){
	int idx1 = (int)v1 - NODE;
	int idx2 = (int)v2 - NODE;
	if(idx1>ROW||idx1<0||idx1>COL||idx2>ROW||idx2<0||idx2>COL){
		printf("OUT OF BOUNDS.\n");
	}
	else{
		matrix[idx1][idx2] = 1;
		matrix[idx2][idx1] = 1;
	}
	
}

void displayMatrix(int row, int col, int matrix[row][col]){
	int i, j, d;
	int v1 = NODE;
	int v2 = NODE;
	printf("DISPLAYING THE ADJACENCY MATRIX: \n   ");
	for(d=0; d<col; d++){
		printf(" %c ", v2);
		v2++;
	}
	printf("\n");
	for(i=0; i<row; i++){
		printf(" %c ", v1);
		for(j=0; j<col; j++){
			
			printf(" %d ", matrix[i][j]);
		}
		v1++;
		printf("\n");
	}
}


