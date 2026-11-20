#include <stdio.h>

int main(void)
{
    double numero;

    printf("Digite um numero: ");
    if (scanf("%lf", &numero) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (numero >= 10.0 && numero <= 50.0) {
        printf("O numero pertence ao intervalo [10, 50].\n");
    } else {
        printf("O numero nao pertence ao intervalo [10, 50].\n");
    }

    return 0;
}
