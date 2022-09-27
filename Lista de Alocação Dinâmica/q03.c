#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int m, int n) {
    int **matriz = (int **) malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *) malloc(sizeof(int) * n);
    }
    return matriz;
}

void imprimeMatriz(int **mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    } 
}

void livraMatriz(int **mat, int m) {
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    int m, n;
    printf("Insira o numero de linhas: ");
    scanf("%d", &m);
    printf("Insira o numero de colunas: ");
    scanf("%d", &n);
    int **mat = alocaMatriz(m, n);
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = ++count;
        }
    }
    imprimeMatriz(mat, m, n);
    livraMatriz(mat, m);
    imprimeMatriz(mat, m, n);
}