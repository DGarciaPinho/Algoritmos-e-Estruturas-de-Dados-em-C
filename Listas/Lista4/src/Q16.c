/*
16. Implemente uma função que receba um vetor estático de inteiros e determine simul-
taneamente o maior e o menor valor encontrado. Utilize o seguinte cabeçalho void
extremos(int *vetor, int tamanho, int *maior, int *menor). A função deverá
percorrer o vetor utilizando aritmética de ponteiros.
*/

#include <stdio.h>

void extremos(int *vetor, int tamanho, int *maior, int *menor){
  for(int i=0;i<tamanho;++i){
    if(*maior < *vetor){
      *maior = *vetor;
    }else if(*menor > *vetor){
      *menor = *vetor;
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

  int Big = *arr;
  int Small = *arr;

  extremos(arr,n,&Big,&Small);
  printf("O maior é %d e o menor é %d",Big,Small);
}
