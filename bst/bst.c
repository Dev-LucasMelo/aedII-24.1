#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int quantidadeElementos(bst raiz) {
    //Caso base - árvore vazia
    if(raiz == NULL) {
        return 0;
    } else {
        //casos recursivos
        return 1 
               + quantidadeElementos(raiz->esq)
               + quantidadeElementos(raiz->dir);
  
    }    
}

bst inserir(bst raiz, int valor) {
    //caso base - árvore vazia
    if(raiz == NULL) {
        //criar o nó - alocação dinâmica de memória
        bst novo;
        novo = (bst) malloc(sizeof(no));
        //inicializar
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if(valor > raiz->chave) {
            raiz->dir = inserir(raiz->dir, valor);
        } else {
            raiz->esq = inserir(raiz->esq, valor);
        }
        return raiz;
    }
}

void preorder(bst raiz) {
    //Caso base implícito na negativa
    if(raiz != NULL) {
        printf("[%d]", raiz->chave);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}
