#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDinamica.h"

// 0 para não debugar, 1 para debugar.
#define FLAG_DEBUG 0

/*
    PROTÓTIPOS DE FUNÇÃO
*/

/* 
    Inicializa uma torre de Hanoi com n discos, jogando todos na torre inicial.
    Parâmetros:
        TipoPilha* - array de pilhas (0 - torre de origem, 1 - torre auxiliar, 2 - torre destino)
        int - número de discos
    Retornos:
        1 - sucesso
        0 - não foi possível inicializar a torre
*/
int inicializaTorre(TipoPilha*, int);

/*
    Move um disco de lugar na torre.
    Parâmetros:
        TipoPilha* - array de pilhas (0 - torre de origem, 1 - torre auxiliar, 2 - torre destino)
        int - torre de origem
        int - torre de saída
    Retornos:
        1 - sucesso
        0 - não foi possível mover o disco
*/
int moveDisco(TipoPilha*, int, int);

/*
    Imprime uma torre.
    Parâmetros:
        TipoPilha* - array de pilhas (0 - torre de origem, 1 - torre auxiliar, 2 - torre destino)
*/
void imprimeTorre(TipoPilha*);

/*
    Verifica se a torre está resolvida
    Parâmetros:
        TipoPilha* - array de pilhas (0 - torre de origem, 1 - torre auxiliar, 2 - torre destino)
        int - número de discos
    Retornos:
        1 - Resolvida
        0 - Solução pendente
*/
int verificaSolucao(TipoPilha*, int);

/*
    Retorna o número de discos de uma torre.
    Parâmetros:
        TipoPilha* - ponteiro para uma única torre/pilha
*/
int getNumeroDeDiscos(TipoPilha*);

/*
    IMPLEMENTAÇÕES DE FUNÇÃO
*/

int inicializaTorre(TipoPilha* torres, int n) {
    // Empilha n discos na primeira torre
    for (int i = 0; i < n; i++) {
        if (!empilha(&torres[0])) {
            return 0;
        }
    }
    return 1;
}

void imprimeTorre(TipoPilha* torres) {
    for (int i = 0; i < 3; i++) {
        printf("\nTorre indice %d: ", i+1);
        imprimePilha(&torres[i]);
    }
}

int moveDisco(TipoPilha* torres, int origem, int destino) {
    // Não se pode mover um disco de um lugar para o mesmo lugar
    if (origem == destino) {
        return 0;
    }

    // Origem e destino não podem estar out-of-bounds
    if ((origem > 3) || (destino > 3)) {
        return 0;
    }


    empilha(&torres[destino-1]);
    // Só dá pra desempilhar torres que tenham, no mínimo, um disco...
    if (pilhaVazia(&torres[origem-1])) {
        return 0;
    } else {
        desempilha(&torres[origem-1]);
    }

    // Verificando o estado das torres após cada movimento
    if (FLAG_DEBUG) {
        printf("\n");
        printf("Estado das torres apos fazer o movimento %d -> %d: ", origem, destino);
        imprimeTorre(torres);
        printf("\n");
    }

    return 1;
}

int getNumeroDeDiscos(TipoPilha *pilha) {
	return pilha->n;
}

int verificaSolucao(TipoPilha* torres, int n) {
    if (!pilhaVazia(&torres[0])) {
        return 0;
    }
    if (!pilhaVazia(&torres[1])) {
        return 0;
    }

    return getNumeroDeDiscos(&torres[2]) == n;
}

int main() {
    int n, m; // n - n. de discos, m - n. de movimentos
    scanf("%d %d", &n, &m);

    TipoPilha *torres = (TipoPilha*) malloc(sizeof(TipoPilha) * 3); // Representam as 3 torres de Hanoi

    // Inicializa as três pilhas
    for (int i = 0; i < 3; i++) {
        inicializaPilha(&torres[i]);
    }

    inicializaTorre(torres, n);

    int origem, destino, resultadoMovimento;
    // Lê os movimentos e vai movendo os discos, um a um
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &origem, &destino);
        resultadoMovimento = moveDisco(torres, origem, destino);
        if (!resultadoMovimento) {
            printf("Wrong move");
            return 0;
        }
    }

    // Verifica o resultado :)
    if (verificaSolucao(torres, n)) {
        printf("Solved");
    } else {
        printf("Unfinished");
    }

    return 0;
}