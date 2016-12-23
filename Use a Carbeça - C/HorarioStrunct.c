/* Crie um programa que possui uma função que recebe como 
argumento um vetor de tamanho 5 de tipo estrutura sendo que
essa estrutura deve armazenar um determinado horário no 
formato hh:mm:ss, peça que o usuário digite 5 horários 
diversos que deverão ser armazendos no argumento recebido.
Crie uma segunda função que receberá este msmo vetor estrutura
mas dessa vez a função deverá apenas ler os valores armazendos
no vetor estrtura mostrando uma mensagem apropriada  */

#include <stdio.h>
#include <string.h>

struct horario{
		int horas;
		int minutos;
		int segundos;
};

void receberHorarios(struct horario x[3]){
	int i;
	for(i = 0; i < 3; i++){
		printf("Digite a hora %d .: ", i+1);
			scanf("%d:%d:%d", &x[i].horas, 
							  &x[i].minutos, 
							  &x[i].segundos);
	}	
}

void printHorarios(struct horario x[3]){
	int i;
	for(i = 0; i < 3; i++){
		printf("Horario %i - %i:%i:%i\n", i + 1,
										  x[i].horas,
										  x[i].minutos,
										  x[i].segundos);
	}
}

int main(){
		
	void receberHorarios(struct horario list[3]);
	void printHorarios(struct horario list[3]);
	struct horario Horario[3];  // recebe esta
	
	receberHorarios(Horario);
	
	printHorarios(Horario);
	
	return 0;
}
