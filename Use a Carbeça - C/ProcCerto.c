#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;
	
	char *ADS[] = {
		"wilian: SWM NS likes sports, TV , dining",
		"Matt: SBM NS likes art, movies, theater",
		"Luis: SLM ND likes books, theater, art",
		"Mike: DWM DS ikes trucks, sports and bieber",
		"Peter: SAM likes chess, working out and art",
		"Josh: SJM likes sports, movies end theater",
		"Jed: DBM likes theater, books and dining",};
		
int sport_no_bieber(char *s){
	return strstr(s, "sports") && !strstr(s, "bieber");
}		

void find(int (*funcao)(char*) ){
	int i;
	puts("Procura resultado.:");
	puts("----------------------------------------------");
	
	for(i = 0; i < NUM_ADS; i++){
		if(funcao(ADS[i]) ){
			printf("%s\n", ADS[i]);
		}
		
	}
	puts("----------------------------------------------");
}

int main(){
	
		
	find(sport_no_bieber);
		
	return 0;
}
