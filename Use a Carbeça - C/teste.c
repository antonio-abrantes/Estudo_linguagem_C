#include <stdio.h>

int main()
{
	int horaPartida, tempoViagem, fuso, resultado;
	
	scanf("%d %d %d", &horaPartida, &tempoViagem, &fuso);
	

	//if(horaPartida == 0){
		resultado = tempoViagem - fuso;
		//resultado = resultado + 24;
		printf("%d\n", resultado);
	//}
	//else if(horaPartida < 0){
	//	resultado = ((horaPartida + tempoViagem) - 24) - fuso;
	//}
	//else{
	//	resultado = (horaPartida + tempoViagem) + fuso;
	//}

	
			
		printf("%d\n", resultado);

	
	
	return 0;
}
