#include "CloseHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (pokemon*)(0xffffffffffffffffULL)

pokemon *hash_table[TABLE_SIZE];

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

bool insert(pokemon *p){
    printf("Inserting %s...\n", p->name);
    if(p == NULL){
        return false;
    }
    int i;
    int index = hash(p->name);
    for(i=0; i<TABLE_SIZE; i++){
        int trial = (i + index) % TABLE_SIZE;
        if(hash_table[trial] == NULL || hash_table[trial] == DELETED_NODE){
            hash_table[trial] = p;
            return true;
        }
    }
    return false;
}

void print_table(){
    int i; 
    printf("Hash Table \n");
    for(i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else if(hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

pokemon *search(char *name){
    printf("Searching for %s...\n", name);
    int index = hash(name);
    int i; 
    for(i=0; i<TABLE_SIZE; i++){
        int trial = (i + index) % TABLE_SIZE;
        if(hash_table[trial] == NULL){
            return NULL;
        }
        if(hash_table[trial] == DELETED_NODE) continue;
        if (strncmp(hash_table[trial]->name, name, MAX_NAME) == 0) {
            return hash_table[trial];
        }
    }
    return NULL;
}

pokemon *delete_item(char *name){
    printf("Deleting %s...\n", name);
    int index = hash(name);
    int i; 
    for(i=0; i<TABLE_SIZE; i++){
        int trial = (i + index) % TABLE_SIZE;
        if(hash_table[trial] == NULL){
            return NULL;
        }
        if(hash_table[trial] == DELETED_NODE) continue;
        if(strncmp(hash_table[trial]->name, name, MAX_NAME)==0){
            pokemon *temp = hash_table[trial];
            hash_table[trial] = NULL;
            return temp;
        }
    }
    return NULL;
}

