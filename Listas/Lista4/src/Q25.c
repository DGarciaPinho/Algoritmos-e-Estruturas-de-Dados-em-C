/*
25. Considere um vetor estático de 10 números inteiros. Implemente o procedimento void
minMax(int *inicio, int *fim, int **menor, int **maior). Os ponteiros inicio
e fim indicam, respectivamente, o primeiro e o último elemento do vetor. A função
deverá percorrer o intervalo utilizando exclusivamente aritmética de ponteiros e fazer:
• *menor apontar para o menor elemento;
• *maior apontar para o maior elemento.
Após a chamada, o programa principal deverá trocar os conteúdos do menor e do
maior elemento utilizando somente os ponteiros retornados pela função.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void minMax(int *inicio, int *fim, int **menor, int **maior){
  int *ptr = inicio;
  while(ptr<=fim){
    if((ptr != menor) && (*ptr < *menor)){
      menor = ptr;
    }else if((ptr != maior) && (*ptr > *maior)){
      maior = ptr;
    }

    ptr++;
  }
}

void main(){
  int arr[10];

  for(int i=0;i<10;++i){
    printf("Digite %d : \n",i+1);
    scanf("%d",&arr[i]);
  }

  int *ptrM = &arr[0];
  int *ptrm = &arr[0];
  int *ptrF = &arr[9];
  int *ptrI = &arr[0];

  minMax(ptrI,ptrF,ptrm,ptrM);
  swap(ptrM,ptrm);
}
