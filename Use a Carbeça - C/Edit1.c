#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	
	char word[10];
	char word2[10];
	int i = 0;
	printf("Cod |   Dados gravados.: \n");
	while(scanf("%9s %9s \n", word, word2) == 2){
		printf("%i.: | %9s %9s\n", (i+1),word, word2);
		if (i == 4){
			break;
		}
		i++;
	}
	
/*	
	while (scanf("%9s", word) == 1){
		fprintf(stdout, "%s\n", word);
		if(word[3] == 'r'){
			break;
		}	
	}  */
	return 0;
}
