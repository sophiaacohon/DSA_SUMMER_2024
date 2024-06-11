#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	char name[MAX];
	int idNum;
	int age;
} info;

typedef struct node{
	info data;
	struct node *next;
} Node, *NodePtr;

void insert_front(NodePtr *head){
	NodePtr temp = malloc(sizeof(Node));
	printf("Enter ID Number: ");
	scanf("%d", &temp->data.idNum);
	printf("Enter name: ");
	scanf("%s", temp->data.name);
	printf("Enter age: ");
	scanf("%d", &temp->data.age);
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
	}
	else{
		temp->next = *head;
		*head = temp;
	}
}

void insert_rear(NodePtr *head){
	NodePtr temp = malloc(sizeof(Node));
	printf("Enter ID Number: ");
	scanf("%d", &temp->data.idNum);
	printf("Enter name: ");
	scanf("%s", temp->data.name);
	printf("Enter age: ");
	scanf("%d", &temp->data.age);
	temp->next = NULL;
	/* pointer to pointer to node mothod (does not work)
	NodePtr *headR = *head;
	while(*headR != NULL){
		*headR = &(*headR)->next;
	}
	*headR = temp;
	*/
	//look ahead method
	if(*head == NULL){
		*head = temp;
	}
	else{
		NodePtr trav;
		for(trav = *head; trav->next!=NULL; trav = trav->next){
		}
		trav->next = temp;
	}
}

void insert_pos(NodePtr *head){
	int pos, i;
	NodePtr prev_ptr;
	NodePtr ptr = *head;
	printf("Enter position you want to insert: ");
	scanf("%d", &pos);
	NodePtr temp = malloc(sizeof(Node));
	printf("Enter ID Number: ");
	scanf("%d", &temp->data.idNum);
	printf("Enter name: ");
	scanf("%s", temp->data.name);
	printf("Enter age: ");
	scanf("%d", &temp->data.age);
	temp->next = NULL;
	for(i=0; i<pos; i++){
		prev_ptr = ptr;
		ptr = ptr->next;
	}
	temp->next = ptr;
	prev_ptr->next = temp;
}

void display(NodePtr head){
	NodePtr trav;
	int counter = 0;
	for(trav = head; trav!=NULL; trav = trav->next){
		printf("No. %d\n", counter);
		printf("ID Number: %d\n", trav->data.idNum);
		printf("Name: %s\n", trav->data.name);
		printf("Age: %d\n\n", trav->data.age);
		counter++;
	}
}

void main(){
	int option;
	NodePtr head = NULL;
	do{
		printf("1. Insert at Front\n");
		printf("2. Insert at End\n");
		printf("3. Insert at Position\n");
		printf("4. Display Records\n");
		printf("Enter option number: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nINSERT AT BEGINNING OF LINKED LIST\n");
				insert_front(&head);
				break;
			case 2: 
				printf("\nINSERT AT END OF LINKED LIST\n");
				insert_rear(&head);
				break;
			case 3: 
				printf("\nINSERT AT POSITION IN LINKED LIST\n");
				insert_pos(&head);
				break;
			case 4:
				printf("\nDISPLAY LINKED LIST\n");
				display(head);
				break;
		}
	}while(option != 0);
	
	
}
