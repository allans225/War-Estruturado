#include <stdio.h>  // Caixa de ferramentas I/O
#include <stdlib.h> // Bibliotec padrão (malloc, calloc, free, rand)
#include <string.h> // Caixa de Ferramentas para Manipulação de Strings
#include <time.h.>  // Biblioteca para funções relacionadas ao tempo e aleatoriedade

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
        printf("%d. Nome: %s | Cor do Exercito: %s | Numero de Tropas: %d\n",
               i+1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

int selecionar_territorio_atacante() {
    int numTerritorioAtacante;
    int valid = 0;

    do {
        printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", MAX_TERRITORIOS);
        scanf("%d", &numTerritorioAtacante);
        limparBuffer(); // Limpa o buffer para evitar problemas com entradas futuras

        if (numTerritorioAtacante == 0) {
            printf("Encerrando o jogo. Ate a proxima!\n");
            break; // Sai do loop e encerra o programa
        }else if (numTerritorioAtacante < 1 || numTerritorioAtacante > MAX_TERRITORIOS) {
            printf("Numero invalido. Tente novamente.\n");
            continue; // Reinicia o loop
        }
        valid = 1; // Entrada valida
    } while (!valid); // Continua o loop ate uma entrada valida ser fornecida
    return numTerritorioAtacante;
}

int selecionar_territorio_defensor(int numTerritorioAtacante) {
    int numTerritorioDefensor;
    int valid = 0;

    do {
        printf("Escolha o territorio defensor (1 a %d, ou 0 para sair): ", MAX_TERRITORIOS);
        scanf("%d", &numTerritorioDefensor);
        limparBuffer();

        if (numTerritorioDefensor == 0) {
            printf("Encerrando o jogo. Ate a proxima!\n");
            break; // Sai do loop
        }else if (numTerritorioDefensor < 1 || numTerritorioDefensor > MAX_TERRITORIOS) {
            printf("Numero invalido. Tente novamente.\n");
            continue;
        }else if (numTerritorioAtacante == numTerritorioDefensor) {
            printf("O territorio atacante e o defensor nao podem ser o mesmo. Tente novamente.\n");
            continue;
        }
        valid = 1; // Entrada valida
    } while (!valid); // Continua o loop ate uma entrada valida ser fornecida

    return numTerritorioDefensor;
}

void inicializar_random() {
    srand(time(NULL));
}

int jogar_dado() {
    return (rand() % 6) + 1; // Retorna um valor entre 1 e 6
}

void batalhar(Territorio* atacante, Territorio* defensor) {
    // Cada lado joga um dado
    int dadoAtacante = jogar_dado();
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, dadoAtacante);
    int dadoDefensor = jogar_dado();
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, dadoDefensor);

    // Verifica qual dado e maior e remove uma tropa do perdedor
    if (dadoAtacante > dadoDefensor) {
        defensor->tropas--;
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
    } else {
        atacante->tropas--;
        printf("DEFESA BEM-SUCEDIDA! O atacante perdeu 1 tropa.\n");
    }

    if (defensor->tropas <= 0) {
        printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s\n", defensor->nome, atacante->cor);

        // O atacante precisa de pelo menos 2 tropas para poder mover 1 e continuar com 1
        if (atacante->tropas > 1) {
            // Muda a cor do defensor para a cor do atacante
            strcpy(defensor->cor, atacante->cor);
            
            // Move 1 tropa do atacante para o novo território
            defensor->tropas = 1;
            atacante->tropas--;
        } else {    
            printf("%s venceu, mas nao tem tropas suficientes para ocupar o territorio!\n", atacante->nome);
            printf("O territorio %s se tornou neutro com 0 tropas.\n", defensor->nome);
            defensor->tropas = 0; // Garante que fique com 0
            strcpy(defensor->cor, "Neutro"); // Define como neutro
        }
    }
}

// Função para pausar a execução até o usuário pressionar Enter
void pausar_para_proximo_turno() {
    printf("\nPressione Enter para ir para o proximo turno...");
    limparBuffer();
}

int main() {
    inicializar_random(); // Inicializa o gerador de números aleatórios
    Territorio* territorios = NULL; // Ponteiro para o vetor de territórios
    territorios = (Territorio*) malloc(MAX_TERRITORIOS * sizeof(Territorio)); // Aloca memória para o vetor de territórios

    // Verifica se a alocação de memória foi bem-sucedida
    if (territorios == NULL) {
        printf("Erro! Falha ao alocar memoria.\n");
        return 1; // Encerra o programa indicando um erro
    }

    cadastrar_territorios(territorios, MAX_TERRITORIOS);

    int numAtacante, numDefensor;

    do {
        system("cls"); // Limpa a tela
        listar_territorios(territorios, MAX_TERRITORIOS);
        printf("\n");

        printf("--- FASE DE ATAQUE ---\n");
        // Seleciona o território atacante
        numAtacante = selecionar_territorio_atacante();
        if (numAtacante == 0) break; // Sai do loop e encerra o programa

        // Converte para índice do array, verifica se o território tem mais de 1 tropa
        if (territorios[numAtacante - 1].tropas <= 1) {
            printf("Ataque invalido! O territorio atacante precisa de mais de 1 tropa.\n\n");
            continue; // Volta para o início do loop
        }

        // Seleciona o território defensor
        numDefensor = selecionar_territorio_defensor(numAtacante);
        if (numDefensor == 0) break; // Sai do loop e encerra o programa

        printf("\n");
        printf("--- RESULTADO DA BATALHA ---\n");
        // Converte para índices do array e inicia a batalha
        batalhar(&territorios[numAtacante - 1], &territorios[numDefensor - 1]);
        printf("\n");
        
        pausar_para_proximo_turno();
    } while (1);

    free(territorios); // Libera a memória alocada para o vetor de territórios
    printf("Memoria liberada. Fim de jogo!\n");
    return 0;
}