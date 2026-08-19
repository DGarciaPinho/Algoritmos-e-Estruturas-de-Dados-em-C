/* 
2. Faça um programa que leia os elementos de um vetor e, posteriormente, leia uma
posição informada pelo usuário. O elemento localizado nessa posição deverá ser
removido do vetor. Após a remoção, os elementos restantes deverão continuar ocu-
pando posições consecutivas. Ao final, apresente os elementos que permaneceram
no vetor.
Exemplo:
Vetor:
10 20 30 40 50
Posicao a ser removida: 2
Vetor resultante:
10 20 40 50
*/

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  int v[5] = {2,5,3,4,6},z;

  printf("Digite o indice para retirar : \n");
  scanf("%d",&z);

  for(int i=z;i<5;++i){
    if(i==4){
      break;
    }
    swap(v[i],v[i+1]);
  }

  for(int i=0;i<4;++i){
    printf("%d \n",v[i]);
  }
}
