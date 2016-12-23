#include <stdio.h>
#include <string.h>

int main(){
	char texto[100];
	char opcao[3];
	
	while(opcao[0] != 'S'){
		printf("Digite a opcao: ");
		scanf ("%s",opcao);
		
		switch(opcao[0]){
			case 'A':
				printf("Voce digitou A\n");
				printf("Digite a opcao: "); 
				scanf ("%s",opcao); break;
			case 'B':
				printf("Voce digitou B\n"); break;
				printf("Digite a opcao: ");
			case 'C':
				printf("Digite o texto.:\n");
				scanf("%s",texto);
				//fgets(texto, 100, stdin); break;
								
			default:
				continue;			
			
		}
		
		
	}
	
}
