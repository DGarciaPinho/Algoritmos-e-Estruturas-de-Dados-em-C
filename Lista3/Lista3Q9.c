/*
9. Faça um programa que leia um vetor de números inteiros e, a partir dele, construa um
segundo vetor. Nesse novo vetor, todos os números pares deverão aparecer antes
dos números ímpares. A ordem relativa em que os números pares aparecem no vetor
original deverá ser mantida, assim como a ordem relativa dos números ímpares.
Exemplo:
Vetor original:
3 8 5 2 7 4
Vetor resultante:
8 2 4 3 5 7
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  int x,n=0;
  printf("Digite o numero de valores : \n ");
  scanf("%d",&x);

  int *ptr = calloc(x,sizeof(int));

  for(int i=0;i<x;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&ptr[i]);
        
        if(ptr[i] % 2 != 0){
          swap(&ptr[i],&ptr[n]);
           n++;
         }
  }

  for(int i=0;i<x;++i){
    printf("%d,",ptr[i]);
  }


}
