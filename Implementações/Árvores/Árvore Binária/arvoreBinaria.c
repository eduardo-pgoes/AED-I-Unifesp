#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

struct NoArvore* insereNaEsquerda(struct NoArvore *raiz, int dado) {
    if (raiz == NULL) {
        return novoNo(dado);
    }

    struct NoArvore* temp = novoNo(dado);
    raiz->esquerda = temp;

    return raiz;
}

struct NoArvore* insereNaDireita(struct NoArvore *raiz, int dado) {
    if (raiz == NULL) {
        return novoNo(dado);
    }

    struct NoArvore* temp = novoNo(dado);
    raiz->direita = temp;

    return raiz;
}

struct NoArvore* novoNo(int dado) {
    struct NoArvore *temp = malloc(sizeof *temp);

    temp->dado = dado;
    temp->esquerda = NULL;
    temp->direita = NULL;

    return temp;
}

void emOrdem(struct NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }
    
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emOrdem(raiz->direita);
}

void posOrdem(struct NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    } 

    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->dado);
}

void preOrdem(struct NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->dado);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void dealocaArvore(struct NoArvore *raiz) {
    if (raiz == NULL) return;
    dealocaArvore(raiz->esquerda);
    dealocaArvore(raiz->direita);
    free(raiz);
}