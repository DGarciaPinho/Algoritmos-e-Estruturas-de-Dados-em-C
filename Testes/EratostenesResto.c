#include <stdio.h>
#include <string.h>

#define MAX 1000001

int primo[MAX];

// Função que cria os primos usando o Crivo de Eratóstenes
void gerarPrimos() {

    // Inicialmente, assume que todos são primos
    for (int i = 0; i < MAX; i++) {
        primo[i] = 1;
    }

    // 0 e 1 não são primos
    primo[0] = 0;
    primo[1] = 0;

    // Marca os múltiplos dos primos
    for (int i = 2; i * i < MAX; i++) {

        // Se ainda for primo
        if (primo[i]) {

            // Marca múltiplos como não primos
            for (int j = i * i; j < MAX; j += i) {
                primo[j] = 0;
            }
        }
    }
}

// Função para calcular K % divisor
// K é uma string enorme
int resto(char K[], int divisor) {

    int r = 0;

    // Percorre todos os dígitos de K
    for (int i = 0; K[i] != '\0'; i++) {

        // Faz a conta do módulo digitado
        r = (r * 10 + (K[i] - '0')) % divisor;
    }

    return r;
}

int main() {

    // Gera todos os primos até 10^6
    gerarPrimos();

    char K[105]; // número enorme (até 10^100)
    int L;

    // Lê até encontrar 0 0
    while (scanf("%s %d", K, &L)) {

        // Condição de parada
        if (strcmp(K, "0") == 0 && L == 0) {
            break;
        }

        int encontrou = 0;

        // Testa todos os primos menores que L
        for (int p = 2; p < L; p++) {

            // Se for primo
            if (primo[p]) {

                // Verifica se K é divisível por p
                if (resto(K, p) == 0) {

                    // Encontrou fator pequeno
                    printf("BAD %d\n", p);

                    encontrou = 1;
                    break;
                }
            }
        }

        // Se não encontrou nenhum fator pequeno
        if (!encontrou) {
            printf("GOOD\n");
        }
    }

    return 0;
}
