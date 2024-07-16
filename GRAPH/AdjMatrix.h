#ifndef AdjMatrix_h
#define AdjMatrix_h

#define ROW 5
#define COL 5
/*
initialize a matrix, accepts an array 
add the connections
display the matrix

i want to use an array because why not
*/

void initMatrix(int row, int col, int matrix[row][col]);
void insertMatrixEdge(int matrix[ROW][COL], char v1, char v2);
void displayMatrix(int row, int col, int matrix[row][col]);

#endif
