#include <stdio.h>

int main(void)
{
    int hora;

    printf("Digite uma hora inteira entre 0 e 23: ");
    if (scanf("%d", &hora) != 1 || hora < 0 || hora > 23) {
        printf("Hora invalida.\n");
        return 1;
    }

    if (hora < 6) {
        printf("Madrugada.\n");
    } else if (hora < 12) {
        printf("Manha.\n");
    } else if (hora < 18) {
        printf("Tarde.\n");
    } else {
        printf("Noite.\n");
    }

    return 0;
}
