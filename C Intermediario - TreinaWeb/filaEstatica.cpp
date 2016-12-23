#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int const MAXTAM=1000;
#define MAXTAM 1000

int Frente, Tras;
int Fila[MAXTAM];	

void Fila_Contrutor(){
	Frente = 0;
	Tras= -1;
}

bool Fila_Vazia(){
	if(Frente > Tras)
		return true;
	else
	{
		return false;
	}
}

bool Fila_Cheia(){
	if(Tras == MAXTAM-1){
		return true;
	}else{
		return false;
	}
}

bool Fila_Enfileirar(int valor){
	if(Fila_Cheia()){
		return false;
	}else{
		Tras++;
		Fila[Tras] = valor;
		return true;
	}
}

bool Fila_Desenfileiar(int &valor){
	if(Fila_Vazia()){
		return false;
	}else{
		valor = Fila[Frente];
		Frente++;
		return true;
	}
}

bool Fila_Get(int valor){
	if(Fila_Vazia()){
		return false;
	}else{
		valor = Fila[Frente];
		return true;
	}
}

int Fila_Tamanho(){
	return (Tras - Frente) + 1;
}

int main(int argc, char** argv)
{
	int valor;
	
	Fila_Contrutor();
	
	Fila_Enfileirar(5);
	Fila_Enfileirar(2);
	Fila_Enfileirar(7);
	Fila_Enfileirar(8);
	Fila_Enfileirar(1);
	
	printf("TAMANHO: %d\n", Fila_Tamanho());
	
	while( Fila_Desenfileiar(valor))
	{
		printf("\nValor: %d\n", valor);
	}
	printf("\n");
	/*if( Fila_Desenfileiar(valor) ){
		printf("\n\nValor: %d\n", valor);
	}else{
		printf("\n\nFila Vazia\n");
	}*/
	printf("TAMANHO: %d\n", Fila_Tamanho());
	
	printf("TRAS: %d - FRENTE: %d\n", Tras, Frente);
	
	system("pause");
	return 0;
}






