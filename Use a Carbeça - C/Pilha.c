#include <stdio.h>

#define STACK_SIZE 10

int pilha[STACK_SIZE];
int topo;

void inicializa(){
	topo = -1;
};

void empilha(int elemento){
	if(topo+1 < STACK_SIZE){
		topo++;
		pilha[topo] = elemento;
	} 	
};

int desempilha(){
	int aux = -1;
	
	if(topo > -1){
		aux = pilha[topo];
		topo--;
	}
	
	return aux;   	
};

int main()
{
	
	return 0;
}