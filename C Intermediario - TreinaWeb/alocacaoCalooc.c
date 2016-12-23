#include <stdio.h>
#include <stdlib.h>

int main()
{
    int QuantidadeE,i;
    int *vetor;

    //vetor = calloc(QuantidadeE,sizeof(int));
    vetor = malloc(QuantidadeE * sizeof(int));

    printf("Informe a quantidade de valores do vetor:\n");
    scanf("%d",&QuantidadeE);

    if(!vetor)
    {
        printf("Memoria esgotada!!\n");
        exit(1);
    }

    printf("Digite os valores para o vetor:\n");
    for(i=0;i<QuantidadeE;i++)
    {
        printf("Valor para o vetor %d\n",i);
        scanf("%d",&vetor[i]);
    }

    printf("Valores do vetor:\n");
    for(i=0;i<QuantidadeE;i++)
    {
        printf("Vetor[%d]-%d\n",i,vetor[i]);
    }
    free(vetor);

    return 0;
}