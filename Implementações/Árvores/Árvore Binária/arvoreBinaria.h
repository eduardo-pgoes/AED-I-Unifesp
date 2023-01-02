#pragma once


struct NoArvore {
    int dado;
    struct NoArvore *esquerda; 
    struct NoArvore *direita;
};

struct NoArvore* insereNaEsquerda(struct NoArvore*, int);
struct NoArvore* insereNaDireita(struct NoArvore*, int);
struct NoArvore* novoNo(int);
void emOrdem(struct NoArvore*);
void preOrdem(struct NoArvore*);
void posOrdem(struct NoArvore*);
void dealocaArvore(struct NoArvore*);