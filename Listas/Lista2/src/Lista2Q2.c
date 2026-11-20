/*2. Leia 10 números inteiros e verifique se o vetor é um palíndromo, isto é, se possui
a mesma sequência de valores quando percorrido da esquerda para a direita e da
direita para a esquerda. Exemplos: 2 5 8 8 5 2 é um palíndromo enquanto 2 5 8 7
5 2 não o é.*/ 

#include <stdio.h>

void main(){
  int v=0,temp,tam=0;

  for(int i=0;i<10;i++){
    scanf("%d",&temp);
    v = (v*10) + temp;
    tam++;
  }

  int original = v;
  int invertido = 0;

  while(tam>0){
    invertido = (invertido * 10) + v % 10;
    v/=10;
    tam--;
  }


  if(original == invertido){
    printf("é palindromo");
  }else{
    printf("Não é palindromo");
  }
}
