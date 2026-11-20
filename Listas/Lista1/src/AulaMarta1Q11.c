/*Escreva um programa que receba o salário de um funcionário. Para salários de até R$
2.000,00, aplique um aumento de 15%. Para salários superiores a esse valor, aplique
um aumento de 8%. Apresente o valor do aumento e o novo salário.*/ 

#include <stdio.h>

void main(){

  float salario,salarion;
  scanf("%f",&salario);

  if(salario <=2000){
    printf("%f",salario);
    salarion = salario + ((salario/10)*1.5);
    printf("%f",salarion);
  }else{
    printf("%f",salario);
    salarion = salario +((salario/10)*0.8);
    printf("%f",salarion);
  }
}
