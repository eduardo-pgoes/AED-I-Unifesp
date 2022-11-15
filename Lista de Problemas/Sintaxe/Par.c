#include "Par.h"

void lePar(Par *p) {
    printf("Esquerda: %c\n", p->esquerda);
    printf("Direita: %c\n", p->direita);
}

int pertenceAPar(Par *p, char caracter, int n) {
    for (int i = 0; i < n; i++) {
        if (caracter == p[i].esquerda) {
            return 1;
        } else if (caracter == p[i].direita) {
            return 2;
        } else {
            return 0;
        }
    }
}

char getCaracterCorrespondente(Par *p, char caracter, int n) {
    for (int i = 0; i < n; i++) {
        if (caracter == p[i].esquerda) {
            return p[i].direita;
        }
    }
    return *"";
}