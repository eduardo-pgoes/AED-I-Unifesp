#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noh.h"

#define MAX 1000

typedef struct{
  int n;
  TipoNoh *inicio;
  TipoNoh *fim;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
int filaVazia(TipoFila*);
int insereNaFila(TipoFila*,char);
int retiraDaFila(TipoFila*,char*);
int imprimeFila(TipoFila*);

#endif /* FILADINAMICA_H */