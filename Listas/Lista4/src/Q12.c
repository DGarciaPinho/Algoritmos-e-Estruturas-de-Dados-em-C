/*
12. Faça um programa que leia três valores inteiros e utilize uma função para colocá-los
em ordem crescente. O cabeçalho da função deverá ser void ordenar3(int *a, int
*b, int *c). Não utilize vetores dentro da função e não aplique algoritmos ou méto-
dos de ordenação. A ordenação deve ser realizada apenas por meio de comparações
e trocas entre as três variáveis, utilizando os ponteiros recebidos como parâmetros.
*/

#include <stdio.h>

void swap(int *m,int *n){
  int temp = *n;
  *n = *m;
  *m = temp;
}

void ordenar3(int *a, int *b, int *c){
  for(int i=0;i<2;++i){
    if(*a>*b){
      swap(a,b);
    }
    if(*b>*c){
      swap(b,c);
    }
  }
}

void main(){
  int v1,v2,v3;
  printf("Digite v1,v2,v3 :\n");
  scanf("%d %d %d",&v1,&v2,&v3);

  ordenar3(&v1,&v2,&v3);

  printf("V1 : %d, V2 : %d, V3 : %d",v1,v2,v3);
}
