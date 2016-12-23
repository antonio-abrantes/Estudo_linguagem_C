#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// quantidade máxima de letras do nome do cliente e do filme
#define MAX 100

// definição da struct do filme
typedef struct filme
{
	// campos da struct filme
	int id;
	int id_cliente;
	char nome[MAX];
	float preco;
} t_filme;

// definição da struct cliente
typedef struct cliente
{
	// campos da struct cliente
	int id;
	char nome[MAX];
} t_cliente;

// protótipos de funções

char menu(); // exibe as opções do programa
void cadastrar_cliente(); // cadastra um cliente pelo nome
void cadastrar_filme(); // cadastra um filme com o nome e preço
void listar_filmes(); // exibe todos os filmes cadastrados e as info. de aluguel
void listar_clientes(); // exibe todos os clientes cadastrados
t_filme *obter_filme(FILE *arq_filmes, int id_filme); // procuma um filme pelo id
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente); // procura um cliente pelo id
void pesquisar_filme(); // pesquisa por um filme e exibe suas informações
void pesquisar_cliente(); // pesquisa por um cliente e exibe suas informações
int existe_filme(FILE *arq_filmes, int id_filme); // procura um filme pelo seu id
int existe_cliente(FILE *arq_clientes, int id_cliente); // procura um cliente pelo seu id
void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado); // atualiza as info. do filme
void alugar_filme(); // aluga um filme
void excluir_filme(); // exclui um filme
void entregar_filme();
int str_somente_numeros(char str[]); // informa se a string é um número

int main(int argc, char *argv[])
{
	char resp;
	while(1){
		//Obtem opção do usuario
		resp = menu();
		if(resp == '1'){
			cadastrar_filme();
		}
		else if(resp == '2'){
			cadastrar_cliente();
		}
		else if(resp == '3'){
			listar_filmes();
		}
		else if(resp == '4'){
			listar_clientes();
		}
		else if(resp == '5'){
			pesquisar_filme();
		}
		else if(resp == '6'){
			pesquisar_cliente();
		}
		else if(resp == '7'){
			alugar_filme();
		}
		else if(resp == '8'){
			entregar_filme();
		}
		else if(resp == '9'){
			excluir_filme();
		}
		else if(resp == '0'){
			break;
		}
		else{
			printf("Opção invalida...");
			scanf("%*c");
			//Limpar o buffer
			fseek(stdin, 0, SEEK_END);
			system(limpar_tela);
		}
	}

	return 0;
}

int existe_filme(FILE *arq_filmes, int id_filme){
	rewind(arq_filmes);

	t_filme filme;

	while(1){
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;
		if(filme.id == id_filme)
			return 1;
	}
	return 0;
}

void excluir_filme(){
	char str_id_filme[10];
	int id_filme;

	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);
	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_filme) == 1){
		sscanf(str_id_filme, "%d", &id_filme);

		FILE *arq_filmes = fopen("filmes.bin", "rb");

		if(arq_filmes == NULL){
			printf("|nFalha ao abrir o arquivo...\n");
			exit(1); //Aborta programa
		}
		if(existe_filme(arq_filmes, id_filme) == 1){
			char nome_filme[MAX];

			FILE *arq_temp = fopen("temp_filmes.bin", "a+b");
			if(arq_temp == NULL){
				printf("\nFalha ao criar arquivo temporario!\n");
				fclose(arq_filmes);
				exit(1); //Aborta o programa
			}
			rewind(arq_filmes);

			t_filme filme;
			while(1){
				size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
				if(result == 0)
					break;

				if(filme.id != id_filme){
					fwrite(&filme, sizeof(t_filme), 1, arq_temp);
				}
				else
					strcpy(nome_filme, filme.nome);
			}
			fclose(arq_filmes);
			fclose(arq_temp);

			if(remove("filmes.bin")!= 0)
				printf("\nErro ao deletar o arquivo \"filmes.bin\"\n");
			else{
				int r = rename("temp_filmes.bin", "filmes.bin");
				if(r != 0){
					printf("\nPermissao negada para renomear o arquivo!\n");
					printf("Feche esse programa e renomeie manualmente");
				}
				else
					printf("\nFimes \"%s\" removido com sucesso\n", nome_filme);

			}
		}
		else{
			fclose(arq_filmes);
			printf("\nNao existe filme com o ID %d\n", id_filme);
		}
	}
	else
		printf("\nO ID so pode conter numeros!\n");


	printf("Pressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}

void entregar_filme(){
	char str_id_filme[10];
	int id_filme;

	FILE *arq_filmes = fopen("filmes.bin", "rb+");

	if(arq_filmes == NULL){
		arq_filmes = fopen("filmes.bin", "wb+");
		if(arq_filmes == NULL){
			printf("|nFalha ao abrir o arquivo...\n");
			exit(1); //Aborta programa
		}
	}

	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);

	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_filme) == 1){
		sscanf(str_id_filme, "%d", &id_filme);

		t_filme *filme = obter_filme(arq_filmes, id_filme);

		if(filme != NULL){
			if(filme->id_cliente == 1){
				printf("\nO filme %s ja esta alugado!\n", filme->nome);
			}
			else{
				filme->id_cliente = -1;
				atualizar_filmes(arq_filmes, filme); // Atualiza o filme no arquivo
				printf("\nFilme %s entregue com sucesso...\n", filme->nome);
			}
			free(filme);
		}
		else
			printf("\nNao existe filme com o ID %d\n", id_filme);
	}
	else
		printf("\nO ID so pode conter numeros!\n");
	fclose(arq_filmes);
	printf("Pressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}

void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado){
	rewind(arq_filmes);

	t_filme filme;

	while(1){
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;
		if(filme.id == filme_alugado->id){
			//Posiciona o arquivo
			fseek(arq_filmes, - sizeof(t_filme), SEEK_END);
			//Atulaiza o filme
			fwrite(filme_alugado, sizeof(t_filme), 1, arq_filmes);
			//Sai do loop
			break;
		}
	}

}

