#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(){
	system("title - Jogo da Velha");
		
	char name[30];
	printf("Digite o nome.: ");
	fgets(name, 30, stdin);
	printf("Hello %s \n", name);
	
	return 0;
}
