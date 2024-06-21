#ifndef SET_UID
#define SET_UID

#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];

void initSet(SET s);

void displaySet(SET s);

void insertElement(SET *s, int n);

void deleteElememt(SET *s, int n);

void unionSet(SET *A, SET *B);

void intersectionSet(SET *A, SET *B);

void differenceSet(SET *A, SET *B);

#endif
