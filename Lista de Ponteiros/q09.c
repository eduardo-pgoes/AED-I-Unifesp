/*
    Enunciado:
        Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
        Imprima o endereço de cada posição dessa matriz.
*/

#include <stdio.h>

void imprimeEnderecos(float mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz[%d][%d] = %f e esta alocada no endereco %p\n", i, j, mat[i][j], (void *)&mat[i][j]);
        }
    }
}

int main() {
    float mat[3][3] = {
        {5.00, 6.00, 7.00},
        {1.00, 2.00, 3.00},
        {4.00, 8.00, 9.00}
    };
    imprimeEnderecos(mat);
    return 0;
}