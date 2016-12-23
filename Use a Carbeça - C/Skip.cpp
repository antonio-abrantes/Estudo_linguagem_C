#include <stdio.h>

void skip(char *msg){
	puts(msg + 6);
}


int main(){
	
	//char *msg_amy = "Don't call me";
	int nums[] = {1,2, 3};
	char teste[3];
	
	//skip(msg_amy);
	printf("\n");
	printf("indice[0] = %i\n",sizeof(nums));
	printf("indice[1] = %i\n",nums + 1);
	printf("indice[2] = %i\n",2[nums]);
	
	//scanf("%s",teste);
	fgets(teste, sizeof(teste), stdin);
	
	printf("Resultado : %s",teste);
	
	//printf("Ponteiro recebe %i",*(contestants + 2));
	
}
