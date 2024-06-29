#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "OpenHash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	init_hash_table();
	print_table();
	printf("\n");
	pokemon Charmander = {.name="Charmander"};
	pokemon Jirachi = {.name="Jirachi"};
	pokemon Meloetta = {.name="Meloetta"};
	pokemon Rowlet = {.name="Rowlet"};
	pokemon Vulpix = {.name="Vulpix"};
	pokemon Pikachu = {.name="Pikachu"};
	pokemon Torchic = {.name="Torchic"};
	pokemon Piplup = {.name="Piplup"};
	pokemon Mudkip = {.name="Mudkip"};
	
	
	
	insert(&Charmander);
	insert(&Jirachi);
	insert(&Meloetta);
	insert(&Rowlet);
	insert(&Vulpix);
	insert(&Pikachu);
	insert(&Torchic);
	insert(&Piplup);
	insert(&Mudkip);
	
	print_table();
	
	pokemon *temp = search("Jirachi");
	if(temp == NULL){
		printf("Not found.\n");
	}
	else{
		printf("Found %s! \n", temp->name);
	}
	
	temp = search("Decidueye");
	if(temp == NULL){
		printf("Not found.\n");
	}
	else{
		printf("Found %s! \n", temp->name);
	}
	
	delete_item("Jirachi");
	temp = search("Jirachi");
	if(temp == NULL){
		printf("Not found.\n");
	}
	else{
		printf("Found %s! \n", temp->name);
	}
	
	print_table();
	return 0;
}
