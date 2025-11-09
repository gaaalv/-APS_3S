#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

	//validação para receber o número correto de parâmetros, <nome do exe> <quantidade> <nome_arquivo>.
	if(argc != 3) {
		printf("Quantidade de argumentos insuficiente!\n");
		printf("Uso Correto: %s	<quantidade> <nome_do_arquivo>", argv[0]);
		return 1;
	}

	int qty = atoi(argv[1]);
	char* nome_arquivo = argv[2];

	//validação quantidade > 0.
	if (qty <= 0) {
		printf("A quantidade nao pode ser igual/inferior a 0!\n");
		return 1;
	}
	
	FILE *arquivo = fopen(nome_arquivo, "w+");

	//validação caso arquivo não seja encontrado, caso não seja limpar memória.
	if(arquivo == NULL){
		printf("Erro ao criar o arquivo solicitado!\n");
		return 1;
	}
	

	srand(time(NULL));

	//loop para inserir dados aleatorios no arquivo sendo gerado
	for(int i = 0; i < qty; i++) {
		int dado_aleatorio = rand();
		fprintf(arquivo, "%d\n", dado_aleatorio);
	}
		
	fclose(arquivo);
	
	printf("Arquivo %s gerado com %d valores!\n", nome_arquivo, qty);
}
