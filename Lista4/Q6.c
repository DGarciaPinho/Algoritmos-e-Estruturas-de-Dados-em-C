/*
6. Implemente uma função void troca(int *a, int *b). A função deve trocar os con-
teúdos das duas variáveis recebidas por meio dos ponteiros. No programa principal,
leia os dois valores e exiba seus conteúdos antes e depois da chamada da função.
*/

#include <stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  int n=1,m=2;

  printf("N : %d, M : %d", n,m);
  swap(&n,&m);
  printf("N : %d, M : %d",n,m);

}
