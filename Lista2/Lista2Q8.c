/*
8. Leia uma matriz 5 × 5. Em seguida, leia dois números que representam índices de
linhas e faça a troca completa dessas duas linhas. Depois, leia dois índices de colunas
e faça a troca completa dessas duas colunas. Apresente a matriz resultante.
*/ 

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  matriz[5][5], k1,k2,z1,z2;

  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      printf("da linha %d e coluna %d : \n ",i+1,j+1);
      scanf("%d",&matriz[i][j]);
    }
  }

  // Mostrando a matriz original 
   for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      printf("|%d|",matriz[i][j]);
    }
    printf("\n");
  }

  printf("\n Escolha os elementos para serem trocados : \n");
  scanf("%d %d %d %d",&z1,&z2,&k1,&k2);

  swap(&matriz[z1][z2],&matriz[k1][k2]);

  printf("A nova matriz : \n");

    // Mostrando a matriz original 
   for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      printf("|%d|",matriz[i][j]);
    }
    printf("\n");
  }
}
