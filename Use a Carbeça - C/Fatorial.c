#include <stdio.h>

int main(){
	int f, r;
	printf("Digite o numero.: ");
	scanf("%d", &f);
	
		for(r = 1; f > 1; --f){
			r = r * f;
			printf("%d, ",r);
		}
	
	return 0;
}