t_filme *obter_filme(FILE *arq_filmes, int id_filme){
	rewind(arq_filmes);

	t_filme *filme;

	filme = (t_filme *)malloc(sizeof(t_filme));

	while(1){
		size_t result = fread(filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0)
			break;
		if(filme->id == id_filme)
			return filme;
	}
	free(filme);
	return NULL;
}

int existe_cliente(FILE *arq_clientes, int id_cliente){
	//Vai para o inicio do arquivo
	rewind(arq_clientes);

	t_cliente cliente;

	while(1){
		size_t result = fread(&cliente, sizeof(cliente), 1, arq_clientes);
		if(result == 0){
			break;
		}
		if(cliente.id == id_cliente);
			return 1;
	}
	return 0;
}

void alugar_filme(){
	char str_id_cliente[10];
	int id_cliente;

	FILE *arq_filmes = fopen("filmes.bin", "rb+");
	FILE *arq_clientes = fopen("clientes.bin", "rb+");

	if(arq_filmes == NULL){
		arq_filmes = fopen("filmes.bin", "wb+");
		if(arq_filmes == NULL){
			printf("|nFalha ao abrir o arquivo...\n");
			exit(1); //Aborta programa
		}
	}
	if(arq_clientes == NULL){
		arq_clientes = fopen("clientes.bin", "wb+");
		if(arq_clientes == NULL){
			printf("|nFalha ao abrir o arquivo...\n");
			exit(1); //Aborta programa
		}
	}

	printf("\nDigite o ID do cliente: ");
	scanf("%10s%*c", str_id_cliente);
	fseek(stdin, 0, SEEK_END);

	if(str_somente_numeros(str_id_cliente) == 1){
		sscanf(str_id_cliente, "%d", &id_cliente);
		//Verificad se id do cliente existe
		if(existe_cliente(arq_clientes, id_cliente)){
			char str_id_filme[10];
			int id_filme;

			printf("\nDigite o ID do filme: ");
			scanf("%10s%*c", str_id_filme);
			fseek(stdin, 0, SEEK_END);

			if(str_somente_numeros(str_id_filme) == 1){
				sscanf(str_id_filme, "%d", &id_filme);

				t_filme *filme = obter_filme(arq_filmes, id_filme);
				//Testa se o filme existe
				if(filme != NULL){
					//Testa se o filme esta alugado
					if(filme->id_cliente != -1)
						printf("\nO Filme %s ja esta alugado!\n", filme->nome);
					else{
						filme->id_cliente = id_cliente;
						atualizar_filmes(arq_filmes, filme);
						printf("\nFilme alugado com sucesso!\n", filme->nome);
					}
					free(filme);
				}
				else
					printf("\nNao existe filme com o ID %d\n", id_filme);
			}
			else
				printf("\nO ID so pode conter numeros!\n");
		}
		else
			printf("\nNão existe cliente com o ID %d\n", id_cliente);
	}
	else
		printf("\nO ID so pode conter numeros!\n");

	fclose(arq_clientes);
	fclose(arq_filmes);

	printf("Pressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}

void pesquisar_cliente(){
	char nome[MAX];
	int encontrou_cliente = 0;

	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_clientes == NULL){
		printf("|nFalha ao abrir o arquivo...\n");
		exit(1); //Aborta programa
	}
	printf("\nDigite o nome do Cliente: ");
	scanf("%99[^\n]%*c", nome);

	printf("\nCliente com nome \"%s\":\n\n",nome);

	t_cliente cliente;

	while(1){
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);

		if(result == 0){
			break;
		}
		char nome_aux[MAX];

		strcpy(nome_aux, cliente.nome);

		//if(strcmp(strupr(nome_aux), strupr(nome))== 0){ //Inplementacao original
			//Mostra dados do cliente
		  if(strstr(strupr(nome_aux), strupr(nome))){
			printf("ID do cliente: %d\n", cliente.id);
			printf("Nome: %s\n\n", cliente.nome);
			encontrou_cliente = 1;
		  }
		//}
	}
	if(encontrou_cliente == 0)
			printf("\nNenhum cliente encontrado...\n\n");

	fclose(arq_clientes);
	printf("Pressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);

}

void pesquisar_filme(){
	char nome[MAX];
	int encontrou_filme = 0;

	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_filmes == NULL){
		printf("|nFalha ao abrir o arquivo...\n");
		exit(1); //Aborta programa
	}
	printf("\nDigite o nome do filme: ");
	scanf("%99[^\n]%*c", nome);

	printf("\nFilmes com nome \"%s\":\n\n",nome);

	t_filme filme;

	while(1){

		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);

		if(result == 0){
			break;
		}
		char nome_aux[MAX];

		strcpy(nome_aux, filme.nome);

		if(strcmp(strupr(nome_aux), strupr(nome)) == 0)
		{
			printf("ID do filme: %d\n", filme.id);
			printf("Preco: R$ %.2lf\n", filme.preco);

			if(filme.id_cliente != -1)
			{
				if(arq_clientes == NULL)
				{
					printf("\nFalha ao abrir o arquivo!\n");
					fclose(arq_filmes);
					exit(1);
				}
				t_cliente *cliente = obter_cliente(arq_clientes, filme.id_cliente);

				printf("Alugado? SIM. Cliente: %s\n", cliente->nome);
				free(cliente);
			}
			else
				printf("Alugado? NAO\n");
			encontrou_filme = 1;
			printf("\n");
		}
	}
	if(encontrou_filme == 0)
		printf("\nNenhum filme encontrado...\n\n");

	fclose(arq_filmes);

	printf("Pressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}

void listar_clientes(){
	int encontrou_cliente = 0;
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_clientes == NULL){
		printf("\nFalha ao abrir o arquivo");
		printf("Pressione <ENTER> para continuar...");
		scanf("%*c");
		fseek(stdin, 0, SEEK_END);
		return;
	}

	t_cliente cliente;

	while(1){
		size_t result = fread(&cliente, sizeof(cliente), 1, arq_clientes);

		if(result == 0){
			break;
		}
		encontrou_cliente = 1;

		printf("\nID do cliente: %d", cliente.id);
		printf("\nNome do cliente: %s", cliente.nome);
	}

	if(encontrou_cliente == 0){
		printf("\nNenhum cliente cadastrado...");
	}
	fclose(arq_clientes);
	printf("\nPressione <ENTER> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);

}

t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente){

	rewind(arq_clientes);
	t_cliente *cliente;

	cliente = (t_cliente *)malloc(sizeof(t_cliente));

	while(1){
		size_t result = fread(cliente, sizeof(t_cliente), 1, arq_clientes);
		if(result == 0){
			free(cliente);
			return NULL;
		}
		if(cliente->id == id_cliente)
			break;
	}

	return cliente;
}

