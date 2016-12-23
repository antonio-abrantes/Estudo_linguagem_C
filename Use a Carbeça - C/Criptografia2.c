#include <stdio.h>
#include <string.h>

int main(){
    char texto[1000], aux[1000];
    int N, i, j;

    scanf("%d%*c", &N);
	
    while(N > 0)
	{	
		i = 0;
		j = 0;
		
		scanf("%999[^\n]%*c", texto);
		strcpy(aux, texto);
		while(i < strlen(texto)){
        if(((texto[i] >= 'A') && (texto[i] <= 'Z')) || ((texto[i] >= 'a') && (texto[i] <= 'z'))){
            texto[i] += 3;
        }
        i++;
    	}
    
    //printf("\nTrocado %s\n", texto);

    	for(i = strlen(texto)-1; i >= 0; i--){
        	aux[j] = texto[i];
        	if(j == strlen(texto)-1){
            	aux[strlen(texto)] = '\0';
            break;
        	}
        	j++;
    	}

    	j = strlen(texto)/2.0;

    	for(i = j; i < strlen(texto); i++){
        	aux[i] -= 1;
    	}
    
	N--;	
	printf("%s\n", aux);
	}
    
  return 0;
}
