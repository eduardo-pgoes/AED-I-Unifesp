#include <stdio.h>
#include <math.h>

void frac(float num, int* inteiro, float* frac);

void frac(float num, int* inteiro, float* frac) {
    *inteiro = floor(num);
    *frac = num - *inteiro;
}

int main() {
    float n;
    printf("Insira um número decimal: ");
    scanf("%f", &n);
    int inteiro;
    float fracionario;
    frac(n, &inteiro, &fracionario);
    printf("%d %f", inteiro, fracionario);
    return 0;
}
