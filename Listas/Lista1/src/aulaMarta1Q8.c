/*Desenvolva um programa que receba a idade de uma pessoa e informe se ela é maior
ou menor de idade.*/

#include <stdio.h>

void main(){
  int idade;
  scanf("%d",&idade);

  if(idade>=18){
    printf("Maior de idade");
  }else{
