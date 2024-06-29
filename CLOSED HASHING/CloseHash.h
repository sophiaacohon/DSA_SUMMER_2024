#ifndef CLOSEHASH_H
#define CLOSEHASH_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (pokemon*)(0xffffffffffffffffULL)

typedef struct {
    char name[MAX_NAME];
} pokemon;

unsigned int hash(char *name);
void init_hash_table();
bool insert(pokemon *p);
void print_table();
pokemon *search(char *name);
pokemon *delete_item(char *name);

#endif
