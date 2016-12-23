#include <stdio.h>
#include <stdlib.h>

enum dias_da_semana {Segunda = 1, Terca, Quarta, Quinta, Sexta, Sabado,
     Domingo}dias;

int main()
{
    printf("Digite o numero do dia: ");
    scanf("%d",&dias);

      switch(dias)
      {
          case Segunda:
               printf("%d - Segunda",dias);
          break;

          case Terca:
               printf("%d - Terca",dias);
          break;

          case Quarta:
               printf("%d - Quarta",dias);
          break;

          case Quinta:
               printf("%d - Quinta",dias);
          break;

          case Sexta:
               printf("%d - Sexta",dias);
          break;

          case Sabado:
               printf("%d - Sabado",dias);
          break;

          case Domingo:
               printf("%d - Domingo",dias);
          break;

          default:
            printf("Dia invalido");
            exit(1);

      }

    return 0;
}