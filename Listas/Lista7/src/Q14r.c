/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 2 – Problemas contextualizados

14. (Palíndromo) Uma string é considerada palíndroma quando pode ser lida da mesma forma da esquerda para a
direita e da direita para a esquerda. Por exemplo, “arara” é um palíndromo, enquanto “elefante” não é um
palíndromo.
Implemente uma função recursiva que determina se uma string é ou não palíndromo. A função deverá retornar
1 quando a string for palíndroma e 0 caso contrário. Diferenças entre letras maiúsculas e minúsculas deverão ser
desconsideradas, mas os espaços e os demais caracteres deverão participar da comparação. Por exemplo,
“Arara” deverá ser considerada palíndroma. Desenvolva um programa para ler uma string, chamar a função e
informar o resultado.
Exemplo 1:
Entrada: Arara
Saída: SIM
Exemplo 2:
Entrada: Caraiva
Saída: NÃO
*/

#include <stdio.h>
#include <stdlib.h>
