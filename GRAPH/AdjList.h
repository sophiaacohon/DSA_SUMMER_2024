#ifndef AdjList_h
#define AdjList_h

#define ROW 5
#define NODE 65

/*
initialize a list
add the connections
display the matrix

i want to use an array of arrays because why not
*/

char** initList(int row);
void insertList(char v1, char v2, char** list);
void displayList(int row, char** list);

#endif
