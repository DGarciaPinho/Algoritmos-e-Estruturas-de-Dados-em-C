#include <stdio.h>
#include <stdlib.h>

void imprimirR(int n,int i){
  if(i == n){
    printf("[%d]",n);
  }else{
    imprimirR(n,++i);
    printf("[%d] \n",n-i);
  }
}

void main(){
  int n;
  printf("Digite n : \n");
  scanf("%d",&n);

  imprimirR(n,0);
}
