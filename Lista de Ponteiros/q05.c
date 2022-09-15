/*
    Enunciado: 
        Leia dois inteiros e chame uma função que recebe os dois valores de entrada
        e retorna o maior valor na primeira variável, o menor na segunda.
*/

#include <stdio.h>

// Protótipo de função
void swapIfBigger(int *a, int *b);

void swapIfBigger(int *a, int *b) {
    if (*a >= *b) {
        return;
    }
    int swap = *a;
    *a = *b;
    *b = swap;
}

int main() {
    int a, b;
    printf("Insira a e b: ");
    scanf("%d %d", &a, &b);
    swapIfBigger(&a, &b);
    printf("A e B depois da chamada da funcao:\n");
    printf("A> %d B> %d\n", a, b);
    return 0;
}