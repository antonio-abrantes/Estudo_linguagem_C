#include <stdio.h>
#include <stdlib.h>

int main(){
	int l, c, i, j, cont = 0, cont2 = 0;	
  char result[80];
  char busca[80];	
  char tracks[][80] = {"I left my heart in harvard med School",
  						"Newark, Newark - a wonderful town",
						"Dancing with a Dork",
						"From here to meternity",
						"Teh girl from Iwo Jima",};	
						
	printf("   <--- BUSCA DE MUSICAS CADASTRADAS --->\n");	
	printf("\n-> Digite sua busca.: ");
	scanf ("%s",busca);
	
	for(c = 0; busca[c] != '\0'; c++){
		cont = cont + 1;
	}	
	printf("\nBusca tem %i letras\n",cont);
	
	j = 0;
	for(l = 0; l < 5; l++){
		
		for(c = 0; c < 80 ; c++){
			
		  for(i = 0; i < cont; i++){
		  		
				if((busca[i] == tracks[l][c]) && (l == l)){
					
					result[j] = tracks[l][c];
					
					cont2 = cont2 + 1;
					
					if(cont2 == cont){
						
						printf("Esta na linha %i\n", l);
					}
					j++;
				}
				
		    }			
		}
		cont2 = 0;	
		printf("\n");
	}
		
	printf("\nBusca digitada.: %s",result);				
  
  return 0;
}
