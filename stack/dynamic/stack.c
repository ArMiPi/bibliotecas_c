#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

typedef struct _stackItem {
    element elem;
    struct _stackItem *below;
}STACKITEM;

typedef struct _stack
{
    STACKITEM *top;
}STACK;

stack newStack() {
    STACK *stk = (STACK *) malloc(sizeof(STACK));
    if(stk == NULL) {
        printf("ERROR: Could not allocate memory for stack\n");
        exit(EXIT_FAILURE);
    }

    stk->top = NULL;

    return stk;
}

/*
    # Saída:
        - STACKITEM: Struct
    
    # Descrição:
        - Retorna um ponteiro para uma instância de STAKITEM contendo
          um item vazio
        
        - É necessário liberar a memória utilizada pelo retorno dessa função
*/
STACKITEM *newStackItem() {
    STACKITEM *stkI = (STACKITEM *) malloc(sizeof(STACKITEM));
    if(stkI == NULL) {
        printf("ERROR: Could not allocate memory for stack item\n");
        exit(EXIT_FAILURE);
    }

    stkI->elem = NULL;
    stkI->below = NULL;

    return stkI;
}

bool isStackEmpty(stack stk) {
    if(stk == NULL) return true;

    STACK *stkP = (STACK *) stk;

    return stkP->top == NULL;
}

void push(stack stk, element elem) {
    if(stk == NULL) return;

    STACK *stkP = (STACK *) stk;
    STACKITEM *stkI = newStackItem();

    // Definir elementos do novo item da pilha
    stkI->elem = elem;
    stkI->below = stkP->top;

    // Posicionar novo elemento no topo da pilha
    stkP->top = stkI;
}

element pop(stack stk) {
    if(stk == NULL) return NULL;

    if(isStackEmpty(stk)) {
        printf("WARNING: The stack is empty\n");
        return NULL;
    }

    // Definir ponteiros para pilha e para o elemento no topo da pilha
    STACK *stkP = (STACK *) stk;
    STACKITEM *top = stkP->top;

    // Ponteiro para elemento armazenado no item no topo da pilha
    element elem = top->elem;

    // Atualizar topo da pilha
    stkP->top = stkP->top->below;

    // "Desvincular" antigo elemento topo da pilha
    top->elem = NULL;
    top->below = NULL;

    // Liberar memória utilizada pelo antigo item do topo
    free(top);

    return elem;
}

element peekStack(stack stk) {
    if(stk == NULL) return NULL;

    if(isStackEmpty(stk)) {
        printf("WARNING: The stack is empty\n");
        return NULL;
    }

    STACK *stkP = (STACK *) stk;
    
    return stkP->top->elem;
}

void destroyStack(stack stk, void (*destroyElement)()) {
    if(stk == NULL) return;

    if(destroyElement != NULL)
        while(!isStackEmpty(stk))
            destroyElement(pop(stk));

    free(stk);
    stk = NULL;
}