/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 2 – Problemas contextualizados

18. (Verificação de ordenação de um vetor) Escreva um programa em C que leia um vetor de números inteiros e
determine se seus elementos estão em ordem crescente, permitindo valores repetidos. Um vetor está nessa
ordem quando cada elemento, a partir do segundo, é maior ou igual ao anterior. Use recursividade para resolver
o problema.
Entrada: a primeira linha contém um inteiro N, 1 ≤ N ≤ 1000, que indica o tamanho do vetor. A segunda linha
contém os N elementos inteiros do vetor.
Saída: imprima SIM se o vetor estiver em ordem crescente; caso contrário, imprima NAO.
Exemplo 1:
Entrada
5
-3 0 0 7 12
Saída
SIM
Exemplo 2:
Entrada
4
1 5 3 8
Saída
NÃO
*/

#include <stdio.h>
#include <stdlib.h>
