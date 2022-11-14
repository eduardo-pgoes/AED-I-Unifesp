#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noh {
    char caracter;
    struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct {
    TipoNoh *topo;
} TipoPilha;

void inicializaPilha(TipoPilha*);
void destroiPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int empilha(TipoPilha*, char);
int desempilha(TipoPilha*, char*);
int imprimePilha(TipoPilha*);