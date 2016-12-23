#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char card_name[3];
	int count = 0;
	
	while(card_name[0] != 'X'){
		puts("Enter the card_game: ");
		scanf("%2s",card_name);
		int val = 0;
	
		if (card_name[0] == 'K'){
		val = 10;
	}
		else if(card_name[0] == 'Q'){
		val = 10;
	}
		else if(card_name[0] == 'J'){
		val = 10;
	}
		else if(card_name[0] == 'A'){
		val = 11;
	}
		else if(card_name[0] == 'X'){
		continue;		
	}
		else{
		val = atoi(card_name);
		if((val < 1) || (val > 10)){
			printf("I dont understand that value!\n");
			continue;
		}
	}
	printf("The card value is: %i\n",val);
	
	if((val >= 3) && (val <= 6)){
		puts("Count has gone up");
		count++;
	}
	else if(val == 10){
		puts("Count has gone down");
		count--;
	}
	printf("Current count: %i\n",count);
		
	}
	
	return 0;
}
