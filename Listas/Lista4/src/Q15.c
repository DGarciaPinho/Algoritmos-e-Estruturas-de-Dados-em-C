/*
15. Implemente uma função que receba um vetor estático de números inteiros e substi-
tua cada elemento negativo pelo seu valor absoluto. O cabeçalho deverá ser void
tornarPositivos(int *vetor, int tamanho). A função deverá percorrer o vetor
utilizando aritmética de ponteiros, sem utilizar a notação vetor[i].
*/ 

#include <stdio.h>

void tornarPositivos(int *vetor, int tamanho){
  for(int i=0;i<tamanho;++i){
    if(*vetor < 0){
      *vetor = *vetor * -1;
    }
    vetor++;
  }
}

void main(){
  int n;
  printf("Digite o numero de elementos : \n");
  scanf("%d",&n);

  int arr[n];

  for(int i=0;i<n;++i){
    printf("Digite o elemento %d",i+1);
    scanf("%d",&arr[i]);
  }

  tornarPositivos(arr,n);
  int *ptr = arr;

  for(int i=0;i<n;++i){
    printf("%d,",*ptr);
    ptr++;
  }
}
