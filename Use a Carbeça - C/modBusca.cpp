/*  ================================================
		       MODULO DE BUSCA POR NOME
	================================================  */
	
#include <stdio.h>
#include <string.h>
#include <teste.h>

int main(){
	char busca[100];
	char conteudo[100];
	char control[100] = "\0";
	FILE *arquivo;
	
	arquivo = fopen("registro.txt", "r");
	
	printf("Digite a busca.: ");
	scanf("%s", busca);
	printf("\n+---------+---------------------------------------------------------------+");
	while(fgets(conteudo, 100, arquivo) != NULL){	
		if(strstr(conteudo, busca)){
			printf("\n%s", conteudo);
		strcpy(control, conteudo);
		}
		
	}
	if(control[1] == '\0'){
			printf("\n # Nenhum resultado encontrado...");
		}
	
	printf("\n+---------+---------------------------------------------------------------+");
	printf("\n-> Pressiona algo para cotinuar");	
	fclose(arquivo);
	
	return 0;
}
