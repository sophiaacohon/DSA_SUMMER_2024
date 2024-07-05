#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.h"

//NodePtr createNode(NodePtr* node); //to create the products;
void addNode(NodePtr* node, Product prod){

	NodePtr newNode = calloc(1, sizeof(NodeType));
	NodePtr *trav;
	for(trav = node; *trav!=NULL && strcmp((*trav)->item.prodName, prod.prodName) != 0; ){
		int cmp = strcmp((*trav)->item.prodName, prod.prodName);
		trav = (cmp < 0) ? &(*trav)->left : &(*trav)->right;
		
	}
	if(*trav == NULL){
		*trav = newNode;
		newNode->item = prod;
		newNode->left = newNode->right = NULL;
	}else{
		printf("Duplicate data");
	}
}

void deleteNode(NodePtr *tr , Product prod){
    
    NodePtr *trav;
    NodePtr temp;
    
    for(trav = tr; *trav!=NULL && strcmp((*trav)->item.prodName, prod.prodName) != 0; ){
	//	int cmp = strcmp((*trav)->item.prodName, prod.prodName);
		trav = (strcmp((*trav)->item.prodName, prod.prodName) < 0) ? &(*trav)->left : &(*trav)->right;
	}
    if(*trav != NULL ){
        temp = *trav;
        if((*trav)->left == NULL){
            *trav = temp->right;
        }
        else if((*trav)->right == NULL){
            *trav = temp->left;
        }
        else{
            printf("NA WAGTANG");
            for(temp = (*trav)->right ; temp->left != NULL ; temp = temp->left){}
            (*trav)->item = temp->item;   
            (*trav)->right = temp->right;
            
        }
        free(temp);
        
    }
    
}


void BFS(NodePtr* node);
void inorder(NodePtr node){
	//inorder(node->left);
	//a print statement
	if (node != NULL) {
        inorder(node->left);            
        printf("\n%s\t\t", node->item.prodName);  
        printf("%.2f\t\t    ", node->item.prodPrice);     
        printf("%d\t\t", node->item.prodQty);       
        printf("\t%d-%d-%d\t", node->item.expDate.day, node->item.expDate.month, node->item.expDate.year); 
        inorder(node->right);          
    }
	//inorder(node->right);
}

void preorder(NodePtr node){
	//a print statement
	preorder(node->left);
	preorder(node->right);
}

void postorder(NodePtr node){
	postorder(node->left);
	postorder(node->right);
	//a print statement
}

