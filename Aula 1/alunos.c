#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Protótipos de função */
int insereAluno(struct aluno* alunos, struct aluno aluno, int size);
int removeAluno(struct aluno* alunos, int ra, int size);
int visualizaAluno(struct aluno* alunos, int ra, int size);

struct aluno {
    char nome[50];
    int ra;
    float nota;
    float frequencia;
};

/* Insere um aluno */
int insereAluno(struct aluno* alunos, struct aluno aluno, int size)
{
    for (int i = 0; i < size; i++) {
        if (alunos[i].ra == 0) {
            alunos[i] = aluno;
            return 1;
        }
    }
    return 0;
}

/* Remove um aluno de acordo com seu RA */
int removeAluno(struct aluno* alunos, int ra, int size) {
    struct aluno vazio; // Eu não sei se isso realmente forma um aluno vazio, então zero o RA pra garantir!!
    vazio.ra = 0;
    // Deve haver uma forma mais eficiente de realizar essa busca, mas não a encontrei
    for (int i = 0; i < size; i++) {
        if (alunos[i].ra == ra) {
            alunos[i] = vazio;
            return 1;
        }
    }
    return 0;
}

int visualizaAluno(struct aluno* alunos, int ra, int size) {
    for (int i = 0; i < size; i++) {
        if (alunos[i].ra == ra) {
            printf("Nome do aluno: %s\n", alunos[i].nome);
            printf("RA do aluno: %d\n", alunos[i].ra);
            printf("Nota do aluno: %f\n", alunos[i].nota);
            printf("Frequencia do aluno: %f\n", alunos[i].frequencia);
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Quantos alunos voce deseja ter? ");
    scanf("%d", &n);
    /* Alocação dinâmica de alunos */
    struct aluno* alunos = (struct aluno*) malloc(n * sizeof(struct aluno));
    char nome[50];
    int ra;
    float nota;
    float frequencia;
    int opcao = -1;

    while (opcao != 0) {
        printf("O que voce deseja fazer?\n");
        printf("1 - Adicionar aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Visualizar dados de aluno\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            /* Insere dados do aluno */
            case 1:
                printf("Insira o nome do aluno: ");
                scanf("%s", nome);
                printf("Insira o RA do aluno: ");
                scanf("%d", &ra);
                printf("Insira a nota do aluno: ");
                scanf("%f", &nota);
                printf("Insira a frequencia do aluno: ");
                scanf("%f", &frequencia);
                struct aluno aluno;
                strcpy(aluno.nome, nome);
                aluno.ra = ra;
                aluno.nota = nota;
                aluno.frequencia = frequencia;
                if (insereAluno(alunos, aluno, n)) {
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Aluno não foi inserido por... algum motivo? '-'\n");
                }
                break;
            /* Remove aluno */
            case 2:
                printf("Insira o RA do aluno.\n");
                scanf("%d", &ra);
                if (removeAluno(alunos, ra, n)) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Aluno não foi removido: RA não encontrado.\n");
                }
                break;
            /* Visualiza aluno */
            case 3:
                printf("Insira o RA do aluno: ");
                scanf("%d", &ra);
                if (!visualizaAluno(alunos, ra, n)) {
                    printf("RA não encontrado.\n");
                }
                break;
            default:
                printf("Opção inválida, bicho.\n");
        }
    }
    return 0;
}