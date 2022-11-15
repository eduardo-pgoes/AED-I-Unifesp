#ifndef NOH_H
#define NOH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noh {
    char caracter;
    struct noh *prox;
};

typedef struct noh TipoNoh;

#endif /* NOH_H */