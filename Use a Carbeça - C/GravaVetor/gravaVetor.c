#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lista_todos();
void cadastra();

int main(){
   cadastra();
   lista_todos();

  return 0;
}

void cadastra(){
    char texto[100];
    FILE *arq = fopen("dados.txt", "a+b");

    printf("Digite o texto: ");
    gets(texto);
    fseek(arq, 0, SEEK_END);

    fwrite(texto, sizeof(char), 99, arq);

    printf("\nTexto gravado com sucesso...\n");
    fclose(arq);
    fseek(arq, 0, SEEK_END);

}

void lista_todos(){

  FILE *arq = fopen("dados.txt", "rb");
  char texto[100];

  int cont = 0;

  printf("\n\nExibir texto cadastrado...\n");
  while(1){
    size_t result = fread(texto, sizeof(char), 99, arq);

    if(result == 0){
      break;
    }
    cont = 1;
    printf("\nTexto: %s",texto);

  }

  fclose(arq);
  fseek(arq, 0, SEEK_END);
}
