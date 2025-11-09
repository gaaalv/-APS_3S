#include <stdio.h>
#include <stdlib.h>

/*o bloco de código abaixo se trata de uma compilação condicional onde se o código estiver sendo compilado
numa máquina WINDOWS, ele realizará a primeira parte (o include da biblioteca windows.h), agora senão estiver
realizará a segunda.*/
#ifdef _WIN32
	#include <windows.h>
#else
	#include <time.h>
#endif

//function feita para abrir o arquivo com os parametros solicitados, criar um array para comportar os dados desse arquivo, e retornar esse array.
int* carregar_dados(int qty, char* txt) {
	
	int* array_dados = (int *) malloc(qty * sizeof(int));
	
	char* nome_arquivo = txt;
	
	FILE *arquivo = fopen(nome_arquivo, "r");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo %s", nome_arquivo);
		free(array_dados);
		return NULL;
	}
	
	char valor_puxado[20];
	
	int i = 0;
	while(fgets(valor_puxado, sizeof(valor_puxado), arquivo) != NULL) {
		if (i < qty) array_dados[i++] = atoi(valor_puxado); //atoi para converter as Strings do arquivo em int.
		else break;
	}
	
	fclose(arquivo);
	
	return array_dados;
}

//function com a ordenação CoutingSort.
void countingSort(int arr[], int n, int maxValue) {
    int *count = NULL;
    int *output = NULL;
    int i;

    count = (int *) calloc((maxValue + 1), sizeof(int));
    output = (int *) malloc(n * sizeof(int));
    if (!count || !output) {
        if (count) free(count);
        if (output) free(output);
        return;
    }

    for (i = 0; i < n; i++) count[arr[i]]++;

    for (i = 1; i <= maxValue; i++) count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++) arr[i] = output[i];

    free(count);
    free(output);
}

//functions com a ordenação HeapSort.
void heapify(int arr[], int n, int i) {
    int largest, l, r, temp;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

//functions com a ordenação MergeSort.
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1, n2;
    int *L = NULL;
    int *R = NULL;

    n1 = m - l + 1;
    n2 = r - m;

    L = (int *) malloc(n1 * sizeof(int));
    R = (int *) malloc(n2 * sizeof(int));
    if (!L || !R) {
        if (L) free(L);
        if (R) free(R);
        return;
    }

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//functions para conseguir calcular o tempo de execução de cada algoritmo de ordenação.
double tempo_mergeSort(int arr[], int n) {
    printf("Iniciando Merge Sort para %d elementos...\n", n);
    double tempo_total;

    #ifdef _WIN32
        LARGE_INTEGER freq, inicio, fim;
        QueryPerformanceFrequency(&freq); //utilizamos QueryPerformanceFrequency() para uma medição de alta precisão importando a biblioteca windows.h.
        QueryPerformanceCounter(&inicio);
    #else
        clock_t inicio = clock(); //caso o programa esteja sendo compilado em outro sistema operacional usa se a biblioteca.h, onde clock() não possui tanta precisão.
    #endif

    mergeSort(arr, 0, n - 1); // <-- Ação

    #ifdef _WIN32
        QueryPerformanceCounter(&fim);
        tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / (double)freq.QuadPart;
    #else
        clock_t fim = clock();
        tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    #endif

    printf("Tempo do Merge Sort: %.9f segundos\n\n", tempo_total);
    return tempo_total;
}

double tempo_heapSort(int arr[], int n) {
    printf("Iniciando Heap Sort para %d elementos...\n", n);
    double tempo_total;

    #ifdef _WIN32
        LARGE_INTEGER freq, inicio, fim;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&inicio);
    #else
        clock_t inicio = clock();
    #endif

    heapSort(arr, n); // <-- Ação

    #ifdef _WIN32
        QueryPerformanceCounter(&fim);
        tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / (double)freq.QuadPart;
    #else
        clock_t fim = clock();
        tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    #endif
    
    printf("Tempo do Heap Sort: %.9f segundos\n\n", tempo_total);
    return tempo_total;
}

double tempo_countingSort(int arr[], int n) {
    printf("Iniciando Counting Sort para %d elementos...\n", n);
    double tempo_total;

    #ifdef _WIN32
        LARGE_INTEGER freq, inicio, fim;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&inicio);
    #else
        clock_t inicio = clock();
    #endif
    
    // --- Ação (find maxValue + sort) ---
    printf("Calculando maxValue...\n");
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    printf("maxValue encontrado: %d\n", maxValue);
    countingSort(arr, n, maxValue);
    // --- Fim da Ação ---

    #ifdef _WIN32
        QueryPerformanceCounter(&fim);
        tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / (double)freq.QuadPart;
    #else
        clock_t fim = clock();
        tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    #endif

    printf("Tempo do Counting Sort: %.9f segundos\n\n", tempo_total);
    return tempo_total;
}

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

	printf("Carregando dados para 3 arrays (total de %d elementos)...\n", qty);
	
	//os três arrays que serão ordenados.
	int *teste_merge;
	int *teste_heap;
	int *teste_counting;
	
	teste_merge = carregar_dados(qty, nome_arquivo);
	teste_heap = carregar_dados(qty, nome_arquivo);
	teste_counting = carregar_dados(qty, nome_arquivo);
	
	
	//validação caso arquivo não seja encontrado, caso não seja limpar memória.
	if(teste_counting == NULL || teste_heap == NULL || teste_merge == NULL){
		printf("Erro fatal ao ler o arquivo ou alocar memoria! Encerrando.\n");

        if(teste_merge) free(teste_merge);	
        if(teste_heap) free(teste_heap);
        if(teste_counting) free(teste_counting);
		return 1;
	}
	
	printf("Dados carregados com sucesso.\n\n");

	//variavel para receber o tempo de execução de cada algoritmo de ordenação.
    double tempo_m = tempo_mergeSort(teste_merge, qty);
    double tempo_h = tempo_heapSort(teste_heap, qty);
    double tempo_c = tempo_countingSort(teste_counting, qty);


    printf("=======================================\n");
    printf("--- Resumo da Analise ---\n");
    printf("Arquivo: %s (%d elementos)\n", nome_arquivo, qty);
    printf("---------------------------------------\n");
    printf("Merge Sort: \t%.9f s\n", tempo_m);
    printf("Heap Sort: \t%.9f s\n", tempo_h);
    printf("Counting Sort: \t%.9f s\n", tempo_c);
    printf("=======================================\n");
	
	printf("\nLiberando memoria...\n");
	free(teste_counting);
	free(teste_heap);
	free(teste_merge);
	
	printf("Concluido.\n");
	printf("----------------------------------------\n");
	return 0;
}
