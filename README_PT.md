# 📊 APS: Análise de Algoritmos de Ordenação

![Status](https://img.shields.io/badge/status-concluído-green)

### 📖 Descrição

Este é um projeto desenvolvido para a disciplina de Atividades Práticas Supervisionadas (APS) do 3º/4º semestre do curso de Ciência da Computação da UNIP (Universidade Paulista). O objetivo é criar um sistema em Linguagem C que compara a performance de diferentes algoritmos de ordenação ao processar grandes volumes de dados.

***

### 🛠️ O que foi feito

Para atender aos requisitos, o projeto foi dividido em dois programas principais:

1.  **Gerador de Dados** ([`gerador.c`](./gerador.c))
    * Um utilitário de linha de comando que gera arquivos `.txt` com a quantidade especificada de números inteiros aleatórios.
    * **Uso:** `./gerador <quantidade> <nome_do_arquivo>`

2.  **Sistema de Análise** ([`analise.c`](./analise.c))
    * O programa principal que realiza a análise de performance.
    * **Uso:** `./analise <quantidade> <nome_do_arquivo>`
    * **O que ele faz:**
        * Carrega os dados do arquivo especificado em três arrays separados na memória.
        * Executa um algoritmo de ordenação diferente em cada array.
        * Mede o tempo de execução de cada algoritmo usando um cronômetro de alta precisão (o `QueryPerformanceCounter` no Windows ou `clock()` em outros sistemas).
        * Exibe um resumo comparativo dos tempos no final.

***

### 📊 Algoritmos Comparados

Foram implementados e analisados três algoritmos de ordenação, como exigido pelo trabalho:

* **Merge Sort:** Um algoritmo eficiente do tipo "dividir para conquistar".
* **Heap Sort:** Um algoritmo de comparação eficiente que usa a estrutura de dados Max Heap.
* **Counting Sort:** Um algoritmo de tempo linear (não-comparativo) que é eficaz quando o valor máximo (`maxValue`) dos dados é conhecido e não é exorbitantemente grande.

> **Nota:** O tempo de medição do Counting Sort inclui o tempo necessário para encontrar o `maxValue` do array, pois este é um pré-requisito obrigatório para o funcionamento do algoritmo.

***

### 🚀 Como Compilar e Executar

O projeto foi desenvolvido em C e compilado com **GCC**.

#### 1. Compilação
Abra o terminal na pasta do projeto e execute:

```bash
# 1. Compile o gerador de dados
gcc gerador.c -o gerador -std=c11

# 2. Compile o sistema de análise
gcc analise.c -o analise -std=c11

```

#### 2. Execução
O fluxo de trabalho é gerar um arquivo e depois analisá-lo.

```bash
# Exemplo com 10.000 elementos

# 1. Gere o arquivo de teste
./gerador 10000 dados_10k.txt

# 2. Execute a análise no arquivo gerado
./analise 10000 dados_10k.txt

```

#### 3. Execução dos arquivos da APS
Para os testes oficiais do trabalho (até 5 milhões de elementos):

```bash
# Gerar os arquivos
./gerador 500 dados_500.txt
./gerador 5000 dados_5k.txt
./gerador 50000 dados_50k.txt
./gerador 500000 dados_500k.txt
./gerador 5000000 dados_5M.txt

# Analisar um arquivo grande
./analise 5000000 dados_5M.txt

```

#### Exemplo de saída
Ao executar o programa de análise, a saída será semelhante a esta:

```bash
$ ./analise 10000 dados_10k.txt

Carregando dados para 3 arrays (total de 10000 elementos)...
Dados carregados com sucesso.

Iniciando Merge Sort para 10000 elementos...
Tempo do Merge Sort: 0.001523400 segundos

Iniciando Heap Sort para 10000 elementos...
Tempo do Heap Sort: 0.001987600 segundos

Iniciando Counting Sort para 10000 elementos...
(Pode falhar aqui ou demorar muito devido à alocação de memória)
Tempo do Counting Sort: 2.345678900 segundos

=======================================
--- Resumo da Analise ---
Arquivo: dados_10k.txt (10000 elementos)
---------------------------------------
Merge Sort:     0.001523400 s
Heap Sort:      0.001987600 s
Counting Sort:  2.345678900 s
=======================================

Liberando memoria...
Concluido.

```

