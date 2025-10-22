#ifndef LOGICA_JOGO_H
#define LOGICA_JOGO_H

#include "territorio.h" // importa a definição da struct Territorio
#include "jogador.h"   // importa a definição da struct Jogador

void inicializar_random();
int jogar_dado();
void cadastrar_territorios(Territorio territorios[], int num_territorios);
void cadastrar_jogadores(Jogador jogadores[], Territorio territorios[], int num_jogadores);
void atribuir_donos_aos_territorios(Jogador jogadores[], Territorio territorios[], int num_jogadores);
void neutralizar_territorio(Territorio* territorio);
void conquistar_territorio(Territorio* t_atacante, Territorio* t_defensor);
void batalhar(Territorio* t_atacante, Territorio* t_defensor);
void verificar_jogadores_dorrotados(Territorio territorios[], Jogador jogadores[], Jogador jogadores_derrotados[]);
void inicializar_baralho_de_missoes(Jogador jogadores[], int num_jogadores, Territorio territorios[], int num_territorios);
void distribuir_missoes(Jogador jogadores[], int num_jogadores, Territorio territorios[], int num_territorios);
int verificarMissao(Territorio territorios[], int num_territorios);
void liberar_baralho_de_missoes();
void embaralhar_indices(int* array, int n);

#endif