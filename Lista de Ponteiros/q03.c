/*
    Enunciado:
        Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do 
        teclado. Em seguida, compare seus endereços e exiba o conteudo do maior endereço.
*/

#include <stdio.h>

int main() {
    int a, b;
    printf("Insira a e b:");
    scanf("%d %d", &a, &b);
    (&a > &b) ? printf("O maior endereco eh %p\n", (void*) &a) : printf("O maior endereco eh %p\n", (void*) &b);
    return 0;
}