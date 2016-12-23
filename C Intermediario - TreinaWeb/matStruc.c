#include <stdio.h>
struct Cao {
  char *nome;
  int idade;
  char *raca;
};

int main()
{
  struct Cao dog[3][3];
  int x, y;

  dog[0][0].nome = "brutus";
  dog[0][0].idade = 2;
  dog[0][0].raca = "doberman";

  dog[0][1].nome = "k9";
  dog[0][1].idade = 3;
  dog[0][1].raca = "doberman";

  dog[0][2].nome = "kin";
  dog[0][2].idade = 4;
  dog[0][2].raca = "doberman";

  dog[1][0].nome = "toto";
  dog[1][0].idade = 2;
  dog[1][0].raca = "vira lata";

  dog[1][1].nome = "brutus";
  dog[1][1].idade = 4;
  dog[1][1].raca = "vira lata";

  dog[1][2].nome = "zeus";
  dog[1][2].idade = 2;
  dog[1][2].raca = "vira lata";

  dog[2][0].nome = "fifi";
  dog[2][0].idade = 2;
  dog[2][0].raca = "poodle";

  dog[2][1].nome = "bidu";
  dog[2][1].idade = 4;
  dog[2][1].raca = "poodle";

  dog[2][2].nome = "deco";
  dog[2][2].idade = 3;
  dog[2][2].raca = "poodle";

  for(x = 0; x < 3; x++) {
    printf("Cao %d\n\n", x+1);
    for(y = 0; y < 3; y++) {
      printf("%s %d %s \n\n", dog[x][y].nome, dog[x][y].idade,dog[x][y].raca);
    }
  }

  return 0;
}