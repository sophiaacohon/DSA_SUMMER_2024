#ifndef OPENHASH_H
#define OPENHASH_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct pokemon{
	char name[MAX_NAME];
	struct pokemon* next;
} pokemon;

unsigned int hash(char *name);
void init_hash_table();
bool insert(pokemon *p);
void print_table();
pokemon *search(char *name);
pokemon *delete_item(char *name);



#endif
