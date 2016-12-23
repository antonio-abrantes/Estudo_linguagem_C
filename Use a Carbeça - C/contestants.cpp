#include <stdio.h>
#include <stdlib.h>

int main(){
	int contestants[] = {1,2,3};
	char teste[] ={'x'} ;
	int pont = 24;
	
	int *ponteiro = &pont;
	int *choice = contestants;
	
	pont = atoi(teste);
	
	//scanf("%c",teste);
	
	if((teste[0] >= 'a') && (teste[0] <= 'g')){
		printf("Maior que a e menor que g\n");
	}
	else
		printf("Maior que g\n");
	
	contestants[0] = 2;
	contestants[1] = contestants[2];
	contestants[2] = *choice;
	
	//printf("Contestants number %i\n\n",contestants[2]);
	
//	printf("Ponteiro recebe %i",*(contestants + 2));
	printf("Contestants number %c\n\n",*teste);
	
}
