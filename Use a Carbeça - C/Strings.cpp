#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
  char texto[100];
  char inverso[100];
  
  int i, f;
  	
	printf("Digite um texto.: ");	
	gets(texto);
	
	printf("O tamanho eh: %i\n", strlen(texto));
	
	f = 0;
	for(i = (strlen(texto) - 1); i >= 0; i--  ){
		//printf("%c",texto[i]);
		inverso[f] =  texto[i];
		f++;
		if(f == strlen(texto)){
			inverso[f] = '\0';
		}
	}
		
	printf("\nInverso = %s",inverso); 
	
	if (strcmp(texto, inverso) == 0){
		printf("\nEh palindromo");
	}
	else{
		printf("\nNao eh palindromo");
	}
  return 0;
}
