#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cofCod(int cod){	
	char conf[100];
	char codf[5];
	int cont = 0;
	
	sprintf(codf, "%d", cod);
	
	FILE *arquivo;
	arquivo = fopen("registro.txt", "r");
		
	 while(fgets(conf, 100, arquivo) != NULL){	
		if(strstr(conf, codf )){
			printf("\n%s", conf);
			return cont;
		}
		cont++;
	} 
	return cont++;
	printf("\n%d",cont);
	fclose(arquivo); 	
}

int main(){
	int cod;
	
	printf("Digite o numero.: ");
	scanf("%d",&cod);
	
	printf("\n O retorno foi.: %d", cofCod(cod));
	
	getch();
	
	return 0;
}
