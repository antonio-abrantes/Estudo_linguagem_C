#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct island{
	char *nome;
	char *opens;
	char *closes;
	struct island *next;
}island;

island* create(char *nome){
	island *i = malloc(sizeof(island));
	i->nome = strdup(nome);
	i->opens = "9:00";
	i->closes = "17:00";
	i->next = NULL;
	
	return i;
}

void display(island *start){
	island *i = start;
	for (;i != NULL; i = i->next){
		printf("Destino %s, Ida: %s, Volta: %s, Proxima: %s\n", 
					i->nome, i->opens, i->closes);
	}
	
}

void release(island *start){
	island *i = start;
	island *next = NULL;
	for(; i = NULL; i = next){
		next = i->next;
		free(i->next);
		free(i);
	}
}

int main(){
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char nome[80];
	
	for(;fgets(nome, 80, stdin) != NULL; i = next){
		next = create(nome);
		if(start == NULL){
			start = next;
		}
		if(i != NULL){
			i->next = next;
		}
	}
	display(start);
	release(start);

	/*island amity =  {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island shutter = {"Shutter", "09:00", "17:00", NULL};
	island skull = {"Skull", "09:00", "17:00", NULL};
	
	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &skull;
	skull.next = &shutter;
	
	island *p_island1 = create(nome);
	p_island0->next = p_island1;
	
	display(p_island0);*/
	
		
	return 0;
}
