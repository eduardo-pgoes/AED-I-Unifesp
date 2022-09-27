#include <stdio.h>

typedef struct {
    char nome[30];
    char dataNascimento[10];
    char cpf[14];
} Pessoa;

void preenchePessoa(Pessoa *p) {
    printf("Insira seu nome: ");
    scanf("%s", p->nome);
    fflush(stdin);
    printf("Insira sua data de nascimento: ");
    scanf("%s", p->dataNascimento);
    fflush(stdin);
    printf("Insira seu CPF: ");
    scanf("%s", p->cpf);
}

void imprimePessoa(Pessoa p) {
    printf("Nome: %s\nNascimento: %s\nCPF: %s\n", p.nome, p.dataNascimento, p.cpf);
}

int main() {
    Pessoa p1;
    Pessoa *ponteiro = &p1; 
    preenchePessoa(ponteiro);
    imprimePessoa(p1);
    return 0;
}