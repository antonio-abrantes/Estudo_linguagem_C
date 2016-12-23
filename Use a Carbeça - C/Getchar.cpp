#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	
	char linha[100];
	char caractere;
	int i;
	char teste = 'A';
	
	printf("Digite o nome.: ");
	do{
		caractere = getchar();
		linha[i] = caractere;
		i++;
		if(caractere == '\n'){
			linha[i] = '\0';
		}
		
	}while(caractere != '\n');
	
	printf("O Nome digitado foi.: %s\n",linha);
	printf("A em condigo ASCII.: %i",teste);
	
	getch();
	return 0;

}
