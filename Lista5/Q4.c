/*
4. Faça um programa em C para armazenar em memória um total de 30 valores do tipo inteiro,
   usando a função de alocação dinâmica de memória CALLOC:
   (a) Atribua para os primeiros 10 inteiros os valores de 1 a 10;
   (b) Atribua para os últimos 10 inteiros os valores de 10 a 1;
   (c) Exiba na tela os 30 números.
*/
#include <stdio.h>
#include <stdlib.h>

void main(){
  int *ptr = calloc(30,sizeof(int));

  for(int i=0;i<30;++i){
    if(i<10){
      ptr[i] = (i+1);
    }else if(20==i){
      ptr[i] = 10;
    }else if(20<i){
      ptr[i] = ptr[i-1] - 1;
    }
  }

  for(int i=0;i<30;++i){
    printf("Elemento [%d] : %d \n", i+1,ptr[i]);
  }
}
