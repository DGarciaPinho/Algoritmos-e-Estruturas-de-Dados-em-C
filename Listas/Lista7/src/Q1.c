/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

1. Implemente uma função recursiva para imprimir os elementos de um vetor de inteiros de tamanho n.
*/

#include <stdio.h>
#include <stdlib.h>

void imprimir(int *ptr,int i,int n){
  if((i+1)==n){
    printf("[%d]",ptr[n-i-1]);
  }else{ // Como a questão não pede pra ser da esquerda para a direita, vou apresentar do final do vetor para o começo 
    imprimir(ptr,i+1,n);
    printf("[%d]",ptr[n-i-1]);
  }
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);

  int *ptr = calloc(n,sizeof(int));

  for(int i=0;i<n;++i){
    scanf("%d",&ptr[i]);
  }

  imprimir(ptr,0,n);


}
