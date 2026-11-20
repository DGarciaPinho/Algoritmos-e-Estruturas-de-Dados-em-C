/*
8. Faça um programa em C que aloque dinamicamente uma matriz tridimensional. O programa
   deve solicitar que o usuário informe o tamanho da profundidade da matriz, a quantidade
   de linhas e a quantidade de colunas. A matriz deverá ser alocada e posteriormente
   preenchida pelo usuário usando aritmética de ponteiros. Ao final, o programa deve
   imprimir a matriz.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  int i,k,j;
  printf("Digite o valor de i : \n");
  scanf("%d",&i);

  printf("Digite o valor de j : \n");
  scanf("%d",&j);

  printf("Digite o valor de k : \n");
  scanf("%d",&k);

  printf("O ptr vai ter %d posições \n",i*k*j);

  // ALOCANDO A MATRIZ 3D 
  //Alocando cada profundidade 
  int ***ptrz = malloc(k * sizeof(int **));
  for(int x=0;x<k;++x){
    // Alocando as linhas para cada profundidade
    ptrz[x] = malloc(i * sizeof(int *));
    for(int y=0;y<i;++y){
      // Alocando as colunas
      ptrz[x][y]= malloc(j * sizeof(int));
    }
  }

  int ***prt1 = prtz;

  for(int x=0;x<i;++x){
    for(int y=0;y<j;++y){
      for(int z=0;z<k;++z){
        printf("[%d][%d][%d] : \n",x+1,y+1,z+1);
        scanf("%d",&ptr1);
        ptr1++;
      }
    }
  }

  //Mostrando a matriz
  for(int x=0;x<i;++x){
    for(int y=0;y<j;++y){
      for(int z=0;z<k;++z){
        printf("[%d][%d][%d] : [%d] \n",x+1,y+1,z+1,ptrz);
        ptrz++;
      }
    }
  }
}
