#include <stdio.h>

/*
 * Resposta da questao 1:
 *
 * No Codigo 1, o ponteiro continua apontando para o unico inteiro alocado.
 * O conteudo desse inteiro e incrementado cinco vezes, de 10 para 15. Portanto,
 * o valor impresso para *ptr e 15, e free(ptr) recebe o endereco correto.
 *
 * No Codigo 2, o conteudo nao e alterado: quem e incrementado e o endereco
 * guardado em ptr. Nao existe um endereco numerico fixo que possa ser previsto.
 * Alem disso, avancar repetidamente para fora do bloco de um unico inteiro tem
 * comportamento indefinido, e free(ptr) tambem e invalido porque ptr ja nao
 * contem o endereco originalmente devolvido por malloc.
 */

int main(void)
{
    printf("Codigo 1: *ptr vale 15.\n");
    printf("Codigo 2: nao ha valor de endereco previsivel; o programa tem "
           "comportamento indefinido.\n");
    return 0;
}