void listar_filmes(){
	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_filmes == NULL){
		printf("\nFalha ao abrir o arquivo ou nenhum filme cadastrado");
		printf("Pressione <ENTER> para continuar...");
		scanf("%*c");
		fseek(stdin, 0, SEEK_END);
		return;
	}
	int encontrou_filmes = 0;
	t_filme filme;
	while(1){
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
		if(result == 0){
			break;
		}
		encontrou_filmes = 1;
		printf("\nID do filme: %d\n", filme.id);
		printf("\nNome do filme: %s\n", filme.nome);
		printf("\nPreco R$: %.2f\n", filme.preco);

		//Se for diferente de menos -1, o filme esta alugado
		if(filme.id_cliente != -1){
			if(arq_clientes == NULL){
				printf("\nFalha ao abrir arquivo!\n");
				fclose(arq_filmes);
				exit(1);
			}
			t_cliente *cliente = obter_cliente(arq_clientes, filme.id_cliente);
			printf("Alugado? SIM. Cliente: %s\n", cliente->nome);
			free(cliente);
		}
		else
			printf("Alugado? NAO\n");

	}
	//Verifica se encontrou pelo menos um filme
	if(encontrou_filmes == 0){
		printf("\nNenhum filme cadastrado\n");
	}
	if(arq_filmes != NULL){
		fclose(arq_clientes);
	}

	fclose(arq_filmes);

	printf("\nPressione <ENTER> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);

}

