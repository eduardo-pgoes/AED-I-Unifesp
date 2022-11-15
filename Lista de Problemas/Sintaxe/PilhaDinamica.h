#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noh.h"

typedef struct {
    TipoNoh *topo;
} TipoPilha;

void inicializaPilha(TipoPilha*);
void destroiPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int empilha(TipoPilha*, char);
int desempilha(TipoPilha*, char*);
int imprimePilha(TipoPilha*);

#endif /* PILHADINAMICA_H */