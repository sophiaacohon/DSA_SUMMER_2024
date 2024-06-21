/*
Create a Program to find the union and intersection of two sets.

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
#include <windows.h>
#include <conio.h>
#include "SET_UID.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int n;
	SET A, B;
	initSet(A);
	initSet(B);
	do{
		system("cls");
		printf("MENU\n");
		printf("1. Add an Element to Set A\n");
		printf("2. Add an Element to Set B\n");
		printf("3. Delete an Element from Set A\n");
		printf("4. Delete an Element from Set B\n");
		printf("5. Display Set A \n");
		printf("6. Display Set B\n");
		printf("7. Union of Set A and Set B\n");
		printf("8. Intersection of Set A and Set B\n");
		printf("9. Difference of A and B \n");
		printf("10. Difference of B and A\n");
		printf("0. EXIT\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nAdd an Element to Set A\n");
				printf("Enter a number to add to Set A: ");
				scanf("%d", &n);
				insertElement(&A, n);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 2:
				printf("\nAdd an Element to Set B\n");
				printf("Enter a number to add to Set B: ");
				scanf("%d", &n);
				insertElement(&B, n);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 3:
				printf("\nDelete an Element from Set A\n");
				printf("Enter a number to delete from Set A: ");
				scanf("%d", &n);
				deleteElement(&A, n);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 4:
				printf("\nDelete an Element from Set B\n");
				printf("Enter a number to delete from Set B: ");
				scanf("%d", &n);
				deleteElement(&B, n);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 5:
				printf("\nDisplay Elements of Set A\n");
				printf("SET A: \n");
				displaySet(A);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 6:
				printf("\nDisplay Elements of Set B\n");
				printf("SET B: \n");
				displaySet(B);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 7:
				printf("\nUnion of Set A and Set B\n");
				unionSet(&A, &B);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 8:
				printf("\nIntersection of Set A and Set B\n");
				intersectionSet(&A, &B);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 9:
				printf("\nDifference of Set A and Set B\n");
				printf("\nA - B\n");
				differenceSet(&A, &B);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 10:
				printf("\nDifference of Set B and Set A\n");
				printf("\nB - A\n");
				differenceSet(&B, &A);
				printf("\nPress Enter to continue\n");
				getch();
				break;
		}
	}while(choice!=0);
	printf("Program Terminated.\n");
	return 0;
}
