#ifndef JOGADOR_H
#define JOGADOR_H

#include "missao.h"

#define MAX_JOGADORES 5

typedef struct {
    int id;
    char nome[10];
    char cor[10];
    Missao missao_atual;
} Jogador;

#endif