/* 1) Escreva um programa que receba a base e a altura de um retângulo e calcule sua
área e seu perímetro. Considere : A = b * h  e  P = 2(b+h) */

#include <stdio.h>

void main()
{
  int Base, Altura;
  scanf("%d",&Base);
  scanf("%d",&Altura);

  int P = 2(Base + Altura), A = Base * Altura;

  printf("Area = %d e Perimetro = %d",A,P);

}
