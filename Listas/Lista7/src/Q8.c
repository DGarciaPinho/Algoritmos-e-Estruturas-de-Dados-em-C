/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

8. Escreva uma função recursiva que dado dois números x e n, calcula o valor x^n (x elevado a n).
*/

#include <stdio.h>
#include <stdlib.h>

int power(int a,int b){
  if(b==1){
    return a;
  }else{
    return a * power(a,b-1);
  }
}

void main(){
  int a,b;
  printf("Digite o numero 'a' : \n");
  scanf("%d",&a);
  printf("Digite o numero 'b' : \n");
  scanf("%d",&b);

  int res = power(a,b);

  printf(" '%d' elevado a '%d' é igual a : [%d]",a,b,res);

}
