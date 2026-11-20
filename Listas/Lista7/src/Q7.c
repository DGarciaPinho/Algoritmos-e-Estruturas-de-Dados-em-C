/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

7. Escreva uma função recursiva que, dado dois números x e n, calcula o valor x*n (x multiplicado por n). Sua
função não pode usar o operador de multiplicação.
*/

#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int a,int b){
  if(b==1){
    return a;
  }else{
    return a + multiplicacao(a,b-1);
  }
}

void main(){
  int a,b;
  printf("Digite o numero 'a' : \n");
  scanf("%d",&a);
  printf("Digite o numero 'b' : \n");
  scanf("%d",&b);

  int res = multiplicacao(a,b);

  printf("a multiplicação é igual a : [%d]",res);
}
