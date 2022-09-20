#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int n);

int negativos(float *vet, int n) {
    int negativos = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] < 0) {
            negativos++;
        }
    }
    return negativos;
}

int main() {
    int n;
    printf("Quantos numeros voce deseja inserir? ");
    scanf("%d", &n);
    float* arr = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        printf("Insira a float de índice %d: ", n);
        scanf("%f", &arr[i]);
    }

    printf("Numero de negativos na array: %d", negativos(arr, n));
    free(arr);
    return 0;
}