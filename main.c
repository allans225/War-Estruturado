#include <stdio.h>  // Caixa de ferramentas I/O
#include <stdlib.h> // Bibliotec padrão
#include <string.h> // Caixa de Ferramentas para Manipulação de Strings

// Constantes Globais

#define MAX_TERRITORIOS 5

// Objetos e Estruturas de Dados

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Funções e Procedimentos

// Limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastrar os territórios
void cadastrar_territorios(Territorio territorios[], int num_territorios) {
    printf("======================\n");
    printf("Vamos cadastrar os %d territorios iniciais do nosso mundo.\n", num_territorios);
    printf("\n");

    for (int i = 0; i < num_territorios; i++) {
        printf("Cadastrando Territorio %d\n", i + 1);
        printf("Nome do territorio: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;

        printf("Cor do exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
        printf("\n");
    }
}

// Função para listar todos os territórios cadastrados
void listar_territorios(const Territorio territorios[], int num_territorios) {
    printf("======================================\n");
    printf("      MAPA DO MUNDO - ESTADO ATUAL    \n");
    printf("======================================\n");
    printf("\n");
    
    for (int i = 0; i < num_territorios; i++) {
        printf("TERRITORIO %d:\n", i + 1);
        printf(" - Nome: %s\n", territorios[i].nome);
        printf(" - Dominado por: Exercito %s\n", territorios[i].cor);
        printf(" - Numero de Tropas: %d\n", territorios[i].tropas);
        printf("\n");
    }
}

int main() {
    Territorio territorios[MAX_TERRITORIOS]; // Declara o vetor de territórios
    cadastrar_territorios(territorios, MAX_TERRITORIOS); // Chama a função para preencher o vetors
    listar_territorios(territorios, MAX_TERRITORIOS); // Chama a função para exibir o conteúdo do vetor
    return 0;
}