#include <stdio.h>
#include <stdlib.h>

int matrix[3][3];

int check_winner();
int check_draw();
void init_matrix();
void get_player_action();
void get_computer_action();
void show_matrix();

int main(int argc, char *argv[]){
    system("title - Jogo da Velha");
    char winner = 'E';
    int cont;

    init_matrix();

    do{
        do{
      system("cls");
      //chama funcao para mostrar matriz
      show_matrix();
      //obtém o movimento do jogador
      get_player_action();
      //verifica se há vencedor
      if(check_winner() == 1){
        winner = 'P';
        break;
      }
      //obtém o movimento do computador
      get_computer_action();
      if(check_winner() == 1){
        winner = 'C';
        break;
      }
      //Verifica se houve empate
      if(check_draw() == 1){
        winner = 'E';
      }

    } while(1);
        show_matrix();
        if(winner == 'P'){
            system("cls");
            show_matrix();
            printf("\n\nParabens, voce ganhou!");
        }
        else if(winner == 'C'){
            system("cls");
            show_matrix();
            printf("\n\nO computador ganhou, tente novamente...");
        }
        else{
            system("cls");
            show_matrix();
            printf("\n\nEmpatou!");
        }
        printf("\n\nDeseja jogar novamente? <1>SIM <outro valor>NAO: ");
        scanf("%d%*c",&cont);

        if(cont == 1){
            system("cls");
            init_matrix();
            continue;
        }
        else{
            break;
        }
    }while(1);
    printf("\n\nPressione ENTER para encerrar o programa...");
    scanf("%*c");

  return 0;
}

void init_matrix(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           matrix[i][j] = ' ';
        }
    }
}

int check_winner(){
    int i;
    //Verifica as linhas
    for(i = 0; i < 3; i++){
        if(matrix[i][0] != ' ' && matrix[i][1] != ' ' && matrix[i][2] != ' '){
            if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]){
                return 1;
            }
        }
    }
    //Verifica colulas
    for(i = 0; i < 3; i++){
        if(matrix[0][i] != ' ' && matrix[1][i] != ' ' && matrix[2][i] != ' '){
            if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]){
                return 1;
            }
        }
    }
    //verifica as diagonais
    for(i = 0; i < 3; i++){
        if(matrix[0][0] != ' ' && matrix[1][1] != ' ' && matrix[2][2] != ' '){
            if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
                return 1;
            }
        }
    }
    for(i = 0; i < 3; i++){
        if(matrix[0][2] != ' ' && matrix[1][1] != ' ' && matrix[2][0] != ' '){
            if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){
                return 1;
            }
        }
    }

    return 0;
}

void get_computer_action(){
  int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matrix[i][j] == ' '){
                matrix[i][j] = 'O';
                return;
            }
        }
    }
}

void get_player_action(){
    int x, y;
    printf("\nDigite as coordenadas (exemplo 1 2): ");
    scanf("%d %d%*c", &x, &y);
    x--;
    y--;
    if(matrix[x][y] != ' '){
        printf("Posição invalida, tente novamente");
        get_player_action();
    }
    else{
        matrix[x][y] = 'X';
    }
}

void show_matrix(){
    int i;
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("\t  %c | %c | %c\n", matrix[i][0],
               matrix[i][1], matrix[i][2]);
        if(i != 2){
        printf("\t-------------\n", matrix[i][0],
               matrix[i][1], matrix[i][2]);
        }
    }
}

int check_draw(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matrix[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}








