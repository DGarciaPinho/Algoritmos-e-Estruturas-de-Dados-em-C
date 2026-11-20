/*
8. Faça um programa que leia um vetor de números inteiros e reorganize seus elemen-
tos de maneira que eles fiquem armazenados em ordem crescente. Não devem ser
utilizadas funções prontas da linguagem para realizar a ordenação. Ao final do pro-
cessamento, apresente o vetor ordenado.
Exemplo:
Vetor original:
8 3 6 1 4
Vetor ordenado:
1 3 4 6 8
*/ 

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(int *array, int numsSize){
  for(int i=0;i<numsSize;++i){
    for(int j=i+1;j<numsSize;++j){
      if(array[i]>array[j]){
        swap(&array[i],&array[j]);
      }
    }
  }
}

void main(){
  int x;

  printf("Digite o tamanho do vetor :\n");
  scanf(" %d",&x);

  int *ptr = calloc(x,sizeof(int));

  for(int i=0;i<x;++i){
    printf("Digite o elemento : [%d]",i+1);
    scanf("%d",&ptr[i]);
  }

  bubblesort(ptr,x);

  for(int i=0;i<x;++i){
    printf("%d,",ptr[i]);
  }

}
