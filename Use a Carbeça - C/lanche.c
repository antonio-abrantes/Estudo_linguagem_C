#include <stdio.h>

int main()
{
	int codigo, quantidade;
	float v_pagar = 0;
	
	scanf("%d %d", &codigo, &quantidade);
	
	switch(codigo)
	{
	case 1:
		//Cachorro quente
		v_pagar = (float)quantidade * 4.00; 
		break;
	case 2:
		//X-Salada
		v_pagar = (float)quantidade * 4.50;
		break;
	case 3:
		//X-Bacon
		v_pagar = (float)quantidade * 5.00;
		break;
	case 4:
		//Torrada simples
		v_pagar = (float)quantidade * 2.00;
		break;
	case 5:
		//Refrigerante
		v_pagar = (float)quantidade * 1.50;   	
	default:
		break;
	}
	
	printf("Total: R$ %.2f\n", v_pagar);
	
	return 0;
}