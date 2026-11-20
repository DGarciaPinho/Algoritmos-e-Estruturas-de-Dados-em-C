/*
3. Leia 15 números inteiros e reorganize o vetor de forma que todos os valores iguais a
zero sejam deslocados para o final, mantendo a ordem relativa dos demais elementos.
Exemplo: 3 0 7 0 2 5 0 → 3 7 2 5 0 0 0
*/

#include <stdio.h>

void swap(int *a,int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }

void main(){
    int v[15],right=14,n=0;

    for(int i=0;i<15;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&v[i]);
        
        if(v[i]==0){
           n++;
        }
      }

    for(int i=0;i<15;++i){

      while(v[right]==0){
          right--;
        }

      if(v[i]==0 && v[right]!=0 && n!=0){
          swap(&v[i],&v[right]);
          right--;
          n--;
          //debug
          printf("swap de %d e %d \n",i,right);
        }
      }

    printf("A nova ordem do vetor é : \n ");

    for(int i=0;i<15;++i){
        printf("%d,",v[i]);
      }
}
