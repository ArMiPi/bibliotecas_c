#ifndef LIST_H
#define LIST_H

#include<stdbool.h>

/*
    - Esse módulo tem por objetivo definir uma lista simplesmente encadeada
      bem como funções para manupulá-la

    - Todas as funções que tiverem list, element e/ou item como parâmetro de entrada presumem
      list != NULL && element != NULL && item != NULL
*/

typedef void* list;
typedef void* item;
typedef void* element;

/*
    # Saída:
        - list: Lista
    
    # Descrição:
        - Retorna um ponteiro para uma lista vazia
*/
list newList();

/*
    # Entrada:
        - l: Lista
    
    # Saída:
        - true
        - false
    
    # Descrição:
        - Retorna true se a l estiver vazia,
          false caso contrário
*/
bool isListEmpty(list l);

/*
    # Entradas:
        - lst: Lista
        - elem: Elemento
    
    # Saída:
        - item: Struct

    # Descrição:
        - Insere elem no início da lista

        - Retorna um ponteiro para o item que foi 
          inserido na lista
*/
item insertStart(list lst, element elem);

/*
    # Entradas:
        - lst: Lista
        - elem: Elemento
    
    # Saída:
        - item: Struct

    # Descrição:
        - Insere elem no final da lista

        - Retorna um ponteiro para o item que foi 
          inserido na lista
        
        - Se isListEmpty(lst) será executada a função
          insertStart()
*/
item insertEnd(list lst, element elem);

/*
    # Entradas:
        - lst: Lista
        - li: Item da lista
        - elem: Elemento
    
    # Saída:
        - item: Struct

    # Descrição:
        - Insere elem após o item li da lista

        - Retorna um ponteiro para o item que foi 
          inserido na lista
*/
item insertAfter(list lst, item li, element elem);

/*
    # Entradas:
        - lst: Lista
        - li: Item da lista
        - elem: Elemento
    
    # Saída:
        - item: Struct

    # Descrição:
        - Insere elem antes o item li da lista

        - Retorna um ponteiro para o item que foi 
          inserido na lista
*/
item insertBefore(list lst, item li, element elem);

/*
    # Entradas:
        - lst: Lista
        - li: Item
    
    # Saída:
        - element
    
    # Descrição:
        - Remove o item li da lista e retorna o
          elemento elem armazenado nesse item

        - Se a lista estiver vazia será retornado
          NULL
*/
element removeItem(list lst, item li);

/*
    # Entrada:
        - li: Item
    
    # Saída:
        - element
    
    # Descrição:
        - Retorna o elemento element 
          armazenado em li
*/
element getItemElement(item li);

/*
    # Entrada:
        - lst: Lista
    
    # Saída:
        - item: Struct
    
    # Descrição:
        - Retorna um ponteiro para o primeiro
          item da lista
        
        - Se a lista for vazia será retornado NULL
*/
item getFirstItem(list lst);

/*
    # Entrada:
        - lst: Lista
    
    # Saída:
        - item: Struct
    
    # Descrição:
        - Retorna um ponteiro para o último
          item da lista

        - Se a lista for vazia será retornado NULL
*/
item getLastItem(list lst);

/*
    # Entradas:
        - li: Item
    
    # Saída:
        - item
    
    # Descrição:
        - Retorna o próximo item da lista
*/
item getNextItem(item li);

/*
    # Entradas:
        - lst: Lista
        - destroyElement: Função
    
    # Descrição:
        - Libera toda a memória utilizada por l

        - Se destroyElement == NULL os elements de
          l não terão seus espaços de memória deslocados
*/
void destroyList(list lst, void (*destroyElement)());

#endif