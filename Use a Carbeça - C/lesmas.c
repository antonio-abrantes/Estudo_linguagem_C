#include <stdio.h>

int main()
{	
	int lesmas;
	int i, ciclos, maior;	
	//fflush(stdin);
	
	while(scanf("%d", &ciclos))
	{		
		maior = 0;
		for(i = 0; i < ciclos; i++){
			scanf("%d", &lesmas);
			if(lesmas > maior){
				maior = lesmas;
			} 
		}
		
		//printf("%d\n", maior);
		
		if(maior >= 20){
			printf("3\n");
		}else {
			if(maior >= 10){
				printf("2\n");	
			}
			else{
				printf("1\n");
			}	
		}		
	}
				
	return 0;
}
