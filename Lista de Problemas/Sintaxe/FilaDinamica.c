#include "FilaDinamica.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila){
  char caracter;
  while(!filaVazia(fila))
    retiraDaFila(fila,&caracter);
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int insereNaFila(TipoFila *fila,char caracter){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    if(!filaVazia(fila)){
      fila->fim->prox = novoNoh;
    }
    else{
      fila->inicio = novoNoh;
    }
    fila->n++;
    novoNoh->caracter = caracter;
    novoNoh->prox = NULL;
    fila->fim = novoNoh;
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila, char *caracter){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    *caracter = ptrAux->caracter;
    if(fila->inicio==fila->fim){
      fila->inicio = NULL;
      fila->fim = NULL;
    }
    else{
      fila->inicio = ptrAux->prox;
    }
    free(ptrAux);
    fila->n--;
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    while(ptrAux!=NULL){
      printf("%c", (ptrAux->caracter));
      ptrAux = ptrAux->prox;
    }
    return 1;
  }
  return 0;
}