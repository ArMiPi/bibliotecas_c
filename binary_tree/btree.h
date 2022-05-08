#ifndef BTREE_H
#define BTREE_H

#include<stdbool.h>

/*
    - Esse módulo tem por objetivo definir uma árvore binária, bem como funções para
      criar e manipular essa árvore

    - Todas as funções que recebem btree, node e/ou element como parâmetros necessitam que
      btree != NULL && node != NULL && element != NULL
*/

typedef void* btree;
typedef void* node;
typedef void* element;

/*
    # Saída:
        - btree: Ponteiro para a árvore criada
    
    # Descrição:
        - Retorna uma árvore binária vazia
*/
btree newBinaryTree();

/*
    # Entrada:
        - tree: Árvore binária
    
    # Saída:
        - bool
    
    # Descrição:    
        - Retorna true caso tree esteja vazia,
          false caso contrário
*/
bool isBinaryTreeEmpty(btree tree);

/*
    # Entrada:
        - tree: Árvore binária
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Retorna um ponteiro para o nó de tree

        - Caso tree seja vazia, será retornado NULL
*/
node getBinaryTreeRoot(btree tree);

/*
    # Entradas:
        - tree: Árvore binária
        - elem: Elemento a ser armazenado
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Armazena elem na raíz de tree
        
        - tree deve ser vazia, caso contrário será
          retornado NULL
*/
node setBinaryTreeRoot(btree tree, element elem);

/*
    # Entrada:
        - nd: Nó de btree
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Retorna um ponteiro para o nó à
          esquerda de nd
        
        - Caso não exista um nó à esquerda de nd,
          será retornado NULL
*/
node getLeftNode(node nd);

/*
    # Entradas:
        - nd: Nó de btree
        - elem: Elemento a ser inserido
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Armazena elem à esquerda de nd

        - Caso já exista um elemento armazenado à
          esquerda de nd, elem não será armazenado
          e será retornado um ponteiro para o nó
          à esquerda já existente
*/
node setLeftNode(node nd, element elem);

/*
    # Entrada:
        - nd: Nó de btree
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Retorna um ponteiro para o nó à direita
          de nd

        - Caso não exista um nó à direita de nd, será
          retornado NULL
*/
node getRightNode(node nd);

/*
    # Entradas:
        - nd: Nó de btree
        - elem: Elemento a ser inserido
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Armazena elem à direita de nd

        - Caso já exista um elemento armazenado à
          direita de nd, elem não será armazenado
          e será retornado um ponteiro para o nó
          à direita já existente
*/
node setRightNode(node nd, element elem);

/*
    # Entrada:
        - nd: Nó de btree
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Retorna um ponteiro para o nó "pai"
          de nd

        - Caso não exista um nó "pai" de nd, será
          retornado NULL
*/
node getParentNode(node nd);

/*
    # Entrada:
        - nd: Nó de btree
    
    # Saída:
        - node: Ponteiro para nó de btree
    
    # Descrição:
        - Retorna um ponteiro para o nó "irmão"
          de nd

        - Caso não exista um nó "irmão" de nd, será
          retornado NULL
*/
node getSiblingNode(node nd);

/*
    # Entradas:
        - parent, child: Nós de btree
    
    # Saída:
        - bool
    
    # Descrição:
        - Retorna true se child for o "filho esquerdo"
          de parent, false caso contrário
*/
bool isLeftNode(node parent, node child);

/*
    # Entradas:
        - parent, child: Nós de btree
    
    # Saída:
        - bool
    
    # Descrição:
        - Retorna true se child for o "filho direito"
          de parent, false caso contrário
*/
bool isRightNode(node parent, node child);

/*
    # Entradas:
        - parent, child: Nós de btree
    
    # Saída:
        - bool
    
    # Descrição:
        - Retorna true se parent for o "pai"
          de child, false caso contrário
*/
bool isParentNode(node parent, node child);

/*
    # Entradas:
        - parent, child: Nós de btree
    
    # Saída:
        - bool
    
    # Descrição:
        - Retorna true se ancestor for "antecessor"
          de child, false caso contrário
*/
bool isAncestorNode(node ancestor, node child);

/*
    # Entrada:
        - nd: Nó de btree
    
    # Saída:
        - element
    
    # Descrição:
        - Retorna o elemento armazenado em nd
*/
element getNodeElement(node nd);

#endif