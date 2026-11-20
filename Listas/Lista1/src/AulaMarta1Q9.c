/*Escreva um programa que receba duas notas, calcule a média aritmética e informe a
situação do aluno. Considere aprovado o aluno que obtiver média maior ou igual a 60.*/

#include <stdio.h>

void main(){
  int n[2],media = 0;

  for(int i=0;i<2;i++){
    scanf("%d",&n[i]);
    media = n[i] + media;
  }

  if(media > 59){
    printf("Situação: Aprovado!"); 
  }else{
    printf("Situação: Reprovado!");
  }
}
