/*
2. Crie um programa em C que:
   (a) Aloque dinamicamente 5 números inteiros;
   (b) Peça para o usuário digitar os 5 números e armazene no espaço alocado;
   (c) Mostre na tela os 5 números;
   (d) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  int *ptr = calloc(5,sizeof(int));

  for(int i=0;i<5;++i){
    printf("Digite o elemento [%d] : \n",i+1);
    scanf("%d",&ptr[i]);
  }

  for(int i=0;i<5;++i){
    printf("Elemento [%d] = %d \n",i+1,ptr[i]);
  }

  free(ptr);
}
