/*
9. Implemente uma função que receba dois números inteiros por meio de ponteiros e
faça com que o maior valor fique armazenado na primeira variável e o menor valor
na segunda variável. O cabeçalho da função deverá ser void ordenar2(int *a, int
*b).
*/ 

#include <stdio.h>

void swap(int *m,int *n){
  int temp = *m;
  *m = *n;
  *n = temp;
}

void ordenar2(int *a, int *b){
  if(*a < *b){
    swap(a,b);
  }
}

void main(){
  int v1,v2;
  scanf("%d %d",&v1,&v2);

  ordenar2(&v1,&v2);

  printf("%d %d",v1,v2);
}
