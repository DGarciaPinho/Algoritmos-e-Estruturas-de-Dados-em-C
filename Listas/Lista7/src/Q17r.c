/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 2 – Problemas contextualizados

17. (Máximo divisor comum pelo algoritmo de Euclides) O máximo divisor comum (MDC) de dois números inteiros
positivos é o maior número que divide ambos sem deixar resto. Pelo algoritmo de Euclides, o MDC pode ser
calculado substituindo-se repetidamente o par (a, b) por (b, a mod b), até que o segundo número seja zero.
Nesse momento, o primeiro número é o MDC.
Escreva um programa em C que leia dois números inteiros positivos e calcule o MDC entre eles usando o
algoritmo de Euclides. Seu programa deve implementar a função que calcular o MDC usando recursividade.
Entrada: dois números inteiros positivos a e b, separados por espaço.
Saída: um único número inteiro correspondente ao MDC de a e b.
Exemplo:
Entrada
48 18
Saída
6
*/

#include <stdio.h>
#include <stdlib.h>
