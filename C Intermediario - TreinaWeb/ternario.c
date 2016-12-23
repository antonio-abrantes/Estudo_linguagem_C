#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r;
    char *nome, teste[10];
    
    scanf("%d", &r);
    
    printf("%2d\n", r);
    
    //nome = "Antonio";
    
    free((int)r);
    
    printf("%d", r);
    //nome = "Eu";
    
   // printf("%c\n", nome[0]);
    //printf("%s\n", nome);
    
    //r <= 0 ? printf("Menor\n") : printf("Maior\n");
    
    //printf("O maior numero e %.2f\n",r);
    return 0;
}