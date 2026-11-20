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
#include <stdlib.h>

void swap(int *a,int *b){
  int temp = *a;
  *b = *a;
  *a = *b;
}

void erase(int *ptr,int x){
  ptr[x] = 0; 
  int z=0;
  int temp = sizeof(ptr)/sizeof(int);

  for(int i=0;i<temp;++i){
    if(ptr[i]!=0){
      swap(&ptr[i],&ptr[z]);
      z++;
    }
  }

  ptr = realloc(ptr,sizeof(temp) - sizeof(int));
}

void main(){
  int n,e; 
  
  printf("Digite um valor de n : \n ");
  scanf("%d",&n);

  int *v = malloc(sizeof(int) * n);

  for(int i=0;i<n;++i){
    printf("Digite o Elemento [%d]",i+1);
    scanf("%d",&v[i]);
    printf("\n");
  }

  printf("Digite a posição a ser removida : \n ");
  scanf("%d",&e);

  erase(v,e);

  // Mostrando o novo ptr sem o elemento antigo
  for(int i=0;i<n;++i){
    printf("%d",v[i]);
  }
}
