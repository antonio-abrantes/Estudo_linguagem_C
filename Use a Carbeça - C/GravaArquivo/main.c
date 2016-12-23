#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30], endereco[30];
    int id;
  }cadastro;

void gravar_dados();
void ler_dados();
void listar_ultimo();
void lista_escolha();
void lista_todos();

int main(){
  int cont;
  while(1){
    //gravar_dados();
    ler_dados();
    listar_ultimo();
    lista_escolha();
    lista_todos();
    printf("\n\nSair? 1 <SIM> Qualquer tecla para continuar...");

    scanf("%d%*c", &cont);
    if(cont == 1){
      break;
    }

  }

  return 0;
}

void lista_todos(){
  FILE *arq = fopen("dados.txt", "rb");
  cadastro todos;
  int cont = 0;

  printf("\n\nListando todos os clientes...\n");
  while(1){
    size_t result = fread(&todos, sizeof(cadastro), 1, arq);

    if(result == 0){
      break;
    }
    cont = 1;
    printf("\nNOME: %s, End: %s, Idade: %d ",
                        todos.nome, todos.endereco,todos.id);

  }

  fclose(arq);
  fseek(arq, 0, SEEK_END);
}

void lista_escolha(){

  int codigo;

  printf("\n\nDigite o codigo: ");
  scanf("%d", &codigo);
  scanf("%*c");

  FILE *arq = fopen("dados.txt", "rb");
  cadastro busca;

  fseek(arq, 0, SEEK_END);

  fseek(arq, (codigo - 1) * sizeof(cadastro), SEEK_SET);
  fread(&busca, sizeof(cadastro), 1, arq);

    printf("\nNome buscado\nNOME: %s, End: %s, Idade: %d \n",
                        busca.nome, busca.endereco, busca.id);

  fclose(arq);
  fseek(arq, 0, SEEK_END);
  system("pause");
}

void listar_ultimo(){
  cadastro ultimo;
  int cont_bytes, num_reg;

  FILE *arq = fopen("dados.txt", "rb");

  cont_bytes = 0;
  fseek(arq, 0, SEEK_END);
  cont_bytes = ftell(arq);

  fseek(arq, cont_bytes - sizeof(cadastro), SEEK_SET);
  fread(&ultimo, sizeof(cadastro)+1, 1, arq);

    printf("\nUltimo registro\nNOME: %s, End: %s, Idade: %d ",
                        ultimo.nome, ultimo.endereco, ultimo.id);

  fseek(arq, 0, SEEK_END);
  fclose(arq);
}

void ler_dados(){
  cadastro leitura[100];
  int cont_bytes, num_reg;

  FILE *arq = fopen("dados.txt", "rb");
  printf("\nDigite a quantidade de registros que deseja.: ");
  scanf("%d", &num_reg);

  cont_bytes = ftell(arq);
  fseek(stdin, 0, SEEK_END);

  fread(&leitura, sizeof(cadastro), num_reg, arq);

  int i = 0;
  while(i < num_reg){
    printf("\n%d - NOME: %s, End: %s, Idade: %d ", i+1,
                        leitura[i].nome, leitura[i].endereco, leitura[i].id);
    i++;
  }
  fclose(arq);
  fseek(arq, 0, SEEK_END);
  printf("\n\n");
  system("pause");
}

void gravar_dados(){
  FILE *arq = fopen("dados.txt", "a+b"); //Escreve adicionando conteudo na ultima linha
  //FILE *arq = fopen("dados.txt", "wb"); //Escreve substitui todo conteudo
  if(arq == NULL){
    printf("Erro na abertura\n");
    system("pause");
    exit(1);
  }

  int cont_bytes = 0;

  fseek(arq, 0, SEEK_END);


  cadastro cad;

  printf("Digite o nome: ");
  gets(cad.nome);
  printf("Digite o endereco: ");
  gets(cad.endereco);
  printf("Digite a idade: ");
  scanf("%d", &cad.id);

  fwrite(cad.nome, sizeof(cadastro), 1, arq);
  //fwrite(&cont_bytes, sizeof(int), 1, arq);

  cont_bytes = ftell(arq);

  printf("\nTamanho do arquivo.: %ld\n", cont_bytes);

  fclose(arq);
  system("pause");
}
