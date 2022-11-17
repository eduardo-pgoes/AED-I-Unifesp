#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noh {
    int valor;
    struct noh *prox;
};

typedef struct noh TipoNoh;