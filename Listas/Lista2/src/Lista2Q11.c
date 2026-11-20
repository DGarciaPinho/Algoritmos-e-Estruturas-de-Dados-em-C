/*
11. Leia uma matriz 5 × 5 de números inteiros e construa uma segunda matriz. Para
   cada posição que não pertence à borda, o elemento da nova matriz deverá receber a
   soma do elemento original com seus oito vizinhos. Ou seja, para uma posição [i][j],
   deverão ser considerados os elementos da região 3 × 3 centralizada nessa posição.
   As posições da borda deverão permanecer inalteradas.
*/

#include <stdio.h>

void main(){
  int matriz[5][5];

  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      printf("Elemento [%d][%d]: \n ",i+1,j+1);
      scanf(" %d",&matriz[i][j]);
      printf("\n ");
    }
  }

  int matriz2[5][5], vizinhos=0;

  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      if(i>0 && i<4 && j>0 && j<4){
        vizinhos = (matriz[i][j-1]+matriz[i][j+1]) + (matriz[i-1][j]+matriz[i-1][j-1]+matriz[i-1][j+1]) + (matriz[i+1][j]+matriz[i+1][j-1]+matriz[i+1][j+1]);
        matriz2[i][j] = matriz[i][j] + vizinhos;
      }else{
        matriz2[i][j] = matriz[i][j]; // borda inalterada
    }
  }
}
 

  printf("Nova Matriz : \n");

  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){

    }
    printf("\n");
  }
}
