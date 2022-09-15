/* 
    Enunciado:
        Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função
        que retorne a soma do dobro dos dois números lidos. A função deverá armazenar o dobro  
        de A na própria variável A e o dobro de B na própria variável B.
*/

#include <stdio.h>

// Protótipo de função
int dobraERetornaSoma(int *a, int *b);

int dobraERetornaSoma(int *a, int *b) {
    *a = 2 * *a;
    *b = 2 * *b;
    return *a + *b;
}

int main() {
    int a, b;
    printf("Insira a e b: ");
    
    scanf("%d %d", &a, &b);
    printf("Soma do dobro: %d\n", dobraERetornaSoma(&a, &b));
    printf("A e B depois da chamada da funcao:\n");
    printf("A> %d B> %d\n", a, b);
    return 0;
}