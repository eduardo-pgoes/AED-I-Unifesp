/*
	Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
	e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
	programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
	finalizar o programa, deve-se liberar a área de memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void leVetor(int *vetor, int size);

void leVetor(int *vetor, int size) {
	for (int i = 0; i < size; i++) {
		printf("Insira o elemento de indice %d: ", i);
		scanf("%d", &vetor[i]);
	}
}

int main(void) {
	int n;
	printf("Quantos elementos voce deseja inserir no vetor? ");
	scanf("%d", &n);
	int *vetor = (int *) malloc(sizeof(int) * n);
	leVetor(vetor, n);
	for (int i = 0; i < n; i++) {
		printf("vetor[%d]: %d\n", i, vetor[i]);
	}
	free(vetor);
	return 0;
}