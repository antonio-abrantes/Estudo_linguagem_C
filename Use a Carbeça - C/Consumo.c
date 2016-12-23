#include <stdio.h>

#define kmL 12; //Kilometros por litro

int main(){

  int tempo_viagem, vel_media;
  float consumoMedio;

  scanf("%d", &tempo_viagem);
  scanf("%d", &vel_media);
  
  consumoMedio = ((float)tempo_viagem * vel_media)/kmL;

  printf("%.3f\n", consumoMedio);

  return 0;
}