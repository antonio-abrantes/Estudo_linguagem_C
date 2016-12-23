#include <stdio.h>
#include <stdlib.h>

typedef struct Cao {
  char *nome;
  int idade;
  char *raca;
}dog;

void Mudar(dog *c)
{
    //printf("Nome : %s\n",c->nome);
    //printf("Idade : %d\n",c->idade);
    //printf("Raca : %s\n",c->raca);
    
    c->idade = 10;
	(*c).nome = "Eu";   
}

dog Exibir(dog c)
{
    printf("Nome : %s\n",c.nome);
    printf("Idade : %d\n",c.idade);
    printf("Raca : %s\n",c.raca);
    
    c.idade = 10;
	   
    return c;
}

int main()
{
    dog d1 = {"fifi",2,"poodle"};
    Exibir(d1);
    dog *ponteiro = &d1;
    
    printf("IDADE: %d\n", d1.idade);
    Mudar(ponteiro);
    printf("APOS USAR O PONTEIRO: IDADE: %d e NOME: %s\n", d1.idade, (*ponteiro).nome);

	dog d2 = Exibir(d1);
	printf("IDADE ATUAL: %d\n", d2.idade);
	
  return 0;
}