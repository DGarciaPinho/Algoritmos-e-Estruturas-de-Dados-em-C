/*
1. Faça um programa que leia os elementos de um vetor de números inteiros e, em
seguida, altere o próprio vetor de modo que seus elementos fiquem armazenados na
ordem inversa. A inversão deverá ser realizada sem a utilização de um segundo vetor.
Ao final, apresente o vetor resultante.
Exemplo:
Vetor original:
2 5 8 1 9
Vetor resultante:
9 1 8 5 2
*/ 

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *b = *a;
  *a = *b;
}

void vswap(int *ptr){
  int temp = sizeof(*ptr)/sizeof(int);

  for(int i=0;i<temp;++i){
    swap(&ptr[temp - 1 - i],&ptr[i]);
  }
}

void main(){
  int n;

  printf("Digite um valor de n : \n ");
  scanf("%d",&n);

  int *v = malloc(sizeof(int) * n);

  for(int i=0;i<n;++i){
    printf("Digite o Elemento [%d]",i+1);
    scanf("%d",&v[i]);
    printf("\n");
  }

  vswap(v);

  printf("Ordem Invertida");

  for(int i=0;i<n;++i){
    printf("Elemento [%d] \n ",v[i]);
  }

}
