#ifndef SEQUENCIA_H
#define SEQUENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"
#include "Par.h"

typedef struct {
    TipoPilha caracteres_esquerda;
    TipoFila caracteres_direita;
} Sequencia;

/* 
    Verifica se uma sequência de caracteres está devidamente fechada de acordo com as regras de sintaxe.
    Parâmetros:
        Sequência* - sequência a se considerar/ver se está correta
        Par* - lista (array criada com malloc) de pares de símbolos a considerar como válidos na sequência
        int - número de caracteres que devem constar na sequência
        int - número de pares na lista de pares
    Retornos:
        1 - sequência correta
        -1 - Símbolo direito não esperado
        -2 - Símbolo da esquerda não esperado
*/
int verificaSequencia(Sequencia*, Par*, int, int);

/*
    Imprime todos os caracteres da esquerda presentes na sequência
*/
void printaEsquerda(Sequencia*);

/*
    Imprime todos os caracteres da direita presentes na sequência
*/
void printaDireita(Sequencia*);

/*
    Inicializa a pilha da esquerda e a fila da direita, a serem consideradas na sequência
*/
void inicializaSequencia(Sequencia*);

#endif /* SEQUENCIA_H */