/*Escreva um programa que receba dois números e apresente o maior. Caso os valores
sejam iguais, o programa deverá informar que não há um número maior.:*/

#include <stdio.h>

void main(){
  int n1,n2;
  scanf("%d %d",&n1,&n2);

  if(n1==n2){
    printf("Valores iguais");
  }else if(n1 > n2){
    printf("N1 é maior");
  }else{
    printf("N2 é maior");
  }
}
