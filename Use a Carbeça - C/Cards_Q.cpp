#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	//char masked_raider[13] = "Alive";
	char masked_raider[15];
	char *jimmy = masked_raider;
	char teste = 'E';
	char *ponteiro =  &teste;
	
	scanf("%s",masked_raider);
	
	printf("Masked Raider is %s, Jimmy is %s\n", masked_raider, jimmy);
	//printf("\n%s\n",teste);
	printf("\n%i\n",sizeof(masked_raider));
	
	
/*	char cards[] = "JQK";
	//char *teste = "Antonio";
	char *teste = cards;
	char a_card = cards[2];
	
	 cards[2] = cards[1];
	cards[1] = cards[0];
	cards[0] = cards[2];
	cards[2] = cards[1];
	cards[1] = a_card;
	
	puts(cards);
	printf("\n%s\n",teste);
	printf("\n%i",sizeof(cards)); 
	return 0; */	
}
