#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){ // Algoritmo de Euclides
  if(b==0){
    return a;
  }else{
    return mdc(b,a%b);
  }
}

void main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int z = mdc(n,m);
  printf("%d",z);
}
