#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct{
	int day;
	int month;
	int year;
} Date;

typedef struct{
	char prodName[20]; //use this to rearrange BST with strcmp()
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node{
	Product item;
	struct node *left;
	struct node *right;
} NodeType, *NodePtr;

typedef struct Qnode{
	NodePtr data;
	struct Qnode* next;
} QNode, *QNodePtr;

typedef struct {
	QNodePtr front;
	QNodePtr rear;
} Queue;

//NodePtr createNode(NodePtr* node); //to create the products;
void addNode(NodePtr* node, Product prod);
void deleteNode(NodePtr *tr, Product prod);

void initQueue(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue* q, NodePtr node);
NodePtr dequeue(Queue* q);
NodePtr front(Queue* q);
void BFS(NodePtr root);

void inorder(NodePtr node);
void preorder(NodePtr node);
void postorder(NodePtr node);

/*
add
delete
traversal
-BFS: need a QUEUE
-DFS
 -inorder
 -preorder
 -postorder
*/

///avl on monday


#endif
