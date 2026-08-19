/* 7) Desenvolva um programa que receba um número inteiro e informe se ele é par ou
ímpar.*/

#include <stdio.h>

void main(){
  
  int n;
  scanf("%d",&n);

  if(n % 2 == 1){
    printf("Impar");
  }else if(n % 2 == 0){
    printf("Par");
  }else{
    printf("Zero");
  }

}
