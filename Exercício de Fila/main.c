#include "FilaCorreios.h"
#include <time.h>
#include <stdlib.h>

void imprimeMenu();
void leDadosItem(TipoItem*, int*, int*);

int main(){
  srand(time(NULL));
  TipoFila fila;
  TipoItem item;
  int op = 0, i;
  int prioritario;
  int senhaPrioritaria = 0, senhaComum = 0;
  inicializaFila(&fila);

  while(op != 4){
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosItem(&item, &senhaPrioritaria, &senhaComum);
        if(insereNaFila(&fila,item))
          printf("\nItem inserido com sucesso!\n");
        else
          printf("\nErro! Nao foi possível inserir o item!\n");
        break;
      case 2:
        if(retiraDaFila(&fila,&item)){
          printf("\nItem retirado com sucesso!");
          imprimeItem(item);
        }
        else{
          printf("\nErro! Nao foi possível retirar da fila!\n");
        }
        break;
      case 3:
        if(!filaVazia(&fila)){
          printf("\nFila:\n");
          imprimeFila(&fila);
        }
        else{
          printf("\nFila Vazia!\n");
        }
        break;
      case 4:
        destroiFila(&fila);
        printf("\nAte logo!\n");
        break;
      default:
        break;
    }
  }

  return 0;
}

void imprimeMenu(){
  printf("\nMenu");
  printf("\n1 - Insere na fila");
  printf("\n2 - Retira da fila");
  printf("\n3 - Imprime fila");
  printf("\n4 - Sair");
}

void leDadosItem(TipoItem *item, int *senhaPrioritaria, int *senhaComum){
  int prioritario;
  printf("Sua senha eh prioritaria? 0 - Nao; 1 - Sim ");
  scanf("%d", &prioritario);
  if (prioritario) {
    *senhaPrioritaria += 1;
    item->senha = *senhaPrioritaria; 
  } else {
    *senhaComum += 1;
    item->senha = *senhaComum; 
  }
  item->prioritario = prioritario;
  imprimeItem(*item);
}