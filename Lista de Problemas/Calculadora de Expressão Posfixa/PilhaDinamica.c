#include "PilhaDinamica.h"

void inicializaPilha(TipoPilha *pilha){
    pilha->topo = NULL;
}

int pilhaVazia(TipoPilha *pilha){
  return pilha->topo==NULL;  
}

int empilha(TipoPilha *pilha, int valor) {
    TipoNoh *novoNoh;
    novoNoh = (TipoNoh*) malloc(sizeof(char));

    if (novoNoh == NULL) {
        return 0;
    }

    novoNoh->valor = valor;
    novoNoh->prox = pilha->topo;
    pilha->topo = novoNoh;
    return 1;
}

int desempilha(TipoPilha *pilha) {
    TipoNoh *ptrAux;
    int valor;
    if (pilhaVazia(pilha)) {
        return 0;
    }
    ptrAux = pilha->topo;
    valor = ptrAux->valor;
    pilha->topo = ptrAux->prox;
    free(ptrAux);
    return valor;
}

int imprimePilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      printf("%d ", (ptrAux->valor));
      ptrAux = ptrAux->prox;
    }
    printf("\n");
    return 1;
  } 
  return 0;
}