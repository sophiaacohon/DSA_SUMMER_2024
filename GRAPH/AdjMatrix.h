#ifndef AdjMatrix.h
#define AdjMatrix.h

#define ROW 5
#define COL 5
/*
create a matrix, accepts an array 
add the connections
display the matrix

i want to use an array because why not
*/

void createMatrix(int row, int col, int matrix[row][col]);
void insertMatrixEdge(int matrix[ROW][COL], int v1, int v2);
void displayMatrix(int row, int col, int matrix[row][col]);

#endif
