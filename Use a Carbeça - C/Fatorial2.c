#include <stdio.h>

int fatorial(int num){
	if(num == 0 || num == 1){
		return 1;
	}
	
	return (num * fatorial(num - 1));
}


int main()
{
	printf("%i ", fatorial(5));
	
	return 0;
}