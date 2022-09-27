/*
	Faça uma função que receba um valor n e crie dinamicamente um vetor de n
	elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
	vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
	função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
	crie uma função principal que leia um valor n e chame a função criada acima. Depois,
	a função principal deve ler os n elementos desse vetor. Então, a função principal deve
	chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
	memória alocada através da função criada para liberação.
*/

#include <stdio.h>
#include <stdlib.h>


void fazTudo(int *vetor, int size);
void criaVetor(int *vetor, int size);
void leVetor(int *vetor, int size);
void freeVetor(int *vetor);
void imprimeVetor(int *vetor, int size);

int main(void) {
	int n;
	printf("Quantos elementos voce deseja inserir no vetor? ");
	scanf("%d", &n);
	int *vetor;
	fazTudo(vetor, n);
	return 0;
}

void fazTudo(int *vetor, int size) {
	criaVetor(vetor, size);
}

void criaVetor(int *vetor, int size) {
	vetor = (int *) malloc(sizeof(int) * size);
	leVetor(vetor, size);
}

void leVetor(int *vetor, int size) {
	for (int i = 0; i < size; i++) {
		printf("Insira o elemento de indice %d: ", i);
		scanf("%d", (vetor+i));
		fflush(stdin);
	}
	freeVetor(vetor);
}

void freeVetor(int *vetor) {
	free(vetor);
}

void imprimeVetor(int *vetor, int size) {
	for (int i = 0; i < size; i++) {
		printf("vetor[%d]: %d\n", i, *(vetor+i));
	}
}