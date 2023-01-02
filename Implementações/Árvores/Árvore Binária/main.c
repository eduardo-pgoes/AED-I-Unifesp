#include <stdio.h>
#include <stdlib.h>

#pragma region NoArvore

/* Tree function prototypes*/
struct NoArvore* insereNaEsquerda(struct NoArvore*, int);
struct NoArvore* insereNaDireita(struct NoArvore*, int);
struct NoArvore* novoNo(int);
void emOrdem(struct NoArvore*);
void preOrdem(struct NoArvore*);
void posOrdem(struct NoArvore*);
void dealocaArvore(struct NoArvore*);

struct NoArvore {
    int dado;
    struct NoArvore *esquerda; 
    struct NoArvore *direita;
};

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

#pragma endregion NoArvore

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