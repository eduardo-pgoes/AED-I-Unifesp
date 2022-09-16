/*
    Enunciado:
        Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
        Imprima o endereço de cada posição dessa matriz.
*/

void imprimeEnderecos(int linhas, int colunas, float matriz[][]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d] = %f e esta alocada no endereco %p", i, j, matriz[i][j], (void *)&matriz[i][j]);
        }
    }
}