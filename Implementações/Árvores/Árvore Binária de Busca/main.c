#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaBusca.h"

int main() {
    int n;
    printf("Quantos numeros voce deseja inserir na arvore de busca? ");
    scanf("%d", &n);
    struct NoArvore *raiz = NULL;

    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        raiz = insere(raiz, data);
    }

    preOrdem(raiz);
    printf("\n");
    emOrdem(raiz);
    printf("\n");
    posOrdem(raiz);
    printf("\n");
}