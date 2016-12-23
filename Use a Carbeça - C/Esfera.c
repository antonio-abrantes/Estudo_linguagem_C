#include <stdio.h>

#define pi 3.14159

int main(){

  int raio;
  double volume, raio3;

  scanf("%d", &raio);

  raio3 = ((double)raio * raio) * (double)raio;
  
  volume = (4/3.0) * pi * raio3;

  printf("VOLUME = %.3lf\n", volume);

  return 0;
}