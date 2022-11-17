/*
    Enunciado>
        Diremos que uma expressão posfixa simples é uma cadeia de caracteres (= string) de comprimento ≤ 99 cujos 
        caracteres pertencem ao conjunto  '+', '*', '0', '1', . . . , '9'  (o caracter ' ' não faz parte do conjunto). 
        Uma expressão posfixa simples representa uma expressão aritmética da maneira usual. 
        Por exemplo,  "123*+"  representa a expressão  1 + (2*3) ,  cujo valor é  7.  
        Note que cada caracter numérico representa um número entre 0 e 9;  
        assim, a sequência "23" representa o número 2 seguido do número 3, e não o número 23. 
        Escreva uma função que receba uma expressão posfixa simples e 
        devolva o valor da correspondente expressão aritmética.
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaDinamica.h"

#define FLAG_DEBUG 1

int calculaExpressaoPosfixa(char expressao[], int n_caracteres) {
    TipoPilha pilha;
    inicializaPilha(&pilha);

    int num_atual;
    for (int i = 0; i < n_caracteres; i++) {
        if (expressao[i] >= '0' && expressao[i] <= '9') {
            num_atual = expressao[i] - '0';
            empilha(&pilha, num_atual);
        } else {
            if (expressao[i] == '+') {
                empilha(&pilha, (desempilha(&pilha) + desempilha(&pilha)));
            } else if (expressao[i] == '*') {
                empilha(&pilha, (desempilha(&pilha) * desempilha(&pilha)));
            }
        }
    }
    return desempilha(&pilha);
}

int main() {
    char exp[5] = "123*+";
    printf("%d", calculaExpressaoPosfixa(exp, 5));
    return 0;
}