#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "OpenHash.h"

#define MAX_NAME 256
#define TABLE_SIZE 10

pokemon * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
	int length = strnlen(name, MAX_NAME);
	int i;
	unsigned int value = 0;
	for (i=0; i<length; i++){
		value += name[i];
		value = (value*name[i])%TABLE_SIZE;
	} 
	value %= TABLE_SIZE;
	return value;
}

void init_hash_table(){
	int i;
	for(i=0; i<TABLE_SIZE; i++){
		hash_table[i] = NULL;
	}
}

void print_table(){
	int i; 
	printf("Hash Table \n");
	for(i=0; i<TABLE_SIZE; i++){
		if(hash_table[i] == NULL){
			printf("\t%i\t---\n", i);
		}
		else{
			printf("\t%i\t", i);
			pokemon *temp = hash_table[i];
			while(temp != NULL){
				printf("%s -> ", temp->name);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

bool insert(pokemon *p){
	printf("Inserting %s...\n", p->name);
	if(p == NULL){
		return false;
	}
	int index = hash(p->name);
	pokemon *temp = hash_table[index];
    if (temp == NULL) {
        hash_table[index] = p;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
    return true;
}

pokemon *search(char *name){
	printf("Searching for %s...\n", name);
	int index = hash(name);
	pokemon *temp = hash_table[index];
	while(temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0){
		temp = temp->next;
	}
	return temp;
}

pokemon *delete_item(char *name){
	printf("Deleting %s...\n", name);
	int index = hash(name);
	pokemon *temp = hash_table[index];
	pokemon *prev = NULL;
	while(temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		return NULL;
	}
	if(prev == NULL){
		hash_table[index] = temp->next;
	}
	else{
		prev->next = temp->next;
	}
	return temp;
}
