#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
UNDIRECTED GRAPH
A: B, C, D
B: A, C, D, E
C: A, B, D
D: A, B, C, E
E: B, D
*/


int main(int argc, char *argv[]) {
	int matrix[ROW][COL];
	createMatrix(ROW, COL, matrix);
	insertMatrixEdge(matrix, 0, 1);
	insertMatrixEdge(matrix, 0, 2);
	insertMatrixEdge(matrix, 0, 3);
	insertMatrixEdge(matrix, 1, 2);
	insertMatrixEdge(matrix, 1, 3);
	insertMatrixEdge(matrix, 1, 4);
	insertMatrixEdge(matrix, 2, 3);
	insertMatrixEdge(matrix, 3, 4);
	//insertMatrixEdge(ROW, COL, matrix, 6, 8);
	displayMatrix(ROW, COL, matrix);
	return 0;
}
