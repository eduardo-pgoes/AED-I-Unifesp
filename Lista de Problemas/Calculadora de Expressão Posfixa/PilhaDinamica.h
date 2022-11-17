#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noh.h"

typedef struct {
    TipoNoh *topo;
} TipoPilha;

void inicializaPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int empilha(TipoPilha*, int);
int desempilha(TipoPilha*);
int imprimePilha(TipoPilha*);