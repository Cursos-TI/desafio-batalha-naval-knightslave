#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HAB 5

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona navios.
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[6][3] = 3;
    tabuleiro[7][2] = 3;

    int cone[HAB][HAB], cruz[HAB][HAB], octaedro[HAB][HAB];
    int i, j;

    // Gera Cone (formato de V invertido)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= HAB / 2 - i && j <= HAB / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Gera Cruz
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB / 2 || j == HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Gera Octaedro (losango)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (abs(i - HAB / 2) + abs(j - HAB / 2) <= HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Função para aplicar habilidade ao tabuleiro
    void aplicar(int habilidade[HAB][HAB], int origemX, int origemY) {
        for (i = 0; i < HAB; i++) {
            for (j = 0; j < HAB; j++) {
                int x = origemX + i - HAB / 2;
                int y = origemY + j - HAB / 2;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3)
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Aplicar habilidades em pontos específicos
    aplicar(cone, 2, 2);
    aplicar(cruz, 5, 5);
    aplicar(octaedro, 7, 7);

    // Exibir tabuleiro
    printf("Legenda: 0 = Água | 3 = Navio | 5 = Habilidade\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
