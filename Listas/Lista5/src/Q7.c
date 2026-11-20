/*
7. Faça um programa que declare uma matriz bidimensional declarada no principal (main).
   O usuário deverá declarar ponteiros para linhas e para colunas dentro do principal. Os
   ponteiros deverão ser enviados para um procedimento onde a matriz será inicializada.
   Após retornar ao principal, outra função deverá receber a matriz já preenchida pelo
   usuário e deverá imprimi-la.
*/ 

#include <stdio.h>
#include <stdlib.h>
 

void imprimir(int **ptri,int xt,int yt){
  for(int i=0;i<xt;++i){
    for(int j=0;j<yt;++j){
      printf("Elemento [%d][%d] = [%d]",i+1,j+1,*(*(ptri+i)+j));    
      //*ptri++;
    }
    printf("\n");
    //ptri++;
  }
}

void preencher(int **ptrp,int xt,int yt){
  for(int i=0;i<xt;++i){ 
    for(int j=0;j<yt;++j){
      printf("Preencha o elemeento [%d][%d]",i+1,j+1);
      scanf("%d",(*(ptrp + i ) + j));      
     // *ptrp++;
    }
   // ptrp++;
  }
}

void main(){
  int x,y;

  printf("Defina [x] e [y]\n");
  scanf("%d %d",&x,&y);

  int tamanho = x * y;

  //Adicionando as linhas 
  int **ptr = malloc(x * sizeof(int *));
    for(int i=0;i<x;++i){
      // Alocando as colunas para cada linha
      ptr[i]= malloc(y * sizeof(int));
    }

  /* TESTE DOS ENDEREÇOS 
  int **ptrt = ptr;

  for(int i=0;i<x;++i){
    for(int j=0;j<y;++j){
      *ptrt = *ptrt - 3;
      printf("[%p] do elemento %d %d",ptrt,i+1,j+1);
      ptrt++;
    }
    *ptrt++;
  }
*/ 
  preencher(ptr,x,y);

  imprimir(ptr,x,y);
}
