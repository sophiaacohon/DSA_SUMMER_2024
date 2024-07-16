#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjMatrix.h"
#include "AdjList.h"

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
	
	//DISPLAY THE GIVEN
	printf("UNDIRECTED GRAPH:\n A: B, C, D\n B: A, C, D, E\n C: A, B, D\n D: A, B, C, E\n E: B, D\n\n");
	
	//ADJACENCY MATRIX
	int matrix[ROW][COL];
	initMatrix(ROW, COL, matrix);
	insertMatrixEdge(matrix, 'A', 'B');
	insertMatrixEdge(matrix, 'A', 'C');
	insertMatrixEdge(matrix, 'A', 'D');
	insertMatrixEdge(matrix, 'B', 'C');
	insertMatrixEdge(matrix, 'B', 'D');
	insertMatrixEdge(matrix, 'B', 'E');
	insertMatrixEdge(matrix, 'C', 'D');
	insertMatrixEdge(matrix, 'D', 'E');
	//insertMatrixEdge(ROW, COL, matrix, 6, 8);
	displayMatrix(ROW, COL, matrix);
	printf("\n");
	
	
	//ADJACENCY LIST
	char **list = initList(ROW);
	insertList('A', 'B', list);
	insertList('A', 'C', list);
	insertList('A', 'D', list);
	
	insertList('B', 'A', list);
	insertList('B', 'C', list);
	insertList('B', 'D', list);
	insertList('B', 'E', list);
	
	insertList('C', 'A', list);
	insertList('C', 'B', list);
	insertList('C', 'D', list);
	
	insertList('D', 'A', list);
	insertList('D', 'B', list);
	insertList('D', 'C', list);
	insertList('D', 'E', list);
	
	insertList('E', 'B', list);
	insertList('E', 'D', list);
	
	displayList(ROW, list);
	
	return 0;
}
