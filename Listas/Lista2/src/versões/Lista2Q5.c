/* 5. Leia um vetor com 20 números inteiros, que podem ser positivos ou negativos, e
determine qual trecho de elementos consecutivos possui a maior soma. Apresente:
a) a maior soma encontrada;
b) a posição inicial do trecho;
c) a posição final do trecho.
No exemplo, -2 3 5 -1 4 -10 7, o trecho de maior soma é 3 5 -1 4.
*/ 

#include <stdio.h>

#define N 20

int main() {
    int v[N];
    int i, j;

    printf("Digite os %d numeros inteiros:\n", N);
    for (i = 0; i < N; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    int somaMax = v[0];
    int inicioMax = 0;
    int fimMax = 0;

    // Laço externo: fixa o inicio do trecho
    for (i = 0; i < N; i++) {
        int somaAtual = 0;

        // Laço interno: fixa o fim do trecho e acumula a soma
        for (j = i; j < N; j++) {
            somaAtual += v[j];

            if (somaAtual > somaMax) {
                somaMax = somaAtual;
                inicioMax = i;
                fimMax = j;
            }
        }
    }

    printf("\n--- Resultado ---\n");
    printf("a) Maior soma encontrada: %d\n", somaMax);
    printf("b) Posicao inicial do trecho: %d\n", inicioMax);
    printf("c) Posicao final do trecho: %d\n", fimMax);

    printf("Trecho: ");
    for (i = inicioMax; i <= fimMax; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
