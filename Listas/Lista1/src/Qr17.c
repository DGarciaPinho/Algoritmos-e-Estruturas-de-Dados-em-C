#include <stdio.h>

int main(void)
{
    double consumo, tarifa, total;

    printf("Digite o consumo mensal em kWh: ");
    if (scanf("%lf", &consumo) != 1 || consumo < 0.0) {
        printf("Consumo invalido.\n");
        return 1;
    }

    tarifa = consumo <= 100.0 ? 0.60 : 0.80;
    total = consumo * tarifa;

    printf("Valor total da conta: R$ %.2f\n", total);
    return 0;
}
