#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "msg.h"

int main(){
	
	int num, soma = 0;
	char msg[80];
	
	printf("Digite a mensagem a ser criptografada.: ");
	fgets(msg, 80, stdin);
	
	while(num != 9999){
		printf("Digete o numero.: ");
		scanf("%d", &num);
		if(num != 9999){
			soma = soma + num;
			tes(soma);
		}
		
	}
	
	printf("A soma dos numeros digitados.: %d", soma);
	
	encrypt(msg);
	
	printf("\nA menssagem eh.: %s", msg);
	
	return 0;
}
