/*
5. Crie um programa em C que:
   (a) Aloque dinamicamente 5 números inteiros;
   (b) Peça para o usuário digitar os 5 números e armazene no espaço alocado;
   (c) Imprima os endereços onde foram armazenados os 5 números;
   (d) Realoque um espaço para digitais mais 5 números inteiros;
   (e) Peça para o usuário digitar novos 5 números e armazene no novo espaço alocado;
   (f) Imprima os endereços onde foram armazenados os 10 números;
   (g) Mostre na tela os 10 números;
   (h) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  //  (a) Aloque dinamicamente 5 números inteiros;
  int *ptr = calloc(5,sizeof(int));

  //(b) Peça para o usuário digitar os 5 números e armazene no espaço alocado;
  for(int i=0;i<5;++i){
    printf("Digite o elemento %d \n",i+1);
    scanf("%d",&ptr[i]);
  }

  //(c) Imprima os endereços onde foram armazenados os 5 números;
  for(int i=0;i<5;++i){
    printf("Elemento [%d] : Endereço = %p \n",i+1,ptr[i]);
  }

  //(d) Realoque um espaço para digitais mais 5 números inteiros;
  ptr = realloc(ptr,10*(sizeof(int)));

  //(e) Peça para o usuário digitar novos 5 números e armazene no novo espaço alocado;
  for(int i=5;i<10;++i){
    printf("Digite o elemento %d \n",i+1);
    scanf("%d",&ptr[i]);
  }

  //(f) Imprima os endereços onde foram armazenados os 10 números;
  for(int i=0;i<10;++i){
    printf("Elemento [%d] : Endereço = %p \n",i+1,ptr[i]);
  }

  //(g) Mostre na tela os 10 números;
  for(int i=0;i<10;++i){
    printf("%d \n",ptr[i]);
  }

  // (h) Libere a memória alocada.
  free(ptr);
}
