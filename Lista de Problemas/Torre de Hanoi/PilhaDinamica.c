#include "PilhaDinamica.h"

void inicializaPilha(TipoPilha *pilha){
    pilha->topo = NULL;
    pilha->n = 0;
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
	return pilha->n==0;  
}

int empilha(TipoPilha *pilha) {
    TipoNoh *novoNoh;
    novoNoh = (TipoNoh*) malloc(sizeof(char));

    if (novoNoh == NULL) {
        return 0;
    }
    pilha->n++;
	novoNoh->indice = pilha->n;
    novoNoh->prox = pilha->topo;
    pilha->topo = novoNoh;
	
	return 1;
}

// Não precisamos saber o número do disco na implementação da Pilha para a torre de Hanoi :)
int desempilha(TipoPilha *pilha) {
    TipoNoh *ptrAux;
    if (pilhaVazia(pilha)) {
        return 0;
    }
    ptrAux = pilha->topo;
    pilha->topo = ptrAux->prox;
	pilha->n--;
    free(ptrAux);
    return 1;
}


int imprimePilha(TipoPilha *pilha){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha->topo;
    while(ptrAux!=NULL){
      printf("%d ", (ptrAux->indice));
      ptrAux = ptrAux->prox;
    }
    return 1;
  } 
  return 0;
}