/*
20. Considere um vetor estático contendo 10 números inteiros. Implemente o procedi-
mento void inverter(int *inicio, int *fim). O primeiro parâmetro deverá apon-
tar para o primeiro elemento do vetor e o segundo para o último elemento. A função
deverá inverter os elementos do vetor utilizando apenas os dois ponteiros. Dentro da
função, não utilize índices.
*/

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void inverter(int *inicio, int *fim){
  int tamanho = inicio - fim;
  int n = tamanho;

  while(n > tamanho / 2){
    swap(inicio,fim);
    inicio++;
    fim++;
  }
}

void main(){
  int z;
  printf("Digite o tamanho do array : \n");
  scanf("%d",&z);

  int arr[z];

  for(int i=0;i<z;++i){
    printf("Digite o elemento %d : \n", i+1);
    scanf("%d",&arr[i]);
  }

  inverter(&arr[0],&arr[z-1]);

  for(int i=0;i<z;++i){
    printf("%d,",arr[i]);
  }
}
