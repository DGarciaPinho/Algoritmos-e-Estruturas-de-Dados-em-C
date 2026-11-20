/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

4. Implemente uma função recursiva que calcula a soma dos elementos de um vetor de double de tamanho n.
*/

#include <stdio.h>
#include <stdlib.h>

double somaD(double *ptr,int i,int n){
  if(i+1==n){
    return ptr[i];
  }else{
    return ptr[i] + somaD(ptr,i+1,n);
  }
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);

  double *ptr = calloc(n,sizeof(double));

  for(int i=0;i<n;++i){
    scanf("%lf",&ptr[i]);
  }

  double soma = somaD(ptr,0,n);

  printf("Soma = [%f]",soma);
}
