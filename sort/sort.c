#include<stdlib.h>
#include<stdbool.h>

#include"sort.h"

/*
    # Entradas: 
        - *a, *b: Elementos a serem trocados
        - size: Tamanho de cada elemento
    
    # Descrição:
        - Realiza a troca dos valores de a e b
*/
void swap(void *a, void *b, size_t size)
{
    unsigned char *p = a;
    unsigned char *q = b;
    unsigned char temp;

    for(int i = 0; i < size; i++) {
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

void selection(void *array, size_t length, size_t size, int (*compare)(void *, void *))
{
    if(array == NULL || compare == NULL) return;

    int menor;

    for(int i = 0; i < length - 1; i++) {
        menor = i;

        for(int j = i + 1; j < length; j++) {
            if(compare((array + (menor * size)), (array + (j * size)))) menor = j;
        }

        if(menor != i) swap((array + (i * size)), (array + (menor * size)), size);
    }
}

void bubble(void *array, size_t length, size_t size, int (*compare)(void *, void *))
{
    if(array == NULL || compare == NULL) return;

    bool swapped = true;
    int j = 1;
    void *aux;

    while(swapped) {
        swapped = false;

        for(int i = 0; i < (length - j); i++) {
            aux = array + (i * size);
            if(compare(aux, (aux + size))) {
                swap(aux, (aux + size), size);
                swapped = true;
            }
        }

        j++;
    }
}

void insertion(void *array, size_t length, size_t size, int (*compare)(void*, void*))
{
    if(array == NULL || compare == NULL) return;

    void *aux;

    for(int i = 0; i < length; i++) {
        aux = array + (i * size);
        for(int j = i; j > 0 && compare((aux - size), aux); j--, aux -= size) {
            swap(aux, (aux - size), size);
        }
    }
}

void shell(void *array, size_t length, size_t size, int (*compare)(void*, void*))
{
    if(array == NULL || compare == NULL) return;

    int gap;

    for(gap = 1; gap < length; gap = 3*gap + 1);
    gap = (gap - 1) / 3;

    while(gap > 0) {
        for(int i = gap; i < length; i++) {
            for(int j = i; j >= gap && compare((array + (j-gap)*size), (array + j*size)); j -= gap) {
                swap((array + (j-gap)*size), (array + j*size), size);
            }
        }

        gap = (gap - 1) / 3;
    }
}

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento
        - start: Posição inicial a ser considerada de array
        - end: Posição final a ser considerada de array
    
    # Descrição:
        - Executa o quick sort
*/
void qs(void *array, size_t size, int (*compare)(void*, void*), int start, int end)
{
    if((end - start) < 1) return;

    int i = start;
    void *auxEnd = array + (end * size);

    for(int j = start; j < end; j++) {
        if(compare(auxEnd, (array + (j * size)))) {
            swap((array + (i * size)), (array + (j * size)), size);
            i++;
        }
    }

    swap((array + (i * size)), auxEnd, size);

    qs(array, size, compare, start, i - 1);
    qs(array, size, compare, i + 1, end);
}

void quick(void *array, size_t length, size_t size, int (*compare)(void*, void*))
{
    if(array == NULL || compare == NULL) return;

    qs(array, size, compare, 0, length - 1);
}

/*
    # Entradas:
        - array: Vetor a ser ordenado
        - length: Quantidade de elementos do vetor
        - size: Tamanho de cada elemento do vetor
        - compare: Função para comparar cada elemento

    # Descrição:
        - Rearranja array para que se torne um max-heap,
          ou seja, uma "árvore" tal que os elementos "pais"
          sejam sempre maiores que seus "filhos" 
*/
void heapify(void *array, size_t end, size_t size, int (*compare)(void*, void*))
{
    int current, parent;
    for(int i = 0; i < end; i++) {
        current = i;
        parent = (i - 1) / 2;

        while(parent >= 0 && compare((array + (current * size)), (array + (parent * size)))) {
            swap((array + (current * size)), (array + (parent * size)), size);
            current = parent;
            parent = (parent - 1) / 2;
        }
    }
}

void heap(void *array, size_t length, size_t size, int (*compare)(void*, void*))
{
    if(array == NULL || compare == NULL) return;

    while(length > 1) {
        heapify(array, length, size, compare);
        swap(array, (array + ((length -1)* size)), size);
        length--;
    }
}
