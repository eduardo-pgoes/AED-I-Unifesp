#ifndef NOH_H
#define NOH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    O próprio nó já representa um disco.
*/
struct noh {
    int indice;
    struct noh *prox;
};

typedef struct noh TipoNoh;

#endif /* NOH_H */