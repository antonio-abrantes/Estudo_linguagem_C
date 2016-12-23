#include <stdio.h>
#include <conio.h>
#include <time.h>

#define vet 2

int main(){

    char vetor[vet] = "EU";
    int i;
    time_t hora_atual;
    time_t hora_inicio;

    //if (DIA == 7){
        printf("Funcioneou! Vetor tem tamanho %i\n", sizeof(vetor));
    //}
    printf("Prestes a fazer uma pausa de 5 segundos\n");
    time(&hora_inicio);
    do{
        time(&hora_atual);
    }while((hora_atual - hora_inicio) < 5);

    printf("Acabado\n HORA: %s", ctime(&hora_atual) );
    //clrscr();

  return 0;
}
