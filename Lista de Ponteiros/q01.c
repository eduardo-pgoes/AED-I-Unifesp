/*
    Enunciado: 
        Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in-
        teiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
        cada variavel usando os ponteiros. Imprima os valores das variáveis antes e após a
        modificação.
*/

#include <stdio.h>

int main() {
    int inteiro = 10;
    double real = 5.25;
    char caracter = 'c';
    int *ponteiroInteiro = &inteiro;
    double *ponteiroReal = &real;
    char *ponteiroCaracter = &caracter;
    printf("Antes da modificacao:\n");
    printf("%d\n", inteiro);
    printf("%f\n", real);
    printf("%c\n", caracter);
    *ponteiroCaracter = 'f';
    *ponteiroReal = 500;
    *ponteiroInteiro = 1914;
    printf("Depois da modificacao:\n");
    printf("%d\n", inteiro);
    printf("%f\n", real);
    printf("%c\n", caracter);
    return 0;
}