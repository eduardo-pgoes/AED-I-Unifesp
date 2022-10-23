#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearED.h"

void imprimeMenu();
void leDadosAluno(TipoItem*);
void imprimeDadosAluno(TipoItem);

int main(){
  ListaLinearED listaAlunosAED;
  TipoItem item;
  int n, i, op = 0;
  int RA, pos;

  inicializaListaLLED(&listaAlunosAED);

  while(op != 5){
    imprimeMenu();
    printf("Opcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosAluno(&item);
        if(insereNoFinalLLED(&listaAlunosAED,item)){
          printf("\nAluno inserido com sucesso.\n");
        }
        break;
      case 2:
        printf("\nRA a ser retirado: ");
        scanf("%i",&RA);
        if(localizaItemLLED(&listaAlunosAED,RA,&item,&pos)){
          printf("\nDados do aluno:");
          imprimeDadosAluno(item);
          removeDaPosicaoLLED(&listaAlunosAED,pos);
        }
        else
          printf("\nAluno nao encontrado.\n");
        break;
      case 3:
        if(!listaVaziaLLED(&listaAlunosAED)){
          printf("\nAlunos:\n");
          imprimeListaLLED(&listaAlunosAED);
        }
        else
          printf("\nNao ha alunos matriculados.\n");
        break;
      case 4:
        printf("\nRA a ser buscado: ");
        scanf("%i",&RA);
        if(localizaItemLLED(&listaAlunosAED,RA,&item,&pos)){
          printf("\nDados do aluno:");
          imprimeDadosAluno(item);
        }
        else
          printf("\nAluno nao encontrado.\n");
        break;
      case 5:
        destroiListaLLED(&listaAlunosAED);
        break;
      case 6:
        printf("\nPosicao a inserir: ");
        scanf("%d", &RA);
        leDadosAluno(&item);
        if (adicionaNaPosicaoLLED(&listaAlunosAED, item, RA)) {
          printf("\nAluno adicionado com sucesso.\n");
        }
      default:
        printf("\nOpcao incorreta!\n");
        break;
    }
  }
  
  return 0;
}

void imprimeMenu(){
  printf("\nMenu:\n");
  printf("1 - Inserir aluno.\n");
  printf("2 - Retirar aluno.\n");
  printf("3 - Listar alunos.\n");
  printf("4 - Buscar pelo RA.\n");
  printf("5 - Sair.\n");
  printf("6 - Inserir o aluno na posicao n.\n");
}

void leDadosAluno(TipoItem *item){
  int i;
  printf("\nRA: ");
  scanf("%i",&item->RA);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&item->notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&item->freq);
}

void imprimeDadosAluno(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}

