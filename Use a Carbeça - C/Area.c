#include <stdio.h>

#define pi 3.14159

int main(){

  double A, B, C, triangulo, circulo, trapezio, quadrado, retangulo;

  scanf("%lf %lf %lf", &A, &B, &C);
  
  //Triangulo = A = base e C = altura => area = (a.c)/2
  triangulo = (A * C)/2;
  
  //Círculo = raio = C  => area = pi.C²
  circulo = pi *(C * C);
  
  //Trapézio = A e B = base e C = altura => area = ((A + B).C)/2
  trapezio = ((A + B)*C)/2;
  
  //Quadrado = B = lado => area = B.B
  quadrado = B * B;
  
  //Retangulo = A e B = lados => area = A.B
  retangulo = A * B;

  printf("TRIANGULO: %.3lf\n", triangulo);
  printf("CIRCULO: %.3lf\n", circulo);
  printf("TRAPEZIO: %.3lf\n", trapezio);
  printf("QUADRADO: %.3lf\n", quadrado);
  printf("RETANGULO: %.3lf\n", retangulo);

  return 0;
}