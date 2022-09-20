#include <stdio.h>
#include <math.h>

float raizes(float A, float B, float C, float *X1, float *X2);
float calc_delta(float A, float B, float C);

float calc_delta(float A, float B, float C) {
    return ((pow(B, 2)) - (4 * A * C));
}

float raizes(float A, float B, float C, float *X1, float *X2) {
    float delta = calc_delta(A, B, C);
    if (delta > 0) {
        *X1 = (-B + sqrt(delta)) / 2 * A;
        *X2 = (-B - sqrt(delta)) / 2 * A;
    } else if (delta == 0) {
        *X1 = (-B) / 2 * A;
        *X2 = *X1;
    }
}

int main() {
    float A, B, C;
    printf("Insira A, B e C da equacao de 2o grau: ");
    scanf("%f %f %f", &A, &B, &C);
    float X1, X2;
    raizes(A, B, C, &X1, &X2);
    printf("X1: %f\nX2: %f\n", X1, X2);
}