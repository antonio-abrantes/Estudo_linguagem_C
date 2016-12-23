#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(){
	int a, r = 0;
	int contador = 0; 
	char vetor[42][2] = {"A", "B", "C", "D", "F", "G", "R", "T", "Z", "P", 
						 "º", "¢", "Ñ", "¦", "-", "?", "ì", "»", "i", "Ü",
						 "A", "B", "°", "D", "@", "-", "R", "î", "Z", "Â",
						 "®", "¦", "¢", "º", "+", "ë", "å", "T", "Û", "Ï",
						 "&", "*"};
	
	system("COLOR 0A");
	
	while(a < 11){
		r = rand() % 42;
		printf(" %s ", vetor[r]);
		if(a == 10){
			a = 0;
		}
		a++;
		if(contador == 80){
			contador = 0;
			//printf("\n");
			Sleep(200);
		}
		contador++;
	}
	
	return 0;
}
