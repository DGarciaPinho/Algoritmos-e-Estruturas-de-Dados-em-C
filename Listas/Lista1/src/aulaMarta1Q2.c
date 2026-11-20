/* 2) Escreva um programa que receba uma temperatura em graus Celsius e apresente o
valor correspondente em graus Fahrenheit. Utilize a fórmula: F = (9C/5) + 32 */ 

#include <stdio.h>

void main()
{
  int C;
  scanf("%d",&C);

  int F = (9*C/5) + 32;

  printf("%d em Fahrenheit");

}
