/*
    Enunciado:
        Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e  
        exiba o maior endereço.
*/

#include <stdio.h>

int main() {
    int a = 5;
    int b = 6;
    (&a > &b) ? printf("O maior endereco eh %p\n", (void*) &a) : printf("O maior endereco eh %p\n", (void*) &b);
    return 0;
}