#include <stdio.h>

int main()
{
	int N, segundos = 0, minutos = 0, horas = 0;
	
	scanf("%d", &N);
	
	segundos = (N % 3600) % 60;
	minutos = (N % 3600)/60;
	
	if(N < 3600){
		horas = 0;
	}
	else
	{
		horas = N/3600;
	}
		
	printf("%d:%d:%d\n", horas, minutos, segundos );
		
	return 0;
}