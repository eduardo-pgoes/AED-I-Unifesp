#include "PilhaDinamica.h"

void inicializaPilha(TipoPilha *pilha){
    pilha->topo = NULL;
}

void destroiPilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      pilha->topo = ptrAux->prox;
      free(ptrAux);
      ptrAux = pilha->topo;
    }
  }
}

int pilhaVazia(TipoPilha *pilha){
  return pilha->topo==NULL;  
}

int empilha(TipoPilha *pilha, char caracter) {
    TipoNoh *novoNoh;
    novoNoh = (char*) malloc(sizeof(char));

    if (novoNoh == NULL) {
        return 0;
    }

    novoNoh->caracter = caracter;
    novoNoh->prox = pilha->topo;
    return 1;
}

int desempilha(TipoPilha *pilha, char *caracter) {
    TipoNoh *ptrAux;
    if (pilhaVazia(pilha)) {
        return 0;
    }
    ptrAux = pilha->topo;
    *caracter = ptrAux->caracter;
    pilha->topo = ptrAux->prox;
    free(ptrAux);
    return 1;
}

int imprimePilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      printf("%c", ptrAux->caracter);
      ptrAux = ptrAux->prox;
    }
    return 1;
  } 
  return 0;
}