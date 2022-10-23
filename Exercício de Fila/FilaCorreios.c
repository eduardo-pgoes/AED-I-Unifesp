#include "FilaCorreios.h"
#include <time.h>
#include <stdlib.h>

void inicializaFila(TipoFila *fila){
  fila->ultimo = -1;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila))
    retiraDaFila(fila,&item);
}

int filaVazia(TipoFila *fila){
  return fila->ultimo==-1;
}

int filaCheia(TipoFila *fila){
  return fila->ultimo==MAX-1;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  if(!filaCheia(fila)){
    fila->ultimo++;
    fila->itens[fila->ultimo] = item;
    return 1;
  }
  return 0;
}

int indicePrimeiroPrioritario(TipoFila *fila) {
  int res = -1;
  for (int i = 0; i <= fila->ultimo; i++) { 
    if (fila->itens[i].prioritario) {
      res = i;
      break;
    }
  }
  return res;
}

int indicePrimeiroComum(TipoFila *fila) {
  int res = -1;
  for (int i = 0; i <= fila->ultimo; i++) { 
    if (fila->itens[i].prioritario == 0) {
      res = i;
      break;
    }
  }
  return res;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  int i;
  int resto = rand() % 10;
  int conseguiRemover = -1;
  if(!filaVazia(fila)){
    if (resto < 7) {
      printf("Devo tirar um prioritario, necessariamente.");
      int indice = indicePrimeiroPrioritario(fila);
      if (indice != -1) {
        // remove a primeira senha prioritária
        *item = fila->itens[indice];
        for (i = indice+1; i <= fila->ultimo; i++) {
            fila->itens[i-1] = fila->itens[i];
        }
        fila->ultimo--;
        conseguiRemover = 1;
        return 1;
      }
    } else {
      printf("Devo tirar um comum, necessariamente.");
      int indice = indicePrimeiroComum(fila);
      if (indice != -1) {
        // remove a primeira senha comum
        *item = fila->itens[indice];
        for (i = indice+1; i <= fila->ultimo; i++) {
            fila->itens[i-1] = fila->itens[i];
        }
        fila->ultimo--;
        conseguiRemover = 1;
        return 1;
      } 
    }
    if (!conseguiRemover) {
      // remove qualquer coisa, não achei o que queria.
      *item = fila->itens[0];
        for (i = 1; i <= fila->ultimo; i++) {
            fila->itens[i-1] = fila->itens[i];
        }
      fila->ultimo--;
      return 1;
    }
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  int i;
  if(!filaVazia(fila)){
    for(i=0;i<=fila->ultimo;i++){
      imprimeItem(fila->itens[i]);
    }
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  if (item.prioritario) {
    printf("Sua senha eh P | %04d\n", item.senha);
  } else {
    printf("Sua senha eh N | %04d\n", item.senha);
  }
}