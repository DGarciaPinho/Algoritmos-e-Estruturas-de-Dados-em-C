/*Escreva um programa que receba um número inteiro e informe se ele é positivo, neg-
ativo ou igual a zero.*/

#include <stdio.h>

void main(){
  int n;
  scanf("%d",&n);

  if(n==0){
    printf("Igual a zero");
  }else if(n>0){
    printf("Positivo");
  }else if(n<0){
    printf("Negativo");
  }
}
