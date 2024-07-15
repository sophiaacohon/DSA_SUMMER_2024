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
	
	//ADJACENCY MATRIX
	int matrix[ROW][COL];
	initMatrix(ROW, COL, matrix);
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
	printf("\n");
	//*/
	
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
