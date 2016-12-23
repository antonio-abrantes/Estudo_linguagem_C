#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *vetor;

    vetor = calloc(5,sizeof(int));

    if(!vetor)
    {
        printf("Memoria esgotada!!\n");
        exit(1);
    }

    printf("Digite os valores para o vetor:\n");

    for(i=0;i<5;i++)
    {
        printf("Valor para o vetor %d\n",i);
        scanf("%d",&vetor[i]);
    }

    printf("Valores do vetor:\n");

    for(i=0;i<5;i++)
    {
        printf("Vetor[%d]-%d\n",i,vetor[i]);
    }

    vetor = realloc(vetor,10*sizeof(int));

    printf("Digite os valores para o novo vetor:\n");

    for(i = i;i<10;i++)
    {
        printf("Valor para o vetor %d\n",i);
        scanf("%d",&vetor[i]);
    }

    printf("Valores do vetor:\n");

    for(i=0;i<10;i++)
    {
        printf("Vetor[%d]-%d\n",i,vetor[i]);
    }
    
    printf("%d", sizeof(vetor) / sizeof(int));

    free(vetor);

    return 0;
}