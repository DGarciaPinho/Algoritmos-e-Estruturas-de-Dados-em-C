#include <stdio.h>

int main(void)
{
    double primeiro, segundo, terceiro, auxiliar;

    printf("Digite tres numeros distintos: ");
    if (scanf("%lf %lf %lf", &primeiro, &segundo, &terceiro) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (primeiro == segundo || primeiro == terceiro || segundo == terceiro) {
        printf("Os numeros devem ser distintos.\n");
        return 1;
    }

    if (primeiro > segundo) {
        auxiliar = primeiro;
        primeiro = segundo;
        segundo = auxiliar;
    }
    if (primeiro > terceiro) {
        auxiliar = primeiro;
        primeiro = terceiro;
        terceiro = auxiliar;
    }
    if (segundo > terceiro) {
        auxiliar = segundo;
        segundo = terceiro;
        terceiro = auxiliar;
    }

    printf("Ordem crescente: %g, %g, %g\n", primeiro, segundo, terceiro);
    return 0;
}
