#include <stdio.h>

int main(){ 
	int x, tempo;
	
	scanf("%d", &x);
	
	tempo = 150 / 60 * x;
	
	printf("%d minutos\n",tempo);
	
	return 0;  
}