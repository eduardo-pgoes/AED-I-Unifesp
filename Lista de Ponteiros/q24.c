#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void minMax(int *arr, int *max, int *min, int size);

void minMax(int *arr, int *max, int *min, int size) {    
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for (int i = 0; i < size; i++) {  
        if (arr[i] < minimum) {
            minimum = arr[i];
        } 
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    *max = maximum;
    *min = minimum;
}

int main() {
    int n;
    printf("Insira quantos elementos voce deseja ter na array: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        printf("Insira o elemento indice %d: ", i);
        scanf("%d", &arr[i]);
    }
    int min, max;
    minMax(arr, &max, &min, n);
    printf("Max da array: %d\nMin da array: %d\n", max, min);
}