/*Desenvolva um programa que receba o preço de um produto e a quantidade com-
prada. Ao final, apresente o valor total da compra. */

#include <stdio.h>

void main()
{
  int preco, quantidade;

  scanf("%d",&preco);
  scanf("%d"&quantidade);

  int vf = preco * quantidade;

  printf("O valor final é igual a %d",vf);

}

