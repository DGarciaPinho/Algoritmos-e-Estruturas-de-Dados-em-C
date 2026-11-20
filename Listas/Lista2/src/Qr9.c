#include <stdio.h>

#define LINHAS_A 3
#define COLUNAS_A 4
#define COLUNAS_B 2

int main(void)
{
    int a[LINHAS_A][COLUNAS_A];
    int b[COLUNAS_A][COLUNAS_B];
    int c[LINHAS_A][COLUNAS_B] = {0};
    int i, j, k;

    printf("Digite os elementos da matriz A (3 x 4):\n");
    for (i = 0; i < LINHAS_A; i++) {
        for (j = 0; j < COLUNAS_A; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Entrada invalida.\n");
                return 1;
            }
        }
    }

    printf("Digite os elementos da matriz B (4 x 2):\n");
    for (i = 0; i < COLUNAS_A; i++) {
        for (j = 0; j < COLUNAS_B; j++) {
            if (scanf("%d", &b[i][j]) != 1) {
                printf("Entrada invalida.\n");
                return 1;
            }
        }
    }

    for (i = 0; i < LINHAS_A; i++) {
        for (j = 0; j < COLUNAS_B; j++) {
            for (k = 0; k < COLUNAS_A; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Matriz C = A x B (3 x 2):\n");
    for (i = 0; i < LINHAS_A; i++) {
        for (j = 0; j < COLUNAS_B; j++) {
            printf("%d%c", c[i][j], j == COLUNAS_B - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
