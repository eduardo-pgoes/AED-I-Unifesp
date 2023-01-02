#pragma once


struct NoArvore {
    int dado;
    struct NoArvore *esquerda; 
    struct NoArvore *direita;
};

struct NoArvore* insere(struct NoArvore*, int);
struct NoArvore* novoNo(int);
void emOrdem(struct NoArvore*);
void preOrdem(struct NoArvore*);
void posOrdem(struct NoArvore*);
void dealocaArvore(struct NoArvore*);