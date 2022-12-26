#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 156
#define FLAG_DEBUG 1

/**
 * \struct Estrutura de dados que representa um nó de árvore binária
*/
struct noh {
    char data; /**< Dado salvo no nó */
    struct noh* esquerda; /**< Nó da esquerda */
    struct noh* direita; /**< Nó da direita */
};

struct noh* novoNoh(char);
struct noh* constroiArvore(char*, char*, int);
struct noh* construtor(char*, char*, int, int, int*);
int busca(char*, int, int, char);
void posOrdem(struct noh*);
void dealoca(struct noh*);

/**
 * \brief Lida com cada caso de input de construção de árvore a partir das vistas pré-ordem e em ordem.
*/
void lidaComCaso() {
    // Dados necessários para lidar com cada caso de teste
    int length;
    char *strPreOrdem, *strEmOrdem, *LINE;

    LINE = (char*) malloc (MAX_LENGTH * sizeof(char));
    fgets(LINE, MAX_LENGTH, stdin);

    // Preciso ler quantos elementos virão na árvore antes de alocar espaço...
    sscanf(LINE, "%d %*s %*s", &length);

    strPreOrdem = (char*) malloc(length * sizeof(char));
    strEmOrdem = (char*) malloc(length * sizeof(char));

    sscanf(LINE, "%d %s %s", &length, strPreOrdem, strEmOrdem);

    if (FLAG_DEBUG) {
        printf("Primeira linha do caso de teste: %s\n", LINE);
        printf("Length lida: %d\n", length);
        printf("String pre-ordem: %s\n", strPreOrdem);
        printf("String em ordem: %s\n\n", strEmOrdem);
    }
    struct noh *raiz = constroiArvore(strPreOrdem, strEmOrdem, length);
    posOrdem(raiz);

    // Limpeza de memória
    dealoca(raiz);
    free(strEmOrdem);
    free(strPreOrdem);
}

/**
 * \brief Função que constrói uma árvore a partir dos chars de pré-ordem e em ordem
 * @param[in] preOrdem Array de chars com a vista pré-ordem da árvore
 * @param[in] emOrdem Array de chars com a vista em ordem da árvore
 * @param[in] emInicio Posição inicial na array em ordem - deve ser iniciada como 0
 * @param[in] emFinal Posição final na array em ordem - deve ser iniciada como length - 1
 * @return Nó da raíz 
*/
struct noh* construtor(char *preOrdem, char *emOrdem, int emInicio, int emFinal, int *index) {
    // TO-DO: descobrir o motivo pra essa função não funcionar quando passo o índice como parâmetro...
    if (FLAG_DEBUG) {
        printf("Estado atual da construtor():\n");
        printf("emInicio: %d, emFinal: %d\n\n", emInicio, emFinal);
    }

    if (emInicio > emFinal) {
        return NULL;
    }

    struct noh *proximoNoh = novoNoh(preOrdem[*index]);
    *index++;

    if (emInicio == emFinal) {
        if (FLAG_DEBUG) {
            printf("Estado atual do noh: ");
            posOrdem(proximoNoh);
            printf("\n");
        }
        return proximoNoh;
    } 

    if (FLAG_DEBUG) {
        printf("Estado atual do noh: ");
        posOrdem(proximoNoh);
        printf("\n");
    }

    int indiceEmOrdem = busca(emOrdem, emInicio, emFinal, proximoNoh->data);

    proximoNoh->esquerda = construtor(preOrdem, emOrdem, emInicio, indiceEmOrdem - 1, index);
    proximoNoh->direita = construtor(preOrdem, emOrdem, indiceEmOrdem + 1, emFinal, index);

    return proximoNoh;
}

struct noh* constroiArvore(char *emOrdem, char *preOrdem, int n) {
    int index = 0;
    return construtor(preOrdem, emOrdem, 0, n-1, &index);
}

/**
 * Função que busca o índice do valor em uma array de caracteres.
 * A função assume que o valor está presente em *arr.
 * @param[in] arr Array de caracteres
 * @param[in] inicio Onde começar a buscar (reduzindo complexidade em casos O(n))
 * @param[in] fim Onde parar de buscar (reduzindo complexidade em casos O(n))
 * @param[in] val Valor a ser buscado na array
*/
int busca(char *arr, int inicio, int fim, char val) {
    for (int i = inicio; i < fim; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
}

/**
 * \brief Função para liberar a memória de uma árvore binária recursivamente.
 * @param raiz Raíz da árvore binária.
*/
void dealoca(struct noh* raiz) {
    if (raiz == NULL) return;
    dealoca(raiz->esquerda);
    dealoca(raiz->direita);
    free(raiz);
}

/**
 * \brief Função que constrói um novo nó de árvore com um dado, mas sem ramos.
 * @param data O que você deseja salvar no nó
 * @return Nó
*/
struct noh* novoNoh(char data) {
    struct noh* noh = (struct noh*) malloc(sizeof(struct noh));
    noh->data = data;
    noh->esquerda = NULL;
    noh->direita = NULL;

    return noh;
}

/**
 * \brief Passa por uma árvore em pós-ordem, imprimindo seus elementos nessa ordem.
 * \param[in] raiz Raíz da árvore.
*/
void posOrdem(struct noh* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%c", raiz->data);
}

int main() {
    int n;
    scanf("%d", &n);
    (void) getchar(); // Joga fora o \n que o scanf() ignorou
    for (int i = 0; i < n; i++) {
        lidaComCaso();
    }

    return 0;
}