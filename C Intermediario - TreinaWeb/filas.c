#include <stdio.h>
#include <stdlib.h>

struct NO{
  int numero;
  struct NO *proximo;
};
typedef struct NO no;

no *RETIRADA(no *FILA)
{
  if(FILA->proximo == NULL){
    printf("Fila ja esta vazia\n");
  }else{
    no *temp = FILA->proximo;
    FILA->proximo = temp->proximo;
  }

}


void OPCOES(no *FILA, int op)
{
  no *temp;
  switch(op){
    case 0:
      LIBERACAO(FILA);
      break;

    case 1:
        INSERIR(FILA);
      break;

    case 2:
        temp= RETIRADA(FILA);
      break;

    case 3:
        EXIBIR(FILA);
      break;

    default:
      printf("Comando invalido\n\n");
  }
}


int vazia(no *FILA)
{
  if(FILA->proximo == NULL)
    return 1;
  else
    return 0;
}

no *ALOCACAO()
{
  no *novo= malloc(sizeof(no));
  if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    printf("Novo elemento na Fila: "); scanf("%d", &novo->numero);
    return novo;
  }
}

void INSERIR(no *FILA)
{
  no *novo=ALOCACAO();
  novo->proximo = NULL;

  if(vazia(FILA))
    FILA->proximo=novo;
  else{
    no *temp = FILA->proximo;

    while(temp->proximo != NULL)
      temp = temp->proximo;

    temp->proximo = novo;
  }

}

void EXIBIR(no *FILA)
{
  if(vazia(FILA)){
    printf("Fila vazia!\n\n");
    return ;
  }

  no *temp;
  temp = FILA->proximo;
  printf("\nFila :");
  while( temp != NULL){
    printf("%5d", temp->numero);
    temp = temp->proximo;
  }

  printf("\n\n");
}

void LIBERACAO(no *FILA)
{
  if(!vazia(FILA)){
    no *proxNode,
        *atual;

    atual = FILA->proximo;
    while(atual != NULL){
      proxNode = atual->proximo;
      free(atual);
      atual = proxNode;
    }
  }
}


int main(void)
{
    int opt;

  no *FILA = malloc(sizeof(no));
  if(!FILA){
    printf("Sem memoria!\n");
    exit(1);
  }else{
    FILA->proximo = NULL;

  do{

        printf("Opcoes\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Retirar\n");
        printf("3 - Exibir\n");
        printf("Opcao: ");
        scanf("%d", &opt);

    OPCOES(FILA,opt);
  }while(opt);

  free(FILA);
  return 0;
  }
}