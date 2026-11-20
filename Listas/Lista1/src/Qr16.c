#include <stdio.h>

int main(void)
{
    double peso, altura, imc;

    printf("Digite o peso em kg e a altura em metros: ");
    if (scanf("%lf %lf", &peso, &altura) != 2 || peso <= 0.0 || altura <= 0.0) {
        printf("Peso ou altura invalido.\n");
        return 1;
    }

    imc = peso / (altura * altura);
    printf("IMC: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificacao: abaixo do peso.\n");
    } else if (imc < 25.0) {
        printf("Classificacao: peso adequado.\n");
    } else if (imc < 30.0) {
        printf("Classificacao: sobrepeso.\n");
    } else {
        printf("Classificacao: obesidade.\n");
    }

    return 0;
}
