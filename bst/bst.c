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

bst remover(bst raiz, int valor){
    //procurar o elemento
    if(raiz == NULL)
        return NULL;

    if(raiz->chave == valor) {
        //Elemento encontrado ... lógica do remover
        //Caso 1: elemento não possui filhos
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        //Caso 2a: Exatamente um filho esquerdo
        if(raiz->esq != NULL && raiz->dir == NULL) {
            bst esq = raiz->esq;
            free(raiz);
            return esq;
        }

        //Caso 2b: Exatamente um filho direito

        //Caso 3: dois filhos
        if(raiz->esq != NULL && raiz->dir != NULL){
            int maior = maior_valor(raiz->esq);
            raiz->chave = maior;
            raiz->esq = remover(raiz->esq, maior);
            return raiz;
        }

    } else {
        if(valor > raiz->chave) {
            raiz->dir = remover(raiz->dir, valor);
        } else {
            raiz->esq = remover(raiz->esq, valor);
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
