#include<stdio.h>
#include<stdlib.h>

#include"list.h"

typedef struct _listItem {
    element elem;
    struct _listItem *next;
}LISTITEM;

typedef struct _list {
    LISTITEM *head;
}LIST;

/*
    # Saída:
        - LISTITEM*: Struct
    
    # Descrição:
        - Retorna um ponteiro para um novo item
          vazio de lista
*/
LISTITEM *newListItem() {
    LISTITEM *li = (LISTITEM *) malloc(sizeof(LISTITEM));
    if(li == NULL) {
        printf("ERROR: Could not allocate memory for new list item\n");
        exit(EXIT_FAILURE);
    }

    li->elem = NULL;
    li->next = NULL;

    return li;
}

list newList() {
    LIST *l = (LIST *) malloc(sizeof(LIST));
    if(l == NULL) {
        printf("ERROR: Could not allocate memory for new list\n");
        exit(EXIT_FAILURE);
    }

    l->head = NULL;

    return l;
}

bool isListEmpty(list lst) {
    if(lst == NULL) return true;

    LIST *l = (LIST *) lst;

    return l->head == NULL;
}

item insertStart(list lst, element elem) {
    if(lst == NULL || elem == NULL) return NULL;

    // Criação do item
    LISTITEM *li = newListItem();
    li->elem = elem;
    
    LIST *l = (LIST *) lst;

    // Definir ponteiro do item
    li->next = l->head;

    // Posicionar o item na lista
    l->head = li;

    return li;
}

item insertEnd(list lst, element elem) {
    if(lst == NULL || elem == NULL) return NULL;

    if(isListEmpty(lst)) return insertStart(lst, elem);

    // Criar item
    LISTITEM *li = newListItem();
    li->elem = elem;

    // Posicionar o item na lista
    LISTITEM *lit = getLastItem(lst);
    lit->next = li;

    return li;
}

item insertAfter(list lst, item li, element elem) {
    if(lst == NULL || li == NULL || elem == NULL) return NULL;

    if(getLastItem(lst) == li) return insertEnd(lst, elem);

    // Criar item
    LISTITEM *newLi = newListItem();
    newLi->elem = elem;

    // Posicionar elemento na lista
    LISTITEM *lit = (LISTITEM *) li;
    newLi->next = lit->next;
    lit->next = newLi;

    return newLi;
}

item insertBefore(list lst, item li, element elem) {
    if(lst == NULL || li == NULL || elem == NULL) return NULL;

    if(getFirstItem(lst) == li) return insertStart(lst, elem);

    // Criar item
    LISTITEM *newLi = newListItem();
    newLi->elem = elem;
    newLi->next = li;

    // Encontrar item anterior ao item li
    LISTITEM *prev = getFirstItem(lst);
    while(prev->next != li) prev = prev->next;

    // Posicionar elemento na lista
    prev->next = newLi;

    return newLi;
}

element removeItem(list lst, item li) {
    if(lst == NULL || li == NULL) return NULL;

    LIST *l = (LIST *) lst;
    LISTITEM *lit = (LISTITEM *) li;

    if(getFirstItem(lst) == li) {
        l->head = l->head->next;

        element elem = lit->elem;
        lit->elem = NULL;
        lit->next = NULL;

        free(lit);

        return elem;
    }

    // Encontrar elemento que deve ser removido
    LISTITEM *prev = getFirstItem(lst);
    while(prev->next != li) prev = prev->next;

    // Armazenar elemento do item a ser removido
    LISTITEM *rmv = prev->next;
    element elem = rmv->elem;

    // Acertar ponteiros
    prev->next = rmv->next;
    rmv->elem = NULL;
    rmv->next = NULL;

    free(rmv);

    return elem;
}

element getItemElement(item li) {
    if(li == NULL) return NULL;

    LISTITEM *lit = (LISTITEM *) li;

    return lit->elem;
}

item getFirstItem(list lst) {
    if(lst == NULL) return NULL;

    LIST *l = (LIST *) lst;

    return l->head;
}

item getLastItem(list lst) {
    if(lst == NULL) return NULL;

    if(isListEmpty(lst)) return NULL;

    LISTITEM *li = getFirstItem(lst);
    while(li->next != NULL) li = li->next;

    return li;
}

item getNextItem(item li) {
    if(li == NULL) return NULL;

    LISTITEM *lit = (LISTITEM *) li;

    return lit->next;
}

void destroyList(list lst, void (*destroyElement)()) {
    if(lst == NULL) return;

    if(destroyElement != NULL)
        while(!isListEmpty(lst))
            destroyElement(removeItem(lst, getFirstItem(lst)));
    free(lst);
    lst = NULL;
}