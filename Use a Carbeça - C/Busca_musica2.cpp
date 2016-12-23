#include <stdio.h>
#include <string.h>

char tracks[][80] = {"I left my heart in harvard med School",
  						"Newark, Newark - a wonderful town",
						"Dancing with a Dork",
						"From here to meternity",
						"Teh girl from Iwo Jima",
	};
						
void find_track(char busca[]){
	int l;	
	for(l = 0; l < 5; l++){
		if(strstr(tracks[l], busca)){
			printf("\nResultado da busca.: %s",tracks[l]);
		}			
	}
}						

int main(){
	
  char busca[80];		
	printf("   <--- BUSCA DE MUSICAS CADASTRADAS --->\n");
	//printf("       -> Digite 5 para encerrar\n");					
		
	printf("\n\n-> Digite sua busca.: ");
	scanf ("%s",busca);
	
	find_track(busca);
	 
  return 0;
}


