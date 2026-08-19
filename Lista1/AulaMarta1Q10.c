/*Desenvolva um programa que receba o preço de um produto. Caso o valor seja supe-
rior a R$ 100,00, conceda um desconto de 10%. Apresente o preço original, o valor
do desconto e o preço final.*/

#include <stdio.h>

void main(){
  float valori;
  scanf("%f",&valori);

  if(valori > 100){
    printf("Valor Original %f",valori);
    printf("Valor Descontado %f",valori/10);
    printf("Valor final %f",valori - valori/10");
  }else{
    printf("Valor Original %f",valori);
    printf("Valor Descontado 0");
    printf("Valor final %f",valori);
  }
}
