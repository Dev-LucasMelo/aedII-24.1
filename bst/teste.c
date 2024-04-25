#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[]) {
    //declarar uma árvore
    bst arvore_1;
    int opcao;
    int valor;
    arvore_1 = NULL;
    while(1) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                scanf("%d", &valor);
                arvore_1 = inserir(arvore_1, valor);
                break;
            case 2:
                printf("%d\n", quantidadeElementos(arvore_1));
                break;
            case 3:
                preorder(arvore_1);
                printf("\n");
                break;
            case 99:
                exit(0);
        }
    }
}
