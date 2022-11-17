#include "Sequencia.h"
#include <math.h>

int verificaSequencia(Sequencia *sequencia, Par *pares, int numero_caracteres, int numero_pares) {
    char esq, dir;
    // Se o n. de caracteres é ímpar, obviamente tem algum par que não foi fechado
    if ((numero_caracteres) % 2 != 0) {
        return -2;
    }

    for (int i = 0; i < ceil(numero_caracteres / 2); i++) {
        desempilha(&sequencia->caracteres_esquerda, &esq);
        retiraDaFila(&sequencia->caracteres_direita, &dir);
        // Verifica se o caracter da direita é correspondente ao da esquerda.
        if (getCaracterCorrespondente(pares, esq, numero_pares) != dir) {
            // Se não for, o caracter da direita é inesperado/inválido!
            return -1;
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