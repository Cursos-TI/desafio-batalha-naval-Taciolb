#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_VALOR 3

// Função para verificar se há sobreposição
int verifica_sobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO_VALOR;
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1 - Horizontal
    int l1 = 1, c1 = 2;
    if (c1 + NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < NAVIO; i++) {
            if (verifica_sobreposicao(tabuleiro, l1, c1 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l1][c1 + i] = NAVIO_VALOR;
            }
        }
    }

    // Navio 2 - Vertical
    int l2 = 4, c2 = 5;
    if (l2 + NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < NAVIO; i++) {
            if (verifica_sobreposicao(tabuleiro, l2 + i, c2)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l2 + i][c2] = NAVIO_VALOR;
            }
        }
    }

    // Navio 3 - Diagonal principal (↘)
    int l3 = 0, c3 = 0;
    if (l3 + NAVIO <= TAM && c3 + NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < NAVIO; i++) {
            if (verifica_sobreposicao(tabuleiro, l3 + i, c3 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l3 + i][c3 + i] = NAVIO_VALOR;
            }
        }
    }

    // Navio 4 - Diagonal secundária (↙)
    int l4 = 0, c4 = 9;
    if (l4 + NAVIO <= TAM && c4 - NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < NAVIO; i++) {
            if (verifica_sobreposicao(tabuleiro, l4 + i, c4 - i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l4 + i][c4 - i] = NAVIO_VALOR;
            }
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}