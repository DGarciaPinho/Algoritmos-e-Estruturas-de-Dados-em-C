/*1. Leia 20 números inteiros e armazene-os em um vetor. Em seguida, construa dois
novos vetores: um contendo apenas os valores negativos e outro contendo os valores
maiores ou iguais a zero. Apresente os dois vetores ao final.*/

#include <stdio.h>

void main(){
  int v[20],menosn=0,maisn=0;

  for(int i=0;i<20;++i){ // Leitura dos dados 
    scanf("%d ",&v[i]);

    if(v[i]>=0){
      maisn++;
    }else{
      menosn++;
    }
  }

  int vp[maisn];
  int vn[menosn];

  for(int i=0;i<20;++i){ // Comparação e copia dos dados para respectivos vetores 
    if(v[i]>=0){
      maisn = maisn - 1;
      vp[maisn] = v[i];
    }else{
      menosn = menosn - 1;
      vn[menosn] = v[i];
    }
  }

  for(int i=0;i<20;i++){
    printf("indice %d dos positivos | Valor : %d \n ",i,vp[i]);
    printf("indice %d dos negativos | Valor : %d \n ",i,vn[i]);
  }
}
