/*
7. Faça um programa que leia um vetor de números inteiros e elimine os valores que
aparecem mais de uma vez. Para cada valor repetido, somente a sua primeira ocor-
rência deverá permanecer no vetor. A operação deverá ser feita sem a utilização de
um vetor auxiliar. Ao final, apresente apenas os valores distintos na mesma ordem em
que apareceram originalmente.
Exemplo:
Vetor original:
4 2 4 7 2 9 7
Vetor resultante:
4 2 7 9
*/ 

#include <stdio.h>
#include <stdlib.h>

//EMPURRAR A EM B  
void push(int *a,int *b){
  *b = *a;
}

void arrasto(int *b,int l,int lens){
  for(int i=l+1;i<lens;++i){
    push(&b[i],&b[i-1]);
  }
}

int repetido(int *a,int numsSize){
  int n=0;

  for(int i=0;i<numsSize;++i){
    for(int j=i+1;j<numsSize;++j){
      if(a[i]==a[j]){
        arrasto(a,j,numsSize);
        n++;
      }
    }
  }
  return n;
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

  int m = repetido(ptr,x);
  int res = x - m; 

  int *temp = realloc(ptr, res * sizeof(int));
  if (temp != NULL) {
    ptr = temp;
  } else {
    // realloc falhou, ptr original ainda é válido
    printf("Erro ao realocar memória.\n");
  }

  for(int i=0;i<res;++i){
    printf("%d,",ptr[i]);
  }
}
