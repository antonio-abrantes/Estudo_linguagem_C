/*Estudo pratico de conversão de bases
  Autor: Antônio Abrantes
  Disciplina: Organização de Computadores - 3º Semestre */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Declaração das funções do sistema
void menu();
void converte(char *str, int num, int idx);
void converteUmBinario(int dividendo, char *vet, int base);
void converteDecimal(char *str, int op);
char hexadecimal(int num);
int hexadecimalNum(char num);
void converteHexadecimal(char *str);
void converteOctal(char *str);
void conveteHexaDecimal(char *str);
void converteHexaDecimal2(char *str);
void converteOctalDecimal(char *str);
void converteBinario(int dividendo, char *conver, char *strBinario);

//Função que retorna a letra correspodente ao numero em Hexadecimal
char hexadecimal(int num){
	if(num == 10){
		return 'A';
	}
	if(num == 11){
		return 'B';
	}
	if(num == 12){
		return 'C';
	}
	if(num == 13){
		return 'D';
	}
	if(num == 14){
		return 'E';
	}
	if(num == 15){
		return 'F';
	}
	return 0;
}

//Função que retorna o numero correspondente a letra do Hexadecimal
int hexadecimalNum(char num){
	if(num == 'A'){
		return 10;
	}
	if(num == 'B'){
		return 11;
	}
	if(num == 'C'){
		return 12;
	}
	if(num == 'D'){
		return 13;
	}
	if(num == 'E'){
		return 14;
	}
	if(num == 'F'){
		return 15;
	}
	return 0;
}

/* Função 1 para converter de um Hexadecimal para Decimal
Versão que converte cada caracter de acordo com o conjunto de de 4 bits
definido atravez a operação da função "converteUmBinario" */
void conveteHexaDecimal(char *str){
	int i;
	char strTemp[100], decimal[100];
	for(i = strlen(str)-1; i >= 0 ; i--){
		int temp;
		if(str[i] >= '0' && str[i] <= '9'){			
			strTemp[0] = str[i];
			strTemp[1] = '\0';
			temp = atoi(strTemp);
		}else{
			temp = hexadecimalNum(str[i]);
		}			
		converteUmBinario(temp, strTemp, 4);
		strcat(decimal, strTemp);			
	}
	printf("Decimal correspondente.: ");
	converteDecimal(decimal, 2);
	printf("\n");
}

/* Função 2 para converter de um Hexadecimal para Decimal
Versão mais simplificada, onde o valor de cada caracter é multiplicado 
pela base 16 elevado ao numero correspondente a sua posição*/
void converteHexaDecimal2(char *str){
	int i, j, temp, soma = 0;
	j = 0;
	char strTemp[100];
	
	for(i = strlen(str)-1; i >= 0 ; i--){
		if(str[i] >= '0' && str[i] <= '9'){			
			strTemp[0] = str[i];
			strTemp[1] = '\0';
			temp = atoi(strTemp);
		}else{
			temp = hexadecimalNum(str[i]);
		}			
		soma += temp * pow(16, j);
		j++;			
	}
	printf("Decimal correspondente.: %d\n", soma);
}

//Função para converter Binario para Hexadecimal
void converteHexadecimal(char *str){
	int i, j, o = 0, soma;
	int hexa[100];
	printf("\n");
	for(i = 0; i < strlen(str); i++){		
		soma = 0;
		for(j = 0; j < 4; j++){
			if(str[i+j] == '1'){
				soma += 1 * pow(2, j);
			}
		}
		i += j-1;		
		hexa[o] = soma;
		o++;
	}
	printf("Hexadecimal..: ");
	for(i = o-1; i >= 0; i--){
		if(hexa[i] < 10){
			printf("%d", hexa[i]);
		}else{
			printf("%c", hexadecimal(hexa[i]));
		}
	}	
}

//Função para converter Binario para Octal
void converteOctal(char *str){
	int i, j, o = 0, soma;
	int octal[100];
	printf("\n");
	for(i = 0; i < strlen(str); i++){		
		soma = 0;
		for(j = 0; j < 3; j++){
			if(str[i+j] == '1'){
				soma += 1 * pow(2, j);
			}
		}
		i += j-1;
		
		octal[o] = soma;
		o++;
	}
	printf("Octal........: ");
	for(i = o-1; i >= 0; i--){
		printf("%d", octal[i]);
	}	
	printf("\n");
}

