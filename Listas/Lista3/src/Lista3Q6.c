/*
6. Faça um programa que leia um vetor contendo uma quantidade par de elementos. Em
seguida, modifique o próprio vetor de modo que a primeira metade passe a ocupar o
lugar da segunda metade e a segunda metade passe a ocupar o lugar da primeira. A
ordem dos elementos dentro de cada metade deverá ser preservada e não deverá ser
utilizado um vetor auxiliar.
Exemplo:
Vetor original:
1 2 3 4 5 6
Vetor resultante:
4 5 6 1 2 3
*/ 

#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reshape(int *a,int z){
  for(int i=0;i<z/2;++i){
    swap(&a[i],&a[z-i-1]);
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

  reshape(ptr,x);

  for(int i=0;i<x;++i){
    printf("%d,",ptr[i]);
  }
}
