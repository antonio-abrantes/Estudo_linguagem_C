#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *pointer;

  pointer = malloc(sizeof(int));

  if(pointer)
  {
     printf("Memoria alocada com sucesso.\n");
  }
  else
  {
     printf("Memoria nao alocada.\n");
     exit(1);
  }
  *pointer = 100;
  printf("Valor: %d\n\n", *pointer);
  free(pointer);
  return 0;
}