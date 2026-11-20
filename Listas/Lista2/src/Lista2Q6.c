// 6. Um vetor de 9 posições contém números inteiros distintos pertencentes ao 
// intervalo de 1 a 10. Exatamente um número desse intervalo não está 
// presente no vetor. Determine qual é o número ausente.
// Exemplo: 1 2 3 4 6 7 8 9 10 → Número ausente: 5.

#include <stdio.h>

void main(){
  int v[9],valores[10]={1,2,3,4,5,6,7,8,9,10};

  for(int i=0;i<9;++i){
    printf("Insira o %d número : \n ",i+1);
    scanf("%d",&v[i]);
  }

  for(int i=0;i<10;++i){
    for(int j=0;i<10;++i){
      if(v[i]==valores[j]){
        valores[j] = 0;
      }
    }
  }

  for(int i=0;i<10;++i){
    if(valores[i]!=0){
      printf("O número ausente é %d",valores[i]);
    }
  }
}
