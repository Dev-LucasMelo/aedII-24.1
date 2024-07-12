#include <stdio.h>
#include <stdlib.h>

//Representação da estrutura do nó
typedef struct no {
    int chave;
    struct no *esq, *dir;
    int fb;
} no;

typedef no* arvore;

arvore inserir(arvore raiz, int chave, int *cresceu){
    //Caso Base
    if(raiz == NULL) {
        //Alocar memória
        arvore novo = (arvore) malloc(sizeof(struct no));
        //Inicializar Valores
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        *cresceu = 1;
        //retorno da raiz da subárvore modificada
        return novo;
    } else {
        if(chave > raiz->chave) {
            raiz->dir = inserir(raiz->dir, chave);
            //Atualizar fatores de balanço
            //1. Fator de balanço atual (raiz->fb)
            //2. Direita
            //3. raiz->dir cresceu ?

            if(*cresceu) {
                switch(raiz->fb) {
                    case -1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                    case 0:
                        raiz->fb = 1;
                        *cresceu = 1;
                        break;
                    case 1:
                        //rotacionar
                        return rotacionar(raiz);
                }
            }

        } else {
            raiz->esq = inserir(raiz->esq, chave);

            //verificação se a sub-árvore cresceu, considerando inserir na esquerda
        }
        return raiz;
    }

    //Caso recursivo





    return NULL;
}

arvore rotacionar(arvore raiz) {
    arvore p, u, v;
    p = raiz;

    //p - pivô
    if(p->fb > 0) {
        //rotação esquerda
        u=raiz->dir;
        if(u->fb >= 0){
            //caso fb(p, u) = [(+2, +1), (+2, 0)]
            if(u->fb == 1) {
                p->fb = 0;
                u->fb = 0;
            } else {
                p->fb = 1;
                u->fb = -1;
            }
            return rotacao_simples_esquerda(raiz);
        } else {
            v=u->esq;
            //fb(p,u,v) = [(+2,-1,0),(+2,-1,-1),(+2,-1, 1)]
            switch(v->fb) {
                case 0:
                    p->fb = 0;
                    u->fb = 0;
                    v->fb = 0;
                    break;
                case 1:
                    break;
                case -1:
                    break;
            }

           return rotacao_dupla_esquerda(raiz);
        }
    } else {
        //rotação direita
        if(raiz->esq->fb <= 0){
            return rotacao_simples_direita(raiz);
        } else {
           return rotacao_dupla_direita(raiz);
        }
    }

}

/*
      p (+2)
    /  \
  t1    u (+1, 0)
       / \
      t2  t3


      u
     / \
    p  t3
   / \
  t1  t2

*/
arvore rotacao_simples_esquerda(arvore raiz) {
    //Declarar e inicializar os ponteiros p, u, t1, t2, t3
    arvore p, u, t2;
    p = raiz;
    u = p->dir;
    t2 = u->esq;

    //Atualização de ponteiros
    u->esq = p;
    p->dir = t2;

    //Atualização da raiz relativa
    return u;
}

arvore rotacao_dupla_esquerda(arvore raiz) {
    return raiz;
}


int main(int argc, char* argv[]) {
    //declaração de uma variável do tipo árvore
    arvore arvore1;

    //inicialização da variável do tipo árvore
    arvore1 = NULL;

    exit(0);
}

