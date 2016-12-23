#include <stdio.h>
#include <string.h>

struct Peixe{
	char nome[15];
	char especie[15];
	int num;
};

struct Peixe retorna(struct Peixe f2){ //Função com retorno
	//f2.nome = {"Antronio"}; 
	printf("%s\n",.nome);
	printf("%d\n",.num);	
	
	return f2;
}

struct Peixe bPeixe(struct Peixe f[3]){ //Função sem retorno
	int i;
	for (i = 0; i < 3; i++){
		printf("Digite o nome do peixe %i.: ", i + 1);
		scanf("%s",f[i].nome);
	}
	
	return *f;
}

void mPeixe(struct Peixe f[3]){ //Função sem retoirno
	int i;
	for(i = 0; i < 3; i++){
		printf("Peixe %i.: %s\n", i+1, f[i].nome);
	}
}
int main(){
	struct Peixe bPeixe(struct Peixe f[3]);
	void mPeixe(struct Peixe f[3]);
	struct Peixe retorna(struct Peixe f2);
	
	struct Peixe peixe[3];
	
	bPeixe(peixe);	
	mPeixe(peixe);
	
	struct Peixe peixe2;
	printf("Peixe extra.: ");
	scanf("%s", peixe2.nome);
	
	peixe2 = retorna(peixe2);
		
	return 0;
}
