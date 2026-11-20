#include <stdio.h>

int main(void)
{
    int idade;

    printf("Digite a idade: ");
    if (scanf("%d", &idade) != 1 || idade < 0) {
        printf("Idade invalida.\n");
        return 1;
    }

    if (idade >= 18) {
        printf("Maior de idade.\n");
    } else {
        printf("Menor de idade.\n");
    }

    return 0;
}
