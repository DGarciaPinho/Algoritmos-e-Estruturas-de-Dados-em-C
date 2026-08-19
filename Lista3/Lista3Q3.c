/* 
3. Faça um programa que leia um vetor de números inteiros e, depois, leia um valor
qualquer. Todas as ocorrências desse valor deverão ser retiradas do vetor. A operação
deverá ser realizada utilizando apenas o próprio vetor original. Ao final do processo,
apresente somente os elementos que permaneceram armazenados.
Exemplo:
Vetor:
2 7 4 7 1 7
Valor a ser removido: 7
Vetor resultante:
2 4 1
*/ 

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b
  *b = temp;
}

void main(){
  int n,f=0;
  printf("Digite o tamanho");
  scanf("%d",&n);

  int *ptr = malloc(sizeof(int) * n);

   for(int i=0;i<n;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&v[i]);
  }

  for(int i=0;i<n;++i){
     if(v[i]!=x){
          swap(&v[i],&v[n]);
           n++;
    }else{
      f++;
    }
  }

  ptr = realloc(ptr,sizeof(ptr)-sizeof(f));

  for(int i=0;i<n;++i){
    printf("%d,"ptr[i]);
  }

}
