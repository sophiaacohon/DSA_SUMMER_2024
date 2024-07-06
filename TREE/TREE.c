#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.h"

//NodePtr createNode(NodePtr* node); //to create the products;
void addNode(NodePtr* node, Product prod){

	NodePtr newNode = calloc(1, sizeof(NodeType));
	NodePtr *trav;
	for(trav = node; *trav!=NULL && strcmp(prod.prodName, (*trav)->item.prodName) != 0; ){
		//int cmp = strcmp((*trav)->item.prodName, prod.prodName);
		trav = (strcmp(prod.prodName, (*trav)->item.prodName) < 0) ? &(*trav)->left : &(*trav)->right;
		
	}
	if(*trav == NULL){
		*trav = newNode;
		newNode->item = prod;
		newNode->left = newNode->right = NULL;
	}else{
		printf("Duplicate data");
		free(newNode);
	}
}

void deleteNode(NodePtr *tr, Product prod) {
    if (*tr == NULL) {
        printf("Tree is empty\n");
        return;
    }

    NodePtr current = *tr;
    NodePtr parent = NULL;
    while (current != NULL && strcmp(current->item.prodName, prod.prodName) != 0) {
        parent = current;
        if (strcmp(prod.prodName, current->item.prodName) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Product %s not found\n", prod.prodName);
        return;
    }

    if (current->left == NULL) {
        if (parent == NULL) {
            *tr = current->right;
        } else if (current == parent->left) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            *tr = current->left;
        } else if (current == parent->left) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    } else {
        NodePtr successor = current->right;
        parent = NULL;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        current->item = successor->item;

        if (parent != NULL) {
            parent->left = successor->right;
        } else {
            current->right = successor->right;
        }

        free(successor);
    }
}

void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;	
}

bool isEmpty(Queue *q){
	return (q->front == NULL && q->rear == NULL)? true:false;
}

void enqueue(Queue* q, NodePtr node){
	QNodePtr newNode = malloc(sizeof(QNode));
	if(newNode == NULL){
		printf("Memory not allocated");
	}
	newNode->data = node;
	newNode->next = NULL;
	if(isEmpty(q)){
		q->front = newNode;
		q->rear = newNode;
	}
	else{
		q->rear->next = newNode;
		q->rear = newNode;
	}
	//printf("Enqueued: %s\n", node->item.prodName);
}

NodePtr dequeue(Queue* q){
	
	if(isEmpty(q)){
		return NULL;
	}
	QNodePtr temp = q->front;
	NodePtr nodeData = temp->data;
	q->front = q->front->next;
	if(q->front == NULL){
		q->rear == NULL;
	}
	free(temp);
	//printf("Dequeued: %s\n", nodeData->item.prodName);
	return nodeData;
}

NodePtr front(Queue* q){
	if(isEmpty(q)){
		return NULL;
	}
	else{
		return q->front->data;
	}
}

void BFS(NodePtr root){
	//initialize queue
	if(root == NULL){
		printf("Tree is Empty.\n");
		return;
	}
	
	Queue *BFSList = malloc(sizeof(Queue));
	if (BFSList == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
	initQueue(BFSList);
	enqueue(BFSList, root);
	
	while(!isEmpty(BFSList)){
		NodePtr currentNode = front(BFSList);
		//printf("Processing node: %s\n", currentNode->item.prodName);
		printf("\n%s\t\t%.2f\t\t%d\t\t%d-%d-%d\t", currentNode->item.prodName, currentNode->item.prodPrice,
               currentNode->item.prodQty, currentNode->item.expDate.day, currentNode->item.expDate.month,
               currentNode->item.expDate.year);
		//printf("\n");
			
		if(currentNode->left != NULL){
			enqueue(BFSList, currentNode->left);
		}
		if(currentNode->right != NULL){
			enqueue(BFSList, currentNode->right);
		}
		dequeue(BFSList);
	}
	
	free(BFSList);
}

void inorder(NodePtr node){
	//inorder(node->left);
	//a print statement
	
	if (node != NULL) {
        inorder(node->left);            
        printf("\n%s\t\t%.2f\t\t%d\t\t%d-%d-%d\t", node->item.prodName, node->item.prodPrice, node->item.prodQty,
               node->item.expDate.day, node->item.expDate.month, node->item.expDate.year); 
        inorder(node->right);          
    }
	//inorder(node->right);
}

void preorder(NodePtr node){
	//a print statement
	//preorder(node->left);
	//preorder(node->right);
	if (node != NULL) {          
        printf("\n%s\t\t%.2f\t\t%d\t\t%d-%d-%d\t", node->item.prodName, node->item.prodPrice, node->item.prodQty,
               node->item.expDate.day, node->item.expDate.month, node->item.expDate.year); 
        preorder(node->left);
        preorder(node->right);          
    }
}

void postorder(NodePtr node){
	//postorder(node->left);
	//postorder(node->right);
	//a print statement
	if (node != NULL) {          
        postorder(node->left);
        postorder(node->right);  
		printf("\n%s\t\t%.2f\t\t%d\t\t%d-%d-%d\t", node->item.prodName, node->item.prodPrice, node->item.prodQty,
               node->item.expDate.day, node->item.expDate.month, node->item.expDate.year);     
    }
}

