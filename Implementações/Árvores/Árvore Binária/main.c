#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

int main() {
    /*
        Montagem da seguinte árvore:
            1
           / \
          2   3 
             / \
            4   5
    */
    struct NoArvore* raiz = novoNo(1);
    insereNaEsquerda(raiz, 2);
    insereNaDireita(raiz, 3);
    insereNaDireita(raiz->direita, 5);
    insereNaEsquerda(raiz->direita, 4);

    preOrdem(raiz);
    printf("\n");
    emOrdem(raiz);
    printf("\n");
    posOrdem(raiz);
    printf("\n");

    return 0;
}