#include <stdio.h>
#include <string.h>

typedef struct{
	char *nome;
	int idade;
} turtle;
/*
void aniver(turtle *t){
	(*t).idade = (*t).idade + 1;
	printf("Feliz aniversario %s! Voce fez %i anos!\n", (*t).nome, (*t).idade );	
}*/

turtle teste(turtle f){
	printf("Feliz aniversario!!\n");
	f.idade = f.idade + 1;
	f.nome = "Tata velha";
	
	return f;
}

int main(){
	//void aniver(turtle *t)
	
	turtle tata = {"Tata", 99};
	turtle tata1 = teste(tata);
	printf("%s agora tem %i\n",  tata1.nome, tata1.idade);
		
	return 0;
}