//Função para converter de um Octal para um Decimal
void converteOctalDecimal(char *str){
	int i;
	char strTemp[100], decimal[100];
	for(i = strlen(str)-1; i >= 0 ; i--){
		strTemp[0] = str[i];
		strTemp[1] = '\0';	
		int temp = atoi(strTemp);
		converteUmBinario(temp, strTemp, 3);
		strcat(decimal, strTemp);			
	}
	printf("Decimal correspondente.: ");
	converteDecimal(decimal, 2);
	printf("\n");	
}

//Converte um termo de uma base Octal ou Hexadecimal para binario
void converteUmBinario(int dividendo, char *binario, int base){	
	int i = 0, divisor = 2, resto, temp[100];
	while(dividendo > 1){
		resto = dividendo % divisor;
		dividendo = dividendo / divisor;
		temp[i] = resto;
		converte(binario, temp[i], i);
		i++;
	}		
	temp[i] = dividendo;
	converte(binario, temp[i], i);	
	if(i < base){
		for(i = i+1 ; i < base ; i++){
			binario[i] = '0';
		}
		binario[i] = '\0';
	}else{
		binario[i+1] = '\0';
	}
}

//Função para converter Binario para Decimal
void converteDecimal(char *str, int op){
	int i, num = 1, soma = 0;
	
	for(i = 0; i < strlen(str); i++){
		if(str[i] == '1'){
			soma += num;
		}
		num = num * 2;
	}
	if(op == 1){		
		printf("Decimal......: %d\n", soma);
	}else if(op == 3){
		printf("Decimal correspondente.: %d\n", soma);
	}else{
		printf("%d", soma);
	}	
}

//Converte o numero Decimal em binario
void converteBinario(int dividendo, char *conver, char *strBinario){	
	int i = 0, divisor = 2, resto;
	while(dividendo > 1){
		resto = dividendo % divisor;
		dividendo = dividendo / divisor;
		//envia para a função que concatena os restos do vetor para string
		converte(conver, resto, i);
		i++;
	}		
	//envia para a função que concatena os restos do vetor para string
	converte(conver, dividendo, i);
	conver[i+1] = '\0';	
	//Inverte o conteudo da string para a exibição correta do numero Binario	
	int j = 0;	
	for( ; i >= 0; i--){
		strBinario[j] = conver[i];
		j++;
	}
	strBinario[j] = '\0';
	printf("Binario......: %s", strBinario);
}

//Função MAIN
int main()
{	
	int dividendo, op;
	char conver[100];
	char strBinario[100];
	char vet[100];
	
	while(1){
		menu();
		scanf("%d", &op);
		if(op == 0)
			break;
		
		switch(op){
		case 1:
			printf("Digite um Decimal: ");
			scanf("%d", &dividendo);
			converteBinario(dividendo, conver, strBinario);
			converteHexadecimal(conver);
			converteOctal(conver);
			system("pause");
			break;
		case 2:
			printf("\nDigite um Octal: ");
			scanf("%s", vet);
			converteOctalDecimal(vet);
			system("pause");
			break;
		case 3:
			printf("\nDigite um Hexadecimal: ");
			scanf("%s", vet);
			//conveteHexaDecimal(vet);
			converteHexaDecimal2(vet);
			system("pause");
			break;
		case 4:
			printf("\nDigite um Binario: ");
			scanf("%s", vet);
			converteDecimal(vet,3);
			system("pause");
			break;
		default:
			break;
		}	
	}
	
	printf("\n>>>Encerrando o sistema<<<\n");
	system("PAUSE");
		
	return 0;
}

//Função do menu do sistema de conversão de bases
void menu(){	
	system("CLS");
	printf("\n+--------------------------+\n");
	printf("|    Conversao de Bases    |\n");
	printf("+--------------------------+\n\n");
	printf("	OPCOES:\n");
	printf("  0 - Sair do sistema\n");
	printf("  1 - Decimal para Binario, Hexadecimal e Octal\n");
	printf("  2 - Ocatal para Decimal\n");
	printf("  3 - Hexadecimal para Decimal\n");
	printf("  4 - Binario para Decimal\n");
	//printf("  5 - \n");
	//printf("  6 - \n\n");
	printf(" Digite a opcao: ");
}

/*Função recebe os restos em cada interação e concatena em
  uma string que define o numero em Binario*/
void converte(char *str, int num, int idx){
	if(num == 0){
		str[idx] = '0';
	}else{
		str[idx] = '1';
	}	
}