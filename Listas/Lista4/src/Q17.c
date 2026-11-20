/*
17. Considere um vetor estático contendo 10 números inteiros. Implemente o procedi-
mento void separarParesImpares(int *vetor, int tamanho, int *pares, int
impares). A função deverá contar quantos elementos são pares e quantos são ím-
pares, armazenando os resultados nas variáveis indicadas pelos ponteiros pares e
impares. A função deverá percorrer o vetor utilizando aritmética de ponteiros.
*/

#include <stdio.h>

void separarParesImpares(int *vetor, int tamanho, int *pares, int *impares){
  for(int i=0;i<10;++i){
    if(*vetor % 2 == 0){
      *pares = *pares + 1;
    }else{
      *impares = *impares + 1;
    }
    vetor++;
  }
}

void main(){
  int arr[10];

  for(int i=0;i<10;++i){
    printf("Digite o elemento %d",i+1);
    scanf("%d",&arr[i]);
  }

  int impar = 0,par = 0;

  separarParesImpares(arr,10,&par,&impar);

  printf("Numero de par : %d, Numero de impar : %d",par,impar);
}
