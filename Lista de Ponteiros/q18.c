#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

void calc_esfera(float R, float *area, float *volume);

void calc_esfera(float R, float *area, float *volume) {
    *area = 4 * PI * pow(R, 2);
    *volume = (4 * PI * pow(R, 3)) / 3;
}

int main() {
    float r, area, volume;
    printf("Insira o raio da esfera: ");
    scanf("%f", &r);
    calc_esfera(r, &area, &volume);
    printf("Volume: %f m^3\nSuperficie: %f m^2\n", volume, area);
    return 0;
}