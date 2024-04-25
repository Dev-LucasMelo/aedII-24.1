#ifndef BST_H
#define BST_H

//Definição da estrutura de um nó

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
//Uma árvore é um ponbteiro para um nó
typedef no * bst;

int quantidadeElementos(bst raiz);
bst inserir(bst raiz, int valor);
void preorder(bst raiz);
bst remover(bst raiz, int valor);

#endif
