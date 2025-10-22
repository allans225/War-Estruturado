#include <stdio.h>          // Caixa de ferramentas I/O
#include <stdlib.h>         // Bibliotec padrão (malloc, calloc, free, rand)

#include "jogador.h"        // Definição da struct Jogador
#include "territorio.h"     // Definição da struct Territorio
#include "utils.h"          // Funções utilitárias
#include "interface.h"      // Funções de interface
#include "logica_jogo.h"    // Funções de lógica do jogo

int main() {
    inicializar_random(); // Inicializa o gerador de números aleatórios
    Territorio* territorios = NULL; // Ponteiro para o vetor de territórios
    territorios = (Territorio*) malloc(MAX_TERRITORIOS * sizeof(Territorio)); // Aloca memória para o vetor de territórios

    // Verifica se a alocação de memória foi bem-sucedida
    if (territorios == NULL) {
        printf("Erro! Falha ao alocar memoria.\n");
        return 1; // Encerra o programa indicando um erro
    }

    Jogador* jogadores = NULL;
    jogadores = (Jogador*) malloc(MAX_JOGADORES * sizeof(Jogador));

    if (jogadores == NULL) {
        printf("Erro! Falha ao alocar memoria para jogadores.\n");
        free(territorios); // Libera a memória já alocada para territórios
        return 1; // Encerra o programa indicando um erro
    }

    Jogador* jogadores_derrotados = NULL;
    jogadores_derrotados = (Jogador*) malloc(MAX_JOGADORES * sizeof(Jogador));
    
    if (jogadores_derrotados == NULL) {
        printf("Erro! Falha ao alocar memoria para jogadores derrotados.\n");
        free(territorios);
        free(jogadores);
        return 1;
    }

    cadastrar_territorios(territorios, MAX_TERRITORIOS);
    cadastrar_jogadores(jogadores, territorios, MAX_JOGADORES);
    atribuir_donos_aos_territorios(jogadores, territorios, MAX_JOGADORES);
    inicializar_baralho_de_missoes(jogadores, MAX_JOGADORES, territorios, MAX_TERRITORIOS);
    distribuir_missoes(jogadores, MAX_JOGADORES, territorios, MAX_TERRITORIOS);

    int numAtacante, numDefensor;
    system("cls"); // Limpa a tela
    
    do {
        listar_territorios(territorios, MAX_TERRITORIOS);
        printf("\n");

        printf("--- FASE DE ATAQUE ---\n");
        // Seleciona o território atacante
        numAtacante = selecionar_territorio_atacante();
        if (numAtacante == 0) break; // Sai do loop e encerra o programa

        // Converte para índice do array, verifica se o território tem mais de 1 tropa
        if (territorios[numAtacante - 1].tropas <= 0) {
            printf("Ataque invalido! O territorio atacante precisa de uma ou mais tropas.\n\n");
            continue; // Volta para o início do loop
        }

        // mostrar missão do atacante
        mostrar_missao_jogador(territorios[numAtacante - 1].dono);

        // Seleciona o território defensor
        numDefensor = selecionar_territorio_defensor(numAtacante);
        if (numDefensor == 0) break; // Sai do loop e encerra o programa
        
        printf("\n");
        printf("--- RESULTADO DA BATALHA ---\n");
        // Converte para índices do array e inicia a batalha
        batalhar(&territorios[numAtacante - 1], &territorios[numDefensor - 1]);
        printf("\n");

        verificar_jogadores_dorrotados(territorios, jogadores, jogadores_derrotados);

        if (verificarMissao(territorios, MAX_TERRITORIOS)) {
            break; // Sai do loop se uma missão foi cumprida
        }

        pausar_para_proximo_turno();
    } while (1);

    liberar_baralho_de_missoes(); // Libera a memória alocada para o baralho de missões
    free(jogadores_derrotados); // Libera a memória alocada para o vetor de jogadores derrotados
    free(jogadores); // Libera a memória alocada para o vetor de jogadores
    free(territorios); // Libera a memória alocada para o vetor de territórios
    printf("Memoria liberada. Fim de jogo!\n");
    return 0;
}