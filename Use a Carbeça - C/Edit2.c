#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char texto[80];
	char nome[80];
	int len, i;
	
	printf("Digite o Codigo.: ");
	scanf("%s", texto);
//	printf("\nSalvar como? ");
//	scanf("%s",nome);
	
	len = strlen(nome);
	
//		nome[len -1] = '.';
//		nome[len +1] = 't';
//		nome[len +2] = 'x';
//		nome[len +3] = 't';	
	char conteudo[100];
	
	FILE *file;
	
	file = fopen("message.txt", "r");
	//fprintf(file, texto);
	
	while(fgets(conteudo, 100, file) != NULL){
		if(strstr(conteudo, texto)){
			printf("%s",conteudo);
		}
	}
	
	fclose(file);
		
	return 0;
}
