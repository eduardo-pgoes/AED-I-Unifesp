/*
    Enunciado:
        Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
        2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas  
        variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B terá o valor de A.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

int main() {
    int a, b;
    printf("Insira a e b: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Pos inversao:\n");
    printf("a = %d, b = %d\n", a, b);
    return 0;
}