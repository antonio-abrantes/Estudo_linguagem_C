#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int contador(char nome[]){
	int i = 0;
	
	while(nome[i] != '\0'){
		i++;
	}	
	return i;
}

int main(){
	
	char nome[20];
	int i;
	
	scanf("%s",&nome);
	i = contador(nome);
	
	printf("Voce digitou %i letras\n",i);
	printf("O Nome digitado foi %s",&nome);
	
	getch();
	return 0;

}
