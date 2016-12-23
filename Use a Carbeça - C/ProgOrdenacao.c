#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b){ //Ordenação numerica
	double a = *(double*)score_a;
	double b = *(double*)score_b;
	
	return a - b;
}

int compare_nomes(const void* a, const void* b){  //Ordenação alfabetica
	char** sa = (char**)a;
	char** sb = (char**)b;
		
	return strcmp(*sa, *sb);
	
}

int main(){
	
	double scores[] = {543, 323, 32, 554, 11, 3, 112};
	int i;
	qsort(scores, 7, sizeof(double), compare_scores);
	puts("These scores in order.:");
	for(i = 0; i < 7; i++){
		printf("Score = %.2lf\n", scores[i]);
	}
	
/*================================================================  */

	char *nomes[] = {"Karen", "Mark", "Antonio", "Mark"};
	i = 0;
	
	qsort(nomes, 4, sizeof(char*), compare_nomes);
	for(i = 0; i < 4; i++){
		printf("%s\n", nomes[i]);
	}
	
	printf("\n%i", strcmp(nomes[3], nomes[0]));
	
	return 0;
}
