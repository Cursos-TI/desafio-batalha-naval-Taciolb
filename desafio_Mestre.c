#include <stdio.h>
#include <stdlib.h>  // Para outras funções padrão

#define TAM_TAB 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializa_tabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro com cores no terminal
void exibe_tabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:
                    printf("\033[34m~ \033[0m");  // Azul
                    break;
                case NAVIO:
                    printf("\033[32mN \033[0m");  // Verde
                    break;
                case HABILIDADE:
                    printf("\033[31m* \033[0m");  // Vermelho
                    break;
                default:
                    printf("? ");
            }
        }
        printf("\n");
    }
}

// Aplica a matriz de habilidade ao tabuleiro
void aplica_habilidade(int tabuleiro[TAM_TAB][TAM_TAB], int matriz[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha_tab = origem_linha - offset + i;
            int coluna_tab = origem_coluna - offset + j;

            if (linha_tab >= 0 && linha_tab < TAM_TAB && coluna_tab >= 0 && coluna_tab < TAM_TAB) {
                if (matriz[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == AGUA) {
                    tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
                }
            }
        }
    }
}

// Cria matriz em forma de cone
void cria_cone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) ? 1 : 0;
        }
    }
}

// Cria matriz em forma de cruz
void cria_cruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Cria matriz em forma de octaedro (losango) sem usar abs()
void cria_octaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist_i = (i < centro) ? centro - i : i - centro;
            int dist_j = (j < centro) ? centro - j : j - centro;
            matriz[i][j] = (dist_i + dist_j <= centro) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    inicializa_tabuleiro(tabuleiro);

    // Posiciona navios fixos
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Matrizes de habilidade
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    cria_cone(cone);
    cria_cruz(cruz);
    cria_octaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplica_habilidade(tabuleiro, cone, 1, 2);
    aplica_habilidade(tabuleiro, cruz, 5, 5);
    aplica_habilidade(tabuleiro, octaedro, 6, 6);

    // Exibe o resultado final
    exibe_tabuleiro(tabuleiro);

    return 0;
}