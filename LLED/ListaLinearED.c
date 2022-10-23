#include "ListaLinearED.h"

int listaVaziaLLED(ListaLinearED *lista){
  return lista->ultimo==0;
}

void inicializaListaLLED(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}

void imprimeListaLLED(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL){
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

int insereNoFinalLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int insereNoInicioLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoInicioLLED(ListaLinearED* lista,TipoItem* item){
  TipoNoh *ptrAux;

  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    lista->inicioLista = ptrAux->prox;
    *item = ptrAux->item;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}

int localizaItemLLED(ListaLinearED *lista,int info,TipoItem *item, int *pos){
  TipoNoh *ptrAux;
  int cont = 1;

  ptrAux = lista->inicioLista;
  if(ptrAux!=NULL){
    while(ptrAux!=NULL){
      if(verificaItemIgual(ptrAux->item,info)){
        *item = ptrAux->item;
        *pos = cont;
        return 1;
      }
      ptrAux = ptrAux->prox;
      cont++;
    }
  }
  return 0;
}

int verificaItemIgual(TipoItem item, int info){
  if(item.RA == info)
    return 1;
  return 0;
}

int removeDaPosicaoLLED(ListaLinearED* lista, int pos) {
  TipoNoh *ptrAux, *ptrAux2;
  int cont = 1;
  ptrAux = lista->inicioLista;
  
  /* Chega na posição pedida */
  if (ptrAux != NULL) {
    while (ptrAux != NULL && cont != pos) {
      ptrAux = ptrAux->prox;
      cont++;
    }
  }

  /* Pega o item ATRÁS do removido */
  cont = 1;
  ptrAux2 = lista->inicioLista;
  if (ptrAux2 != NULL) {
    while (ptrAux2 != NULL && cont != pos - 1) {
      ptrAux2 = ptrAux2->prox;
      cont++;
    }
  }

  ptrAux2->prox = ptrAux->prox;
  free(ptrAux);
  lista->ultimo--;
  imprimeItemLLED(ptrAux2->item);
}

int adicionaNaPosicaoLLED(ListaLinearED* lista, TipoItem item, int pos) {
  TipoNoh *ptrAux, *ptrAux2;
  int cont = 1;
  ptrAux = lista->inicioLista;
  
  /* Chega na posição pedida */
  if (ptrAux != NULL) {
    while (ptrAux != NULL && cont != pos - 1) {
      ptrAux = ptrAux->prox;
      cont++;
    }
  }

  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  
  novoNoh->item = item;
  novoNoh->prox = ptrAux->prox;

  ptrAux->prox = novoNoh;

  lista->ultimo++;

  return 1;
}