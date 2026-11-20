/* 
10. Faça um programa que leia dois vetores de mesmo tamanho e crie um terceiro vetor
contendo os elementos dos dois vetores de forma intercalada. O primeiro elemento
do novo vetor deverá ser retirado do primeiro vetor, o segundo elemento deverá ser
retirado do segundo vetor, e assim sucessivamente até que todos os valores tenham
sido utilizados.
Exemplo:
Vetor A:
1 2 3 4
Vetor B:
8 7 6 5
Vetor resultante:
1 8 2 7 3 6 4 5
*/ 

#include <stdio.h>
#include <stdlib.h>

// RECEBE OS 3 PONTEIROS E O TAMANHO DO TERCEIRO 
void preencher(int *a,int *b,int *c,numsSize){
  int m,n;
  for(int i=0)
}

void main(){
  int x;
  printf("Primeiro vetor : \n");
  printf("Digite o numero de valores : \n ");
  scanf("%d",&x);
  printf("===================================");

  int *ptr = calloc(x,sizeof(int));

  printf("Preencha o Primeiro Vetor : \n"); 
  for(int i=0;i<x;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&ptr[i]);
        
  }

  printf("===============/===================")
  printf("===============/===================")

  // SEGUNDO Vetor
  printf("Segundo vetor : \n");
  printf("Digite o numero de valores : \n ");
  scanf("%d",&x);
  printf("===================================");

  int *ptr2 = calloc(x,sizeof(int));

  printf("Preencha o Segundo Vetor : \n"); 
  for(int i=0;i<x;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&ptr2[i]);
  }

  int *ptr3 = calloc(x*2,sizeof(int));

  preencher(ptr,ptr2,ptr3,x*2);

  for(int i=0;i<x*2;++i){
    printf("Elemento [%d] de ptr3 : %d \n ", i+1,ptr3[i]);
  }
}
