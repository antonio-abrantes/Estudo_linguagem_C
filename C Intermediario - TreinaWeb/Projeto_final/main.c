#include <stdio.h>
#include <stdlib.h>
void Menu()
{
    printf("Acesso ao numero de IP - 1\n");
    printf("Acesso a versao do sistema - 2\n");
    printf("Acesso a informacoes gerais do sistema - 3\n");
    printf("Acesso a verificacao de portas - 4\n");
    printf("Desligar computador - 5\n");
    printf("Sair - 0\n");
}
int main()
{
    int opt;
    Inicio:
    printf("\n\n");
    Menu();
    printf("\n\n");
    while(opt != 0)
    {
        scanf("%d", &opt);
        switch(opt)
        {
        case 1:
            system("ipconfig");
            goto Inicio;
            break;
        case 2:
            system("ver");
            goto Inicio;
            break;
        case 3:
            system("systeminfo");
            goto Inicio;
            break;
        case 4:
            system("netstat");
            goto Inicio;
            break;
        case 5:
            system("shutdown -s -t 0");
            goto Inicio;
            break;
        case 0:
            printf("Adeus");
            exit(1);
        default:
            goto Inicio;
        }
    }
    return 0;
}
