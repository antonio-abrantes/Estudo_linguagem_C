#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* VERIFICAR DATA NO FORMATO DD/MM/AAAA  */

int main(){
    char data[12];
    char dia[3] = "\0\0\0";
    char mes[3] = "\0\0\0";
    char ano[5] = "\0\0\0\0";
    int d, m, a;

    printf("Digite a data.: ");
    scanf("%s", data);

    strncpy(dia, data, 2);
    d = atoi(dia);

    if(strlen(data) != 10){
        printf("Data invalida, caracteres insuficientes");
    }
    else if(d > 0 && d <= 31 ){  //Verifica dias do mes
        strncpy(mes, (data + 3), 2);
        m = atoi(mes);
        if(m > 0 && m <= 12){  //Verifica o mes
            strncpy(ano, (data + 6), 4);
            a = atoi(ano);
            if(a > 1960 & a <= 9999){  //Verifica o ano
            printf("Data no formato correto");
           }
           else{
            printf("Ano invalido");
           }
        }
        else{
            printf("Mes invalido!");
        }
    }
    else{
        printf("\nDia invalido");
    }

    getch();

 return 0;
}
