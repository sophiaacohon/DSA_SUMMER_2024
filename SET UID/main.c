/*
Create a Program to find the union and intersection
of two sets.

-functions that accept 2 sets and returns the resulting union and intersection
-functions to add or delete values in the set
-keep the integrity of the 2 initial sets when finding the union and intersection
-Display the unions and intersections

https://youtu.be/RVqdK6WAjUI?si=S-MWAAvpvKb4DYop
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "SET_UID.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET A;
	initSet(A);
	display(A);
	insertMember(A);
	display(A);
	deleteMember(A);
	display(A);
	return 0;
}
