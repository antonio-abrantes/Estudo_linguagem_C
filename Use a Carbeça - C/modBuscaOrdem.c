#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cofCod(int cod){	
	char conf[100];
	char codf[5];
	
	sprintf(codf, "%d", cod);
	
	FILE *arquivo;
	arquivo = fopen("registro.txt", "r");
		
	 while(fgets(conf, 100, arquivo) != NULL){	
		if(strstr(conf, codf )){
			printf("\n%s", conf);
			return cod + 1;
		}
		
	} 
	return cod;
	
	fclose(arquivo); 	
}

int main(){
	
	char login[50];
	printf("Digite seu login: ");
	gets(login);
	getch();
	
	if (strcmp (login, "Asdrubal") < 0){
		strcat(login, " Voce esta logado");
		puts(login);
	}
	else
		puts("Sem autorização para entrar");
	
	/*int cod;
	
	printf("Digite o numero.: ");
	scanf("%d",&cod);
	
	printf("\n O retorno foi.: %d", cofCod(cod));
	
	getch();*/
	
	return 0;
}
