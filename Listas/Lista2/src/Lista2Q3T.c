/*
3. Leia 15 números inteiros e reorganize o vetor de forma que todos os valores iguais a
zero sejam deslocados para o final, mantendo a ordem relativa dos demais elementos.
Exemplo: 3 0 7 0 2 5 0 → 3 7 2 5 0 0 0
*/

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
    int v[15],n=0;
  // n de certa forma carrega a posição
  // onde 0 foi visto pela ultima vez, assim trocando ele de posição
  // com o proximo valor de i != 0, pois ao passar por 0, i ignora e 
  // não acontece nenhuma iteração. Assim, i sofre o incremento e assim 
  // sucessivamente.

    for(int i=0;i<15;++i){
        printf("Escreva o %d número",i+1);
        scanf("%d",&v[i]);
        
        if(v[i]!=0){
          swap(&v[i],&v[n]);
           n++;
         }
      }
  printf("A nova ordem é : \n ");

  for(int i=0;i<15;++i){
    printf("%d, ",v[i]);
  }

}
