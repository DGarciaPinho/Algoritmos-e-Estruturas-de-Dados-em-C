#include <stdio.h>

#define ORDEM 3

int main(void)
{
    int matriz[ORDEM][ORDEM];
    int somaReferencia = 0;
    int diagonalPrincipal = 0;
    int diagonalSecundaria = 0;
    int magico = 1;
    int i, j, soma;

    printf("Digite os elementos da matriz 3 x 3:\n");
    for (i = 0; i < ORDEM; i++) {
        for (j = 0; j < ORDEM; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("Entrada invalida.\n");
                return 1;
            }
        }
    }

    for (j = 0; j < ORDEM; j++) {
        somaReferencia += matriz[0][j];
    }

    for (i = 0; i < ORDEM && magico; i++) {
        soma = 0;
        for (j = 0; j < ORDEM; j++) {
            soma += matriz[i][j];
        }
        if (soma != somaReferencia) {
            magico = 0;
        }
    }

    for (j = 0; j < ORDEM && magico; j++) {
        soma = 0;
        for (i = 0; i < ORDEM; i++) {
            soma += matriz[i][j];
        }
        if (soma != somaReferencia) {
            magico = 0;
        }
    }

    for (i = 0; i < ORDEM; i++) {
        diagonalPrincipal += matriz[i][i];
        diagonalSecundaria += matriz[i][ORDEM - 1 - i];
    }

    if (diagonalPrincipal != somaReferencia ||
        diagonalSecundaria != somaReferencia) {
        magico = 0;
    }

    if (magico) {
        printf("A matriz e um quadrado magico. Soma: %d\n", somaReferencia);
    } else {
        printf("A matriz nao e um quadrado magico.\n");
    }

    return 0;
}
