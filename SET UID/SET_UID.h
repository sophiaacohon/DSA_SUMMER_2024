#ifndef SET_UID
#define SET_UID

#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];

void initSet(SET s);

void display(SET s);

void insertMember(SET s, int n);

void deleteMember(SET s, int n);

void Union(SET A, SET B);

void intersection(SET A, SET B);

void difference(SET A, SET B);

#endif
