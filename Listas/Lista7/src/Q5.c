/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

5. Implemente uma função recursiva que inverte os elementos de um vetor de inteiros de tamanho n. O vetor
recebido como parâmetro deve ser alterado.
*/

#include <stdio.h>
#include <stdlib.h>

void inverter(int *ptr,int size,int i){
  int temp = ptr[i];
  if(i+1<size/2){
    inverter(ptr,size,i+1);
    ptr[i] = ptr[size-i-1];
    ptr[size-i-1] = temp;
  }else{
    ptr[i] = ptr[size-i-1];
    ptr[size-i-1] = temp;
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
    printf("Elemento [%d] \n",i+1);
    scanf("%d",&ptr[i]);
  }

  inverter(ptr,n,0);

  printf("Vetor invertido : \n");

  for(int i=0;i<n;++i){
    printf("[%d]",ptr[i]);
  }
}
