#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	if(argc != 3) {
		printf("Quantidade de argumentos insuficiente!\n");
		printf("Uso Correto: %s	<quantidade> <nome_do_arquivo>", argv[0]);
		return 1;
	}
		
	int qty = atoi(argv[1]);
	char* nome_arquivo = argv[2];
	
	if (qty <= 0) {
		printf("A quantidade nao pode ser igual/inferior a 0!\n");
		return 1;
	}
	
	FILE *arquivo = fopen(nome_arquivo, "w+");
	
	if(arquivo == NULL){
		printf("Erro ao criar o arquivo solicitado!\n");
		return 1;
	}
	

	srand(time(NULL));

	for(int i = 0; i < qty; i++) {
		int dado_aleatorio = rand();
		fprintf(arquivo, "%d\n", dado_aleatorio);
	}
		
	fclose(arquivo);
	
	printf("Arquivo %s gerado com %d valores!\n", nome_arquivo, qty);
}
