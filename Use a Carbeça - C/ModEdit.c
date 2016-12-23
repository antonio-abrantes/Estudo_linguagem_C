#include <stdio.h>
#include <string.h>

int main(){
	
	char teste[10] = "Antonio";	
	
	strncat(teste, teste, 2);
	
	printf("%s", teste);
/*	FILE *arquivo;
	arquivo = fopen("registro.txt", "r");
	
	char conteudo[100];
	
	while(fgets(conteudo, 100, arquivo) != NULL){
		printf("%s",conteudo);
	}
	fclose(arquivo);
	
	*/
	
	/*char nomeArquivo[50];
	
	printf("Digite o nome do arquivo.: ");
	scanf("%s", nomeArquivo);

		strcat(nomeArquivo, ".txt");
	
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "w");
	
	fprintf(arquivo,"Teste");
	
	fclose(arquivo); */
	
	
	return 0;
}
