#include <stdio.h>

int main()
{
	int N, i;
	
	scanf("%d", &N);
	
	for(i = N; i > 0; i--){
		if(i == 1){
			printf("Ho!\n");
			break;
		}
		printf("Ho ");
	}
	
	return 0;
}