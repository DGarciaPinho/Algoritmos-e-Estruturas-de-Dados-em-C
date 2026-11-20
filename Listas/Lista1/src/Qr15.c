#include <math.h>
#include <stdio.h>

int main(void)
{
    double numero;

    printf("Digite um numero real: ");
    if (scanf("%lf", &numero) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (numero < 0.0) {
        printf("Nao existe raiz quadrada real para o numero digitado.\n");
    } else {
        printf("Raiz quadrada: %.2f\n", sqrt(numero));
    }

    return 0;
}
