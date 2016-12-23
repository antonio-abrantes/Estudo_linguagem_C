#include <stdio.h>
#include <string.h>

int main(){
	char data[12];
	
	printf("Digite a data.: ");
	gets(data);
		
	if(strlen(data) != 10){
		printf("Data invalida");
	}
	else{
		char *barra1 = strchr(data, '/');
		
		if((barra1 == NULL) || strlen(barra1) != 8 ){
			printf("\nData invalida, dia ou mes incorreto!");	
		}
		else{
			barra1 = (barra1 + 1); //Unica diferença para o algoritomo do corrigido
			barra1 = strchr(barra1, '/');
				if((barra1 == NULL) || strlen(barra1) != 5 ){
				printf("\nData invalida, mes ou ano incorreto!!");	
				}
				else{
					printf("Data aceita! %s", data);
				}		
			}	
		/*====================================
				Solução com vetor
		  ====================================		
		if(barra[3] != '/'){     
		printf("Data invalida 2! segunda barra");	
		}
		else{
			printf("Data aceita!!");
			//strcat(data, data);
		}*/	
	}	
	getch();
	
	return 0;
}
