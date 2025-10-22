#ifndef TERRITORIO_H
#define TERRITORIO_H

#include "jogador.h" // importa a definição da struct Jogador

// Definição GLOBAL do número máximo de territórios
#define MAX_TERRITORIOS 5

typedef struct {
    char nome[30];
    char cor_dominante[10];
    int tropas;
    Jogador* dono;
} Territorio;

#endif