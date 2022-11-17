#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noh.h"

typedef struct {
    TipoNoh *topo;
    int n;
} TipoPilha;

void inicializaPilha(TipoPilha*);
void destroiPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int empilha(TipoPilha*);
int desempilha(TipoPilha*);
int imprimePilha(TipoPilha*);

#endif /* PILHADINAMICA_H */