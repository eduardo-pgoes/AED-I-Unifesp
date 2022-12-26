#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1100000 // no input, temos \r, \n, uma letra (P, I ou R) e um número que pode ir de 1 a 10^6.

/* Protótipos de função */
struct noh* novoNoh(int);
struct noh* insere(struct noh*, int);
struct noh* insere(struct noh*, int);
struct noh* menorNoh(struct noh*);
void posOrdem(struct noh*);
void emOrdem(struct noh*);
void preOrdem(struct noh*);

/**
 * \struct Estrutura de dados que representa um nó de árvore binária
*/
struct noh {
    int data; /** Dado salvo no nó */
    struct noh* esquerda; /** Nó da esquerda */
    struct noh* direita; /** Nó da direita */
};

/**
 * \brief Função que constrói um novo nó de árvore com um dado, mas sem ramos.
 * @param data O que você deseja salvar no nó
 * @return Nó
*/
struct noh* novoNoh(int data) {
    struct noh* noh = (struct noh*) malloc(sizeof(struct noh));
    noh->data = data;
    noh->esquerda = NULL;
    noh->direita = NULL;

    return noh;
}

/**
 * \brief Função para inserir um elemento em uma árvore binária de busca.
 * @param raiz Raíz da árvore binária.
 * @param data Dado a ser inserido.
 * @return Nó da raíz, ponteiro inalterado.
*/
struct noh* insere(struct noh *raiz, int data) {
    // Tive que fazer uma solução iterativa, pois estava estourando o limite de tempo :)
    if (raiz == NULL) return novoNoh(data);

    struct noh *temp = raiz;
    int flag = 1;

    // Travega pela árvore até conseguir inserir um elemento
    while (flag) {
        if (data > temp->data) {
            if (temp->direita == NULL) {
                temp->direita = novoNoh(data);
                flag = 0;
            } else {
                temp = temp->direita;
            }
        } else {
            if (temp->esquerda == NULL) {
                temp->esquerda = novoNoh(data);
                flag = 0;
            } else {
                temp = temp->esquerda;
            }
        }
    }
    return raiz;
}

/**
 * \brief Função para buscar um elemento em uma árvore binária de busca.
 * @param raiz Raíz da árvore binária.
 * @param data Dado a ser buscado.
 * @return Nó da raíz que contém o dado - se ele não for nulo, encontramos o dado
*/
struct noh* busca(struct noh* raiz, int data) {
    // Solução iterativa pra tentar evitar runtime error...
    while (raiz != NULL) {
        if (raiz->data == data) {
            return raiz;
        }

        if (data < raiz->data) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }
    return NULL;
}

/**
 * \brief Função que encontra o menor nó presente na árvore.
 */
struct noh* menorNoh(struct noh* raiz)
{
    struct noh* atual = raiz;
    
    // caçando a folha mais à esquerda na árvore
    while (atual && atual->esquerda != NULL)
        raiz = atual->esquerda;

    return atual;
}

/**
 * \brief Função que remove um nó de uma árvore binária de busca.
 * @param raiz Raiz da árvore binária de busca.
 * @param data Dado que se deseja remover da árvore.
 * @returns Ponteiro para a nova raíz da árvore
*/
struct noh* removeNoh(struct noh *raiz, int data) {
    if (raiz == NULL) {
        return NULL;
    }

    // Se data < nó atual, devemos buscar remover na esquerda
    if (data < raiz->data) {
        raiz->esquerda = removeNoh(raiz->esquerda, data);
    } else if (data > raiz->data) {
        raiz->direita = removeNoh(raiz->direita, data);
    } else {
        // No caso de uma raíz sem filhos...
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            return NULL;
        } else if (raiz->esquerda == NULL) {
            struct noh *temp = raiz->direita;
            return temp;
        } else if (raiz->direita == NULL) {
            struct noh *temp = raiz->esquerda;
            return temp;
        } else {
            // Seguindo as instruções do enunciado pra raízes com mais de um filho
            struct noh *temp = menorNoh(raiz->direita);
            raiz->data = temp->data;
            raiz->direita = removeNoh(raiz->direita, temp->data);
        }
    }
    return raiz;
}

/**
 * \brief Passa por uma árvore em pós-ordem, imprimindo seus elementos.
 * \param[in] raiz Raíz da árvore.
*/
void posOrdem(struct noh* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->data);
}

/**
 * \brief Passa por uma árvore em ordem, imprimindo seus elementos.
 * \param[in] raiz Raíz da árvore.
*/
void emOrdem(struct noh* raiz) {
    if (raiz == NULL) {
        return;
    }
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->data);
    emOrdem(raiz->direita);
}

/**
 * \brief Passa por uma árvore em ordem, imprimindo seus elementos.
 * \param[in] raiz Raíz da árvore.
*/
void preOrdem(struct noh* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d ", raiz->data);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

int main() {
    struct noh *raiz = NULL, *temp = NULL;
    char operacao;
    int data;
    char *LINE;
    int length;
    LINE = (char*) malloc (MAX_LENGTH * sizeof(char));
    
    // Lê e lida com cada caso.
    while (LINE != NULL) {
        fgets(LINE, MAX_LENGTH, stdin);
        // Remove \n e \r do input pra conseguir comparar direito
        LINE[strcspn(LINE, "\r\n")] = 0;

        length = strlen(LINE);
        if (length <= 7 && length >= 6) {
            if (strcmp(LINE, "INFIXA") == 0) {
                emOrdem(raiz);
                printf("\n");
                continue;
            } else if (strcmp(LINE, "PREFIXA") == 0) {
                preOrdem(raiz);
                printf("\n");
                continue;
            } else if (strcmp(LINE, "POSFIXA") == 0) {
                posOrdem(raiz);
                printf("\n");
                continue;
            }
        }
        
        sscanf(LINE, "%c %d", &operacao, &data);
        switch (operacao) {
            case 'I':
                if (raiz == NULL) {
                    // No primeiro caso, a raíz ainda é nula e operar nela vai gerar um belo core dump
                    raiz = insere(raiz, data);
                } else {
                    insere(raiz, data);
                }
                break;
            case 'P':
                temp = busca(raiz, data);
                if (temp == NULL) {
                    printf("%d nao existe\n", data);
                } else {
                    printf("%d existe\n", data);
                }
                break;
            case 'R':
                temp = busca(raiz, data);
                // Não faz sentido algum remover um dado que não existe  
                if (temp == NULL) {
                    printf("%d nao existe\n", data);
                    break;
                }
                removeNoh(raiz, data);
                break;
        }
    }
}