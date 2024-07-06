#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TREE.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodePtr root = NULL;
	
	Product pp [] = {{"Mango", 22.99, 60, {10, 8, 2024}},
				    {"Banana", 28.50, 40, {20, 8, 2024}},
				    {"Pineapple", 72.00, 65, {30, 8, 2024}},
				    {"Watermelon", 102.00, 65, {01, 9, 2024}},
				    {"Sardines", 47.00, 65, {10, 9, 2024}},
				    {"Broccoli", 43.00, 65, {20, 9, 2024}},
				    {"Cantaloupe", 83.00, 65, {31, 7, 2024}},
				    {"Rice", 21.00, 65, {10, 10, 2024}},
				    {"Peach", 37.00, 65, {20, 10, 2024}},
				    {"Strawberry", 147.00, 115, {30, 10, 2024}},
				    {"Apple", 53.00, 215, {10, 11, 2024}}
					 //{"Strawberry", 150.00, 100, {31, 07, 2024}}
	
	};
	
	int count = sizeof(pp) / sizeof(pp[0]);
	int i;
	for(i=0; i<count; i++){
		addNode(&root, pp[i]);
	}
	
	printf("ORIGINAL LISTS\n\n");
	printf("DEPTH FIRST SEARCH\n");
	printf("\nINORDER TRAVERSAL:");
	inorder(root);
	
	printf("\n\nPREORDER TRAVERSAL:");
	preorder(root);
	
	printf("\n\nPOSTORDER TRAVERSAL:");
	postorder(root);
	
	//printf("\n\nBREADTH FIRST SEARCH");
	//BFS(root);
	
	printf("\n\nDELETE THE ROOT: MANGO");
	deleteNode(&root, pp[0]);
	
	printf("\n\nAfter Deletion\n");
	printf("\nDEPTH FIRST SEARCH\n");
	printf("INORDER TRAVERSAL:");
	inorder(root);
	printf("\n\nPREORDER TRAVERSAL:");
	preorder(root);
	printf("\n\nPOSTORDER TRAVERSAL:");
	postorder(root);
	
	printf("\n\nBREADTH FIRST SEARCH");
	BFS(root);
	return 0;
}