char menu(){
	system(limpar_tela);
	system("title - Locadora de filmes");
	printf("------------------------------LOCADORA DE FILMES-------------------------------\n\n");
	char resp[2];
	printf(" 1 - Cadastrar filme\n");
	printf(" 2 - Cadastrar Cliente\n");
	printf(" 3 - Listar todos os filmes\n");
	printf(" 4 - Listar todos os cliente\n");
	printf(" 5 - Pesquisar filme\n");
	printf(" 6 - Pesquisar cliente\n");
	printf(" 7 - Alugar filme\n");
	printf(" 8 - Entregar filme\n");
	printf(" 9 - Excluir um filme\n");
	printf(" 0 - Sair\n");
	printf("-------------------------------------------------------------------------------");

	printf("\nDigite a opção.: ");
	scanf("%1s%*c", resp);

	fseek(stdin, 0, SEEK_END);

	return resp[0];
}

int str_somente_numeros(char str[]){
	int i = 0;
	int len_str = strlen(str);
	for(i = 0; i < len_str; i++){
		if(str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

void cadastrar_filme(){
	FILE *arq_filmes = fopen("filmes.bin", "a+b");
	if(arq_filmes == NULL){
		printf("\nFalha ao abrir o arquivo...");
		exit(1);
	}
	t_filme filme;

	int cont_bytes = 0;
	//Seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_filmes, 0, SEEK_END);
	//Guarda numero total de bytes
	cont_bytes = ftell(arq_filmes);
	if(cont_bytes == 0){
		filme.id = 1;
	}
	else{
		t_filme ultimo_filme;
		fseek(arq_filmes, cont_bytes - sizeof(t_filme), SEEK_SET);
		//Ler o filme
		fread(&ultimo_filme, sizeof(t_filme), 1, arq_filmes);
		filme.id = ultimo_filme.id + 1;
	}
	//Obter o nome do filme
	printf("\nDigite o nome do filme.: ");
	scanf("%99[^\n]%*c",filme.nome);
	fseek(stdin, 0, SEEK_END);
	do{
		char str_preco[5];
		float float_preco;
		int somente_numeros = 1;
		//Obtem o preço do filme
		printf("Digite o preco do filme.: R$ ");
		scanf("%4s%*c", str_preco);
		fseek(stdin, 0, SEEK_END);

		//Verifica se o preco possui somente numeros
		somente_numeros = str_somente_numeros(str_preco);
		if(somente_numeros == 1){
			int int_preco;
			//Exemplo: 49,10 deve digitar 4910
			sscanf(str_preco, "%d", &int_preco);
			float_preco = int_preco / 100.0;
			filme.preco = float_preco;
			break;
		}
	}while(1);
	//inicializa o id do cliente com -1 para indicar que o filme nao esta alugado
	filme.id_cliente = -1;
	fseek(arq_filmes, 0, SEEK_END);
	//escreve no arquivo
	fwrite(&filme, sizeof(t_filme), 1, arq_filmes);
	//fecha o arquivo
	fclose(arq_filmes);
	printf("\nFilme \"%s\" cadastrado com sucesso!\n", filme.nome);
	printf("\nPressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}

void cadastrar_cliente(){
	FILE *arq_clientes = fopen("clientes.bin", "a+b");

	if(arq_clientes == NULL){
		printf("\nFalha ao abrir o arquivo...");
		exit(1);
	}
	int cont_bytes = 0;
	fseek(arq_clientes, 0, SEEK_END);
	cont_bytes = ftell(arq_clientes);
	t_cliente cliente;
	if(cont_bytes == 0){
		cliente.id = 1;
	}
	else{
		t_cliente ultimo_cliente;
		fseek(arq_clientes, cont_bytes - sizeof(t_cliente), SEEK_SET);
		fread(&ultimo_cliente, sizeof(t_cliente), 1, arq_clientes);
		cliente.id = ultimo_cliente.id + 1;
	}
	printf("\nCliente.: ");
	scanf("%99[^\n]%*c", cliente.nome);

	fseek(stdin, 0, SEEK_END);
	//Se o ponteiro nao estiver no final do arquivo, nada é escrito
	fseek(arq_clientes, 0, SEEK_END);
	fwrite(&cliente, sizeof(t_cliente), 1, arq_clientes);
	fclose(arq_clientes);
	printf("\nCliente \"%s\" cadastrado com sucesso!\n", cliente.nome);
	printf("\nPressione <ENTER> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);
}






