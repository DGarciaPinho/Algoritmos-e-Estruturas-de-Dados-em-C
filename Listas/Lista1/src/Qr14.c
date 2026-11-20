#include <stdio.h>

int main(void)
{
    double lado1, lado2, lado3;

    printf("Digite as tres medidas: ");
    if (scanf("%lf %lf %lf", &lado1, &lado2, &lado3) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (lado1 > 0.0 && lado2 > 0.0 && lado3 > 0.0 &&
        lado1 < lado2 + lado3 && lado2 < lado1 + lado3 &&
        lado3 < lado1 + lado2) {
        printf("As medidas podem formar um triangulo.\n");
    } else {
        printf("As medidas nao podem formar um triangulo.\n");
    }

    return 0;
}
