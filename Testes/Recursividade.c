#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n){
  int i=0, temp=n, valor=0;
  
  if(n<10){ //Caso onde n só tem uma casa
    return n;
  }else{
    while(temp>9){ //Caso onde n tem + de 1 casa
      i++;
      temp = temp / 10;
    }
  }

  while(i>=0){
    if(i==0){
      valor = n + valor;
    }
    valor = n/(10*i) + valor;
    n = n - n/(10*i);
    i--;
  }
}

void main(){
  int z;

  printf("Digite o valor : \n");

  scanf("%d",&z);

  int soma = soma_digitos(z);

  printf("[%d]",soma);
}
