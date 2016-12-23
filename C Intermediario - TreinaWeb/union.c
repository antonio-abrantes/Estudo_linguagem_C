#include <stdio.h>
#include <stdlib.h>

union Numeros
{
  float num1;
  int num2;
};

int main()
{
    union Numeros p1;
    int op;

    scanf("%d",&op);

    if(op == 1)
    {
        p1.num1 = 4.5;
        printf("Num1: %f\n",p1.num1);
    }else{
        p1.num2 = 2;
        printf("Num2: %d\n",p1.num2);
    }

  return 0;
}