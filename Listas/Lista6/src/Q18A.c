/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

18. Implemente a função:
int obterSubstring(const char *origem, const int inicio, const int quantidade, char *destino);
A função deverá copiar para destino até quantidade caracteres da string origem, começando na posição inicio. A
substring produzida deverá ser finalizada com o caractere nulo '\0'. A função deverá retornar a quantidade de
caracteres efetivamente copiados. Caso a posição inicial seja inválida ou a quantidade informada seja menor ou
igual a zero, a função deverá produzir uma string vazia e retornar zero. Se existirem menos caracteres disponíveis
do que a quantidade solicitada, deverão ser copiados apenas os caracteres existentes até o final da string.
Considere que o arranjo destino possui espaço suficiente para armazenar o resultado. Desenvolva um programa
para ler a string, a posição inicial e a quantidade de caracteres, chamar a função e imprimir a substring obtida.
*/

