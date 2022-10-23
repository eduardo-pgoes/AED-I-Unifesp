#include "ListaLinearSE.h"

/*
    Verifica se a lista está vazia.
    Retornos:
        1 - vazia
        0 - não vazia
*/
int listaVaziaLLSE(ListaLinearSE* lista) {
    return lista->ultimo == 0;
}

/*
    Verifica se a lista está cheia.
    Retornos:
        1 - cheia
        0 - há espaço(s)
*/
int listaCheiaLLSE(ListaLinearSE* lista) {
    return lista->ultimo == MAX;
}

/*
    Inicializa a lista
*/
void inicializaLLSE(ListaLinearSE* lista) {
    lista->ultimo = 0;
}

/*
    Destrói a lista.
    Como ela é estática, possui a mesma implementação da inicialização da lista...
    ... mas em listas dinâmicas, esse método se torna importantíssimo!
*/
void destroiListaLLSE(ListaLinearSE* lista) {
    lista->ultimo = 0;
}

/*
    Imprime apenas um item da lista.
*/
void imprimeItemLLED(TipoItem item) {
    printf("RA: %d\n", item.RA);
    printf("Nome: %s\n", item.nome);
    printf("Frequencia: %d\n", item.freq);
    for (int i = 0; i < 3; i++) {
        printf("Nota na P%d: %f\n", i+1, item.notas[i]);
    }
}

/* 
    Imprime a lista inteira.
*/
void imprimeListaLLSE(ListaLinearSE* lista) {
    for (int i = 0; i < lista->ultimo; i++) {
        printf("Item %d:\n", i+1);
        imprimeItemLLED(lista->itens[i]);
        printf("\n");
    }
    printf("\n");
}

/* 
    Insere item no início da lista.
    Retornos:
        1 - sucesso
        0 - falha
*/
int insereNoInicioLLSE(ListaLinearSE* lista, TipoItem item) {
    int pos = lista->ultimo;
    if (listaCheiaLLSE(lista)) {
        return 0;
    } 
    if (!listaVaziaLLSE(lista)) {
        for (int i = pos; i > 0; i--) {
            lista->itens[i] = lista->itens[i-1];
        }
    }
    lista->itens[0] = item;
    lista->ultimo++;
    return 1;
}

/* 
    Insere item no final da lista.
    Retornos:
        1 - sucesso
        0 - falha
*/
int insereNoFinalLLSE(ListaLinearSE* lista, TipoItem item) {
    if (listaCheiaLLSE(lista)) {
        return 0;
    }
    int pos = lista->ultimo;
    lista->itens[pos] = item;
    lista->ultimo++;
    return 1;
}

/* 
    Remove item ao final da lista.
    Retornos:
        1 - removido com sucesso
        0 - falha - lista vazia
        em *TipoItem, tem-se o item que foi removido
*/
int removeDoFinalLLSE(ListaLinearSE* lista, TipoItem* item) {
    if (listaVaziaLLSE(lista)) {
        return 0;
    }
    int pos = lista->ultimo - 1;
    *item = lista->itens[pos];
    lista->ultimo--;
    return 1;
}

/* 
    Remove item ao início da lista.
    Retornos:
        1 - removido com sucesso
        0 - falha - lista vazia
        em *TipoItem, tem-se o item que foi removido
*/
int removeDoInicioLLSE(ListaLinearSE* lista, TipoItem* item) {
    if (listaVaziaLLSE(lista)) {
        return 0;
    }
    int pos = lista->ultimo;
    *item = lista->itens[0];
    for (int i = 0; i < pos; i++) {
        lista->itens[i] = lista->itens[i+1];
    }
    lista->ultimo--;
    return 1;
}

/* 
    Remove item em posição específica.
    Retornos:
        1 - removido com sucesso
        0 - falha - lista vazia
        em *TipoItem, tem-se o item que foi removido
*/
int removeDaPosicaoLLSE(ListaLinearSE* lista, TipoItem* item, int posicao) {
    if (listaVaziaLLSE(lista)) {
        return 0;
    }
    *item = lista->itens[posicao-1];
    int pos = lista->ultimo;    
    for (int i = posicao - 1; i < pos; i++) {
        lista->itens[i] = lista->itens[i+1];
    }
    lista->ultimo--;
    return 1;
}

/* 
    Remove item de acordo com RA.
    Retornos:
        1 - removido com sucesso
        0 - falha - lista vazia
        -1 - falha - RA não encontrado
        em *TipoItem, tem-se o item que foi removido
*/
int removeEspecificoLLSE(ListaLinearSE* lista, TipoItem* item, int ra) {
    if (listaVaziaLLSE(lista)) {
        return 0;
    }
    int pos = lista->ultimo;
    int chave = -1;
    TipoItem item_atual;
    
    for (int i = 0; i < pos; i++) {
        printf("pos: %d RA: %d\n", pos, ra);
        imprimeItemLLED(lista->itens[i]);
        item_atual = lista->itens[i];
        if (item_atual.RA == ra) {
            chave = i+1;
            break;
        }
    }

    if (chave == -1) {
        return -1;
    } else {
        return removeDaPosicaoLLSE(lista, item, chave);
    }
}

/* 
    Insere item na posição indicada.
    Retornos:
        1 - adicionado com sucesso
        0 - falha - lista cheia
*/
int insereNaPosicaoLLSE(ListaLinearSE* lista, TipoItem item, int posicao) {
    if (listaCheiaLLSE(lista)) {
        return 0;
    }
    // Jogando os itens da posição para a direita...
    lista->ultimo++;
    int pos = lista->ultimo;
    for (int i = posicao - 1; i < pos; i++) {
        lista->itens[i+1] = lista->itens[i];
    }
    lista->itens[posicao-1] = item;
    return 1;
}
