/*
    Enunciado:
        Crie um programa que contenha uma função que permita passar por parâmetro dois 
        numeros inteiros A e B. A função deverá calcular a soma entre estes dois número e  
        armazenar o resultado na variavel A. Esta função não deverá possuir retorno, mas deverá́
        modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função principal.
*/

#include <stdio.h>

/* Protótipo de função */
void somaEArmazenaEmA(int *a, int *b);

void somaEArmazenaEmA(int *a, int *b) {
    int soma = *a + *b;
    *a = soma;
}

int main() {
    int a, b;
    printf("Insira a e b: ");
    scanf("%d %d", &a, &b);
    somaEArmazenaEmA(&a, &b);
    printf("A e B depois da chamada da funcao:\n");
    printf("A> %d B> %d\n", a, b);
    return 0;
}