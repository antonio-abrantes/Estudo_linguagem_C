#include <stdio.h>
#include <stdlib.h>

/* Conversor ASCII */

int main(){
	int num;
	char letra[2];
	
	printf("Digite um caracter.: ");
	scanf("%s",letra);
	
	num = letra[0];
	
	printf("Em ASCII.: %i\n",num);
	printf("Endereco.: %i",&num);
	
	return 0;
}
