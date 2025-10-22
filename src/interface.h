#ifndef INTERFACE_H
#define INTERFACE_H

#include "territorio.h" // importa a definição da struct Territorio

void listar_territorios(const Territorio territorios[], int num_territorios);
int selecionar_territorio_atacante();
int selecionar_territorio_defensor(int numTerritorioAtacante);
void mostrar_missao_jogador(const Jogador* jogador);

#endif