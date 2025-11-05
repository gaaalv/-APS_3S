#include <stdio.h>
#include <stdlib.h>

int* carregar_dados(int qty, char* txt) {
	
	int* array_dados = (int *) malloc(qty * sizeof(int));
	
	char* nome_arquivo = txt;
	
	FILE *arquivo = fopen(nome_arquivo, "r");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo %s", nome_arquivo);
		return NULL;
	}
	
	char valor_puxado[20];
	
	int i = 0;
	while(fgets(valor_puxado, sizeof(valor_puxado), arquivo) != NULL) array_dados[i++] = atoi(valor_puxado);
	
	fclose(arquivo);
	
	return array_dados;
}

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

	int *teste;
	
	teste = carregar_dados(qty, nome_arquivo);
	
	for(int i = 0; i < qty; i++) {
		printf("%d\n", teste[i]);
	}
	
	return 0;
}
