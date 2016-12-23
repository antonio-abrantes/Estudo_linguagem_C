#include <stdio.h>
#include <stdlib.h>

void open_url(char *url){
	char launch[255];
	sprintf(launch,"cmd /c start %s", url);
	system(launch);	
}

int main(){
	char texto[30];
	FILE *my_file = fopen("Ilhas.txt", "r");
	
	int descriptor = fileno(my_file);
	
	printf("%i\n", descriptor);
	
	while(fgets(texto, 29, my_file) != NULL){
		printf("%s\n",texto );
	}
	
	open_url("C:\\JogodaForca Beta 3.exe");
	
	return 0;
}
