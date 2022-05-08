#ifndef SORT_H
#define SORT_H

#include<stdio.h>

/*
    - Esse módulo tem por objetivo fornecer algumas funções para ordenação de vetores

    - Em todas as funções array != NULL && compare != NULL

    - Em todas as funções, compare deve retornar um valor maior que 0 se o primeiro valor na chamada
      da função for maior que o segundo para que a função ordene o vetor em ordem crescente

    - Métodos implementados:
        -> Selection Sort
        -> Bubble Sort
        -> Insertion Sort
        -> Shell Sort
        -> Quick Sort
        -> Heap Sort
*/

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Selection Sort
*/
void selection(void *array, size_t length, size_t size, int (*compare)(void *, void*));

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Bubble Sort
*/
void bubble(void *array, size_t length, size_t size, int (*compare)(void*, void*));

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Insertion Sort
*/
void insertion(void *array, size_t length, size_t size, int (*compare)(void*, void*));

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Shell Sort
*/
void shell(void *array, size_t length, size_t size, int (*compare)(void*, void*));

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Quick Sort
*/
void quick(void *array, size_t length, size_t size, int (*compare)(void*, void*));

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
    
    # Descrição:
        - Ordena array pelo método Heap Sort
*/
void heap(void *array, size_t length, size_t size, int (*compare)(void*, void*));

#endif