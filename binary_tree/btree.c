#include<stdio.h>
#include<stdlib.h>

#include"btree.h"

typedef struct _btree
{
    int size;
    node root;
}BTREE;

typedef struct _node
{
    struct _node* parent;
    element *elem;
    struct _node* left;
    struct _node* right;
}NODE;

btree newBinaryTree()
{
    BTREE *tree = (BTREE *) malloc(sizeof(BTREE));
    if(tree == NULL) {
        printf("ERROR: Could not allocate memory for tree  (**newBinaryTree**)\n");
        exit(EXIT_FAILURE);
    }

    tree->root = NULL;
    tree->size = 0;

    return tree;
}

bool isBinaryTreeEmpty(btree tree)
{
    if(tree == NULL) return true;

    BTREE *binTree = (BTREE *) tree;

    return binTree->root == NULL;
}

node getBinaryTreeRoot(btree tree)
{
    if(tree == NULL) return NULL;

    BTREE *binTree = (BTREE *) tree;

    return binTree->root;
}

node newNode(element elem)
{
    if(elem == NULL) return NULL;

    NODE *nd = (NODE *) malloc(sizeof(NODE));
    if(nd == NULL) {
        printf("ERROR: Could not allocate memory for new node  (**newNode**)\n");
        exit(EXIT_FAILURE);
    }

    nd->parent = NULL;
    nd->elem = elem;
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

node setBinaryTreeRoot(btree tree, element elem)
{
    if(tree == NULL || elem == NULL) return NULL;

    if(!isBinaryTreeEmpty(tree)) {
        printf("WARNING: Tree already have a root  (**setBinaryTreeRoot**)\n");
        return NULL;
    }

    BTREE *binTree = (BTREE *) tree;

    NODE *nd = newNode(elem);

    binTree->root = nd;

    return nd;
}

node getLeftNode(node nd)
{
    if(nd == NULL) return NULL;

    NODE *no = (NODE *) nd;

    return no->left;
}

node setLeftNode(node nd, element elem)
{
    if(nd == NULL || elem == NULL) return NULL;

    if(getLeftNode(nd) != NULL) return getLeftNode(nd);

    NODE *no = (NODE *) nd;

    NODE *left = newNode(elem);

    left->parent = no;
    no->left = left;

    return left;
}

node getRightNode(node nd)
{
    if(nd == NULL) return NULL;

    NODE *no = (NODE *) nd;

    return no->right;
}

node setRightNode(node nd, element elem)
{
    if(nd == NULL || elem == NULL) return NULL;

    if(getRightNode(nd) != NULL) return getRightNode(nd);

    NODE *no = (NODE *) nd;
    NODE *right = newNode(elem);

    right->parent = no;
    no->right = right;

    return right;
}

node getParentNode(node nd)
{
    if(nd == NULL) return NULL;

    NODE *no = (NODE *) nd;

    return no->parent;
}

node getSiblingNode(node nd)
{
    if(nd == NULL) return NULL;

    NODE *parent = getParentNode(nd);

    if(isLeftNode(parent, nd)) return getRightNode(parent);
    return getLeftNode(parent);
}

bool isLeftNode(node parent, node child)
{
    if(parent == NULL || child == NULL) return false;

    return getLeftNode(parent) == child;
}

bool isRightNode(node parent, node child)
{
    if(parent == NULL || child == NULL) return false;

    return getRightNode(parent) == child;
}

bool isParentNode(node parent, node child)
{
    if(parent == NULL || child == NULL) return false;

    return getParentNode(child) == parent;
}

bool isAncestorNode(node ancestor, node child)
{
    if(ancestor == NULL || child == NULL) return false;

    node parent = getParentNode(child);
    while(parent != NULL) {
        if(parent == ancestor) return true;

        parent = getParentNode(parent);
    }

    return false;
}

element getNodeElement(node nd)
{
    if(nd == NULL) return NULL;

    NODE *no = (NODE *) nd;

    return no->elem;
}
