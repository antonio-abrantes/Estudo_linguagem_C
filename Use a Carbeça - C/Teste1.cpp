#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	
	char letra1[2], letra2[2], palavra[3];
	int num1, num2, soma;
	
	printf("Digite o primeiro numero.: ");
	scanf ("%s",letra1);
	printf("Digite o segundo numero.: ");
	scanf ("%s",letra2);
	
	num1 = atoi(letra1);
	num2 = atoi(letra2);
	
	soma = num1 + num2;
	
	palavra[0] = letra1[0];
	palavra[1] = letra2[0];
	
	printf("A soma.: %i\n",soma);
	printf("Concatenados.: %s",palavra);
	
	getchar();
	
	return 0;
	
}
