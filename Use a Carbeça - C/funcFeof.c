#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE *arquivo = fopen("dados.txt", "r");
	if(arquivo == NULL){
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
	}
	
	char c[30];
	while(!feof(arquivo)){
		fgets(c, 30, arquivo);
		printf("%s", c);
	}
	
	printf("\nFim do arquivo\n\n");
	fclose(arquivo);
	
	system("pause");
	
	return 0;
}