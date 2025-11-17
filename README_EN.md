# 📊 APS: Sorting Algorithms Analysis

![Status](https://img.shields.io/badge/status-completed-green)

### 📖 Description

This project was developed for the Supervised Practical Activities (APS) discipline for the 3rd/4th semester of the Computer Science course at UNIP (Universidade Paulista). The objective is to create a system in **C Language** that compares the performance of different sorting algorithms when processing large volumes of data.

***

### 🛠️ What Was Done

To meet the requirements, the project was divided into two main programs:

1.  **Data Generator** ([`gerador.c`](./gerador.c))
    * A command-line utility that generates `.txt` files containing a specified amount of random integers.
    * **Usage:** `./gerador <quantity> <filename>`

2.  **Analysis System** ([`analise.c`](./analise.c))
    * The main program that performs the performance analysis.
    * **Usage:** `./analise <quantity> <filename>`
    * **What it does:**
        * Loads data from the specified file into three separate arrays in memory.
        * Executes a different sorting algorithm on each array.
        * Measures the execution time of each algorithm using a high-precision timer (`QueryPerformanceCounter` on Windows or `clock()` on other systems).
        * Displays a comparative summary of the times at the end.

***

### 📊 Compared Algorithms

Three sorting algorithms were implemented and analyzed, as required by the assignment:

* **Merge Sort:** An efficient "divide and conquer" algorithm.
* **Heap Sort:** An efficient comparison algorithm that uses the Max Heap data structure.
* **Counting Sort:** A linear-time (non-comparative) algorithm that is effective when the maximum value (`maxValue`) of the data is known and is not exorbitantly large.

> **Note:** The measurement time for Counting Sort includes the time required to find the `maxValue` of the array, as this is a mandatory prerequisite for the algorithm to function.

***

### 🚀 How to Compile and Run

The project was developed in C and compiled using **GCC**.

#### 1. Compilation
Open your terminal in the project folder and execute:

```bash
# 1. Compile the data generator
gcc gerador.c -o gerador -std=c11

# 2. Compile the analysis system
gcc analise.c -o analise -std=c11

```

#### 2. Execution
The workflow consists of generating a file and then analyzing it.

```bash
# Example with 10,000 elements

# 1. Generate the test file
./gerador 10000 data_10k.txt

# 2. Run the analysis on the generated file
./analise 10000 data_10k.txt

```

#### 3. Running the APS Files
For the official tests required by the assignment (up to 5 million elements):

```bash
# Generate the files
./gerador 500 data_500.txt
./gerador 5000 data_5k.txt
./gerador 50000 data_50k.txt
./gerador 500000 data_500k.txt
./gerador 5000000 data_5M.txt

# Analyze a large file
./analise 5000000 data_5M.txt

```

#### Output Example
When running the analysis program, the output will look similar to this:
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
