#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

/*
  Flags - 
  0 - comum;
  1 - preferencial.
*/
typedef struct{
  int senha;
  int prioritario;
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
int filaVazia(TipoFila*);
int filaCheia(TipoFila*);
int insereNaFila(TipoFila*,TipoItem);
int retiraDaFila(TipoFila*,TipoItem*);
int imprimeFila(TipoFila*);
void imprimeItem(TipoItem);