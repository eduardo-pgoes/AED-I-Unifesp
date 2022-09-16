/*
    Enunciado:
        Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
        endereço de cada posição desse array.
*/  

#include <stdio.h>

void imprimeEnderecos(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Endereco no indice %d: %p\n", i, (void *)&arr[i]);
    }
}

int main() {
    float arr[10] = {0.25, 0.10, 0.05, 1.25, 1.70, 1.25, 1.60, 1.80, 9.00, 10.00};
    imprimeEnderecos(arr, 10); 
    return 0;
}