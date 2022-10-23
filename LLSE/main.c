#include "ListaLinearSE.h"
#include <stdio.h>

void imprimeMenu() {
    printf("O que voce deseja fazer?\n");
    printf("1 - Inserir aluno no inicio da lista;\n");
    printf("2 - Inserir no final da lista;\n");
    printf("3 - Inserir aluno na posicao;\n");
    printf("4 - Remover aluno do final da lista;\n");
    printf("5 - Remover aluno do inicio da lista;\n");
    printf("6 - Remover aluno por chave do item;\n");
    printf("7 - Remover aluno por RA;\n");
    printf("8 - Ler estado atual da lista;\n");
    printf("-1 - Sair. ");
}

void leDadosAluno(TipoItem *aluno) {
    printf("Insira RA: ");
    scanf("%d", &aluno->RA);
    printf("Insira nome: ");
    scanf("%s", &aluno->nome);
    printf("Insira frequencia: ");
    scanf("%d", &aluno->freq);
    for (int i = 0; i < 3; i++) {
        printf("Insira nota na P%d: ", i+1);
        scanf("%f", &aluno->notas[i]);
    }
}

int main() {
    int opcao = 0, pos, ra;
    ListaLinearSE lista;
    TipoItem item;
    inicializaLLSE(&lista);
    while (opcao != -1) {
        imprimeMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\n");
                leDadosAluno(&item);
                if (insereNoInicioLLSE(&lista, item)) {
                    printf("Aluno inserido com sucesso!\n\n");
                }
                break;
            case 2:
                printf("\n");
                leDadosAluno(&item);
                if (insereNoFinalLLSE(&lista, item)) {
                    printf("Aluno inserido com sucesso!\n\n");
                }
                break;
            case 3:
                printf("\n");
                printf("Em que posicao voce deseja inserir o aluno? ");
                scanf("%d", &pos);
                leDadosAluno(&item);
                if (insereNaPosicaoLLSE(&lista, item, pos)) {
                    printf("Aluno inserido com sucesso!\n\n");
                }
                break;
            case 4:
                printf("\n");
                if (removeDoFinalLLSE(&lista, &item)) {
                    printf("Aluno removido com sucesso!\n\n");
                    imprimeItemLLED(item);
                }
                break;
            case 5:
                printf("\n");
                if (removeDoInicioLLSE(&lista, &item)) {
                    printf("Aluno removido com sucesso!\n\n");
                    imprimeItemLLED(item);
                }
                break;
            case 6:
                printf("\n");
                printf("De qual posicao voce deseja tirar o item? ");
                scanf("%d", &pos);
                if (removeDaPosicaoLLSE(&lista, &item, pos)) {
                    printf("Aluno removido com sucesso!\n\n");
                    imprimeItemLLED(item);
                }
                break;
            case 7:
                printf("\n");
                printf("Qual eh o RA do aluno que voce deseja remover? ");
                scanf("%d", &ra);
                int flag = removeEspecificoLLSE(&lista, &item, ra);
                if (flag == 1) {
                    printf("Aluno removido com sucesso!\n\n");
                    imprimeItemLLED(item);
                } else if (flag == -1) {
                    printf("RA nao encontrado!!\n\n");
                }
                break;
            case 8:
                printf("\n");
                imprimeListaLLSE(&lista);
            case -1:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}