#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quantos valores deseja digitar? ");
    scanf("%d", &n);

    int *entrada = (int *) malloc(n * sizeof(int));
    printf("Digite %d valores inteiros:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &entrada[i]);
    }

    // descobre o intervalo (min e max) dos valores digitados
    int min = entrada[0], max = entrada[0];
    for (int i = 1; i < n; i++) {
        if (entrada[i] < min){ 
            min = entrada[i];
        }
        if (entrada[i] > max){ 
            max = entrada[i];
        }
    }

    int faixa = max - min + 1; // tamanho necessario do vetor de contagem

    int **dados = (int **) malloc(2 * sizeof(int *));
    dados[0] = (int *) malloc(faixa * sizeof(int)); // vai guardar o valor real
    dados[1] = (int *) calloc(faixa, sizeof(int));  // frequencias, inicia em 0

    // conta as ocorrencias: O(n)
    for (int i = 0; i < n; i++) {
        int idx = entrada[i] - min; // desloca para indice >= 0
        dados[0][idx] = entrada[i]; // guarda o valor original nessa posicao
        dados[1][idx]++;
    }

    // exibe: O(faixa)
    printf("\nValores sem repeticao e suas frequencias:\n");
    for (int i = 0; i < faixa; i++) {
        if (dados[1][i] > 0) {
            printf("Valor: %d - Frequencia: %d\n", dados[0][i], dados[1][i]);
        }
    }

    free(entrada);
    free(dados[0]);
    free(dados[1]);
    free(dados);
    return 0;
}
