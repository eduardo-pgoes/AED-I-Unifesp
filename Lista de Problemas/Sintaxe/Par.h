#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char esquerda;
    char direita;
} Par; // Representa um par de símbolos

void lePar(Par *p);

/* 
    Passa por todos os pares de símbolos de uma array dinâmica e verifica qual é o lado do caracter (esq/dir/não é símbolo)
    Flags:
        0 - não pertence ao par
        1 - é símbolo da esquerda
        2 - é símbolo da direita
    Parâmetros:
        Par* - lista de pares
        char - caracter a ser considerado como pertencente ou não ao par
        int - número de pares na lista

*/
int pertenceAPar(Par *p, char caracter, int n);

/*
    Retorna o caracter correspondente a um símbolo da esquerda dado
    Parâmetros:
        Par* - lista de pares
        char - caracter a ser correspondido
        int - número de pares na lista
    SÓ USE ESSA FUNÇÃO SE VOCÊ GARANTE QUE O CARACTER PERTENCE A UM PAR!!
*/
char getCaracterCorrespondente(Par *p, char caracter, int n);