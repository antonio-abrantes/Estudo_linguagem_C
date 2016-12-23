#include <stdio.h>
#include <stdlib.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
typedef struct{
	char *nome;
	enum response_type type;
} response;

void dump(response r){
	printf("Dear %s\n", r.nome);
	puts("Funcao DUMP");
}

void second_chance(response r){
	printf("Dear %s\n", r.nome);
	puts("Funcao SEGUNCA CHANCE");
}

void marriage(response r){
	printf("Dear %s\n", r.nome);
	puts("Funcao CASAMENTO");
}  
void  (*replies[]) (response) = {dump, second_chance, marriage};

int main(){
	response r[]= {
		{"MIKE", DUMP}, {"Luis", SECOND_CHANCE},
		{"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
	};
	
	int i;
	for(i = 0; i < 4; i++){
		(*replies[r[i].type]) (r[i]);
	/*	switch(r[i].type){
			case DUMP:
				dump(r[i]);
				break;
			case SECOND_CHANCE:
				second_chance(r[i]);
				break;
			default:
				marriage(r[i]);						
		} */	
	}	
	
	return 0;
}
