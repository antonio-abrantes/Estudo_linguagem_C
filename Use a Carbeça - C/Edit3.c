#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cofCod(int cod){  //Verificar se o codigo jé é cadastrado	
	char conf[100];
	char codf[5];
	int cont = -2;
	
	sprintf(codf, "%d", cod);
	
	FILE *arquivo;
	arquivo = fopen("registro.txt", "r");
			
	 while(fgets(conf, 100, arquivo) != NULL){	
		if(strstr(conf, codf )){
			cod = cont + 1; //+ rand() % 50;
			return cont;
		}
		cont++;		
	} 
	return cont++;
	
	fclose(arquivo); 	
}

void buscar(){  //Buscar registro por nome
	char busca[100];
	char conteudo[100];
	char control[100] ="\0";
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
	getch();
}

void abrir(){ //Função para ler e exibir o conteudo de registro.txt
	FILE *arquivo;
	arquivo = fopen("registro.txt", "r");
	
	char conteudo[100];
	
	while(fgets(conteudo, 100, arquivo) != NULL){
		printf("%s",conteudo);
	}
	fclose(arquivo);
	printf("\n+---------------------------------------------------------------+\n");
	printf("\n-> Pressiona algo para cotinuar");
	getch();
}

void grava(char *texto){ //Acrscentar dados ao arquivo registro.txt
	int cod;
	
	cod = cofCod(cod);
	FILE *arquivo;
	arquivo = fopen("registro.txt", "a" );
	
	printf("+---------------------------------------------------------------+\n");
	printf(" # Codigo de registro.: %d", cofCod(cod));

	fprintf(arquivo, " Cod: %i      %s", cofCod(cod), texto);	
	
	
	fclose(arquivo);
	printf("\n # Cliente cadastrado com sucesso...");
	getch();
}

void ler(char *textoC){	 //Ler o texto digitado
	printf("-> NOME.: ");
	fgets(textoC,100,stdin);
	
}

void opc(char *opcao){  //Escolha das opcções do programa
	printf(" # Digite a opcao.: ");
	scanf("%s",opcao);
	getchar();
	printf("\n");
}

char criarArquivo(){ //Criar um novo arqivo com nome especifico
	char nomeArquivo[50];
	
	printf("-> Digite o nome do arquivo.: ");
	scanf("%s", nomeArquivo);

		strcat(nomeArquivo, ".txt");
	
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "w");
	
	fprintf(arquivo,"Teste");
	
	fclose(arquivo);
}

int main(){ //Funcão principal do programa
	char texto[100];
	char opcao[3];
	
	while(opcao[0] != '5'){
		system("cls");
		printf("################################\n");
		printf("||          OPCOES:           ||\n");
		printf("|| 1 - Cadastrar nome         ||\n");
		printf("|| 2 - Criar novo arquivo     ||\n");
		printf("|| 3 - Abrir registro         ||\n");
		printf("|| 4 - Buscar por nome        ||\n");
		printf("|| 5 - Para sair              ||\n");
		printf("################################\n");
		opc(opcao);
		
		switch(opcao[0]){
			case '1':	
				ler(texto);		
				grava(texto); break;
			case '2':
				criarArquivo(); break;	
			case '3':
				abrir(); break;
			case '4':
				buscar(); break;		
			case '5':
				continue;					
		}	
		printf("\n");
	}				
  return 0;
}

