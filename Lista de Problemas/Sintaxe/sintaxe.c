#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDinamica.h"
#include "Par.h"
#include "Sequencia.h"

// 0 para não debugar, 1 para debugar.
#define FLAG_DEBUG 0

/*
    Protótipos de função
*/

/*
    Verifica se um dado índice pertence ou não a uma das "fatias" da sequência (isto é, subsequências)
    Flags:
        0 - não pertence
        1 - pertence
    Parâmetros:
        int - chave a ser considerada
        int* - lista com todos os indícies a fatiar
        int - número de fatias na lista
*/
int pertenceAFatia(int chave, int *fatias, int n);

/*
    Funções auxiliares
*/

int pertenceAFatia(int chave, int *fatias, int n) {
    for (int i = 0; i < n; i++) {
        if (chave == fatias[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int m, n; // m - pares de símbolos, n - sequência de caracteres
    scanf("%d %d", &m, &n);

    // Uma lista fixa de pares será importante na hora de criar as filas e pilhas 
    Par *pares = (Par*) malloc(sizeof(Par) * m);

    // Leitura de pares
    char esq, dir;
    for (int i = 0; i < m; i++) {
        scanf(" %c %c", &esq, &dir);
        pares[i].esquerda = esq;
        pares[i].direita = dir;
    }

    // Leitura da sequência de caracteres
    char *input = (char*) malloc(sizeof(char) * n); 
    char temp;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &temp);
        input[i] = temp;
    }

    /*
        SEÇÃO DE DEBUG PÓS LEITURA
    */
    if (FLAG_DEBUG) {
        printf("\nDEBUG DOS PARES\n");
        for (int i = 0; i < m; i++) {
            lePar(&pares[i]);
        }   
        printf("\n");
        printf("DEBUG DA SEQUENCIA\n");
        for (int i = 0; i < n; i++) {
            printf("%c", input[i]);
        }
        printf("\n");
        printf("\nDe volta para a rotina...\n");
    }

    // Separação do input em sequências (chamei de fatias para não confundir com a seq. de símbolos) de sintaxe
    int *indicesFatia = (int*) malloc(sizeof(int) * n);
    int numFatias = 0;
    for (int i = 1; i < n; i++) {
        // Se o antecessor é da esquerda e o sucessor é da direita, temos uma nova sequência sendo aberta... Fatia!
        if ((pertenceAPar(pares, input[i-1], m) == 1) && (pertenceAPar(pares, input[i], m) == 2)) {
            indicesFatia[numFatias] = i;
            numFatias++;
        }
    }

    // Lê cada sequência de fatias
    Sequencia *seq = (Sequencia*) malloc(sizeof(Sequencia));
    inicializaSequencia(seq);
    /* 
        A cada loop, essa flag vai zerar a sequência e o número de pares.
        Com isso, podemos considerar uma string enorme como sequências separadas!
        Dessa forma, exemplos como "(){{[]}}" não deveriam quebrar :)
    */ 
    int flagVerifica = 0;
    int n_pares = 0;
    
    for (int i = 0; i < n; i++) {
        // Reseta a sequência e verifica se tudo tá certo (até agora)...
        if (flagVerifica) {
            verificaSequencia(seq, pares, n_pares, m);
            flagVerifica = 0;
            n_pares = 0;
        }
        if (pertenceAPar(pares, input[i], m) == 1) {
            empilha(&seq->caracteres_esquerda, input[i]);
            n_pares++;
        } else if (pertenceAPar(pares, input[i], m) == 2) {
            insereNaFila(&seq->caracteres_direita, input[i]);
            n_pares++;
        }
        if (pertenceAFatia(i, indicesFatia, numFatias)) {
            flagVerifica = 1;
        }
    }

    TipoPilha esquerda; // Pilha que simboliza os caracteres da esquerda
    inicializaPilha(&esquerda);
}