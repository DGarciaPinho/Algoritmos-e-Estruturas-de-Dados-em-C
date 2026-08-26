/* 
4. Escreva um programa que declare uma variável do tipo float e um ponteiro associado
a ela. Leia um valor real e altere esse valor, por meio do ponteiro, acrescentando 10%
ao valor original.
*/
#include <stdio.h>

void main(){
  float a;
  float *ptr = &a;

  scanf("%f",&a);

  *ptr = *ptr + (*ptr * 0.1);
  
  printf("Novo valor de a : %f", *ptr);
}
