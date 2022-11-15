#include "Sequencia.h"
#include <math.h>

int verificaSequencia(Sequencia *sequencia, Par *pares, int numero_caracteres, int numero_pares) {
    printf("Mamae, to verificando as sequencias!\n");
    printf("Numero de caracteres a se considerar: %d\n", numero_caracteres);
    char esq, dir;
    for (int i = 0; i < ceil(numero_caracteres / 2); i++) {
        desempilha(&sequencia->caracteres_esquerda, &esq);
        retiraDaFila(&sequencia->caracteres_direita, &dir);
        if (getCaracterCorrespondente(pares, esq, numero_pares) == dir) {
            printf("BINGO!");
            // TO-DO: Verificar se isso funciona para sequências maiores...
        }
    }
    return 1;
}

void printaDireita(Sequencia *sequencia) {
    printf("Fila: ");
    imprimeFila(&sequencia->caracteres_direita);
}

void printaEsquerda(Sequencia *sequencia) {
    printf("Pilha: ");
    imprimePilha(&sequencia->caracteres_esquerda);
}

void inicializaSequencia(Sequencia *sequencia) {
    inicializaFila(&sequencia->caracteres_direita);
    inicializaPilha(&sequencia->caracteres_esquerda);
}