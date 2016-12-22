#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "grafic.h"
#include "creditos.h"

int tam_palavra;
int chance;
char banco[13][15] = {"MACACO", "COELHO", "CACHORRO", "GALINHA", "PORTA", "AUTOMOVEL", "PASSARO",
					  "CACHOEIRA", "RIACHO", "MELANCIA", "BANANA", "GATO", "GALO"};
char palavra_dig[15], vetor[15];

void menu(){
	printf("\n\t<<BEM VINDO AO JOGO DA FORCA>>\n\t------------------------------\n\n");
	//printf("\n\tPALAVRA: %s\n", palavra);
}

void m_chances(int chan){
	printf("\tVOCE TEM %i CHANCES", chance);
}

int sorteia(){
	srand(time(NULL));
    return rand() % (13);
}

void copia_palavra_sorteada(int palavra){
	int i;
        //printf("\n\t%s", banco[palavra]);
        for(i = 0; i < 15; i++){
            palavra_dig[i] = banco[palavra][i];
        }
        //tam_palavra = strlen(palavra_sort);
}

void limpaVetor(){
	int i;
	printf("\n\n LETRAS -> ");
	for(i = 0; i < strlen(palavra_dig); i++){
			vetor[i] = '_';
			printf(" %c ", vetor[i]);
		}
		printf("\n\n");
}

void quant_letras(){
	printf("\n  A PALAVRA TEM %i LETRAS", strlen(palavra_dig));
}

void mostraVetor(char palavra[]){
	int i;
	system("cls");
	menu();
	quant_letras();
	printf("\n\n LETRAS -> ");
	for(i = 0; i < strlen(palavra_dig); i++){
			printf(" %c ", vetor[i]);
		}
		printf("\n\n");
}

int buscaLetra(char letra, char palavra[]){
	int i, b = 0;
	if(letra == 'Z'){
			coracao();
		}
	for(i = 0; i < strlen(palavra_dig); i++){
		if(palavra_dig[i] == letra){
			vetor[i] = palavra_dig[i];
			printf("%c", vetor[i]);
			b = 1;
		}
	}
	return b;
}

int main(){
	chance = 6;
    menu();
    int cont_erros = 0;
	char letra;

	copia_palavra_sorteada(sorteia());
	
	tam_palavra = strlen(palavra_dig);
	quant_letras();

	limpaVetor();

	while(cont_erros <= 7){
		system("color 1B");
		m_chances(chance);
        imprime_forca(cont_erros);
		if(cont_erros < 7){
			printf(" Digite a letra buscada.: ");
			scanf("%c",&letra);
		}
		else{
			system("pause");
		}
		letra = toupper(letra);
        getchar();

		if(buscaLetra(letra, palavra_dig) != 0){
            mostraVetor(palavra_dig);
		}
		else{
            mostraVetor(palavra_dig);
            cont_erros++;
            if(cont_erros <= 6){
            	chance--;
			}
            if(cont_erros > 7){
                system("cls");
                printf("\n\tFIM DE JOGO\n");
                creditos();
                system("pause");
                break;
            }
		}
		if(strcmp(palavra_dig, vetor) == 0){
            printf("\tParabens! Voce ganhou!");
            imprime_forca(8);
            system("pause");
            system("cls");
            creditos();
            system("pause");
            break;
		}
	}

	return 0;
}
