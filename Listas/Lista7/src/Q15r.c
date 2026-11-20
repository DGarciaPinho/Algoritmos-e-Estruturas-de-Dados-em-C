/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 2 – Problemas contextualizados

15. (Soma de dígitos) Implemente uma função que calcula a soma dos dígitos de um número inteiro. Sua função
deve tratar o número como inteiro, não sendo permitido converter para string ou char. Por exemplo:
• a soma dos dígitos do número 1342 é 10;
• a soma dos dígitos do número 700 é 7;
• a soma dos dígitos do número 9 é 9.

Dica: (i) para obter o dígito menos significativo, basta calcular o resto da divisão inteira por 10; (ii) para desprezar
o dígito menos significativo, pegue o resultado da divisão inteira por 10.
(a) Implemente sua solução usando abordagem iterativa.
(b) Implemente sua solução usando abordagem recursiva.
*/

#include <stdio.h>
#include <stdlib.h>
