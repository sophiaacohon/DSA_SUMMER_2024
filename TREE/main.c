#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TREE.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodePtr root = NULL;
	
	Product pp [] = {{"Mango", 25.00, 50, {01, 07, 2024}},
					 {"Banana", 30.00, 25, {31, 07, 2024}},
					 {"Pineapple", 70.00, 50, {31, 07, 2024}},
					 {"Watermelon", 100.00, 50, {31, 07, 2024}},
					 {"Sardines", 50.00, 50, {31, 07, 2024}},
					 {"Broccoli", 40.00, 50, {31, 07, 2024}},
					 {"Cantaloupe", 80.00, 50, {31, 07, 2024}},
					 {"Rice", 20.00, 50, {31, 07, 2024}},
					 {"Peach", 35.00, 50, {31, 07, 2024}},
					 {"Strawberry", 150.00, 100, {31, 07, 2024}},
					 //{"Strawberry", 150.00, 100, {31, 07, 2024}}
	
	};
	
	int count = sizeof(pp) / sizeof(pp[0]);
	int i;
	for(i=0; i<count; i++){
		addNode(&root, pp[i]);
	}
	printf("Something");
	inorder(root);
	
	
	printf("\n\n delete\n");
	deleteNode(&root, pp[0]);
	inorder(root);
	return 0;
}

