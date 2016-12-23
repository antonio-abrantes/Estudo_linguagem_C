#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int numero1;
	int numero2;
}pessoa; 

int main(){
	
	pessoa p1;
	int num;
	
	int *p = (int *)calloc(10, sizeof(p1));
	
	scanf("%d",&num);

	
	printf("\a%d", num % 2);
	
	free(p);
	
	return 0;
}
