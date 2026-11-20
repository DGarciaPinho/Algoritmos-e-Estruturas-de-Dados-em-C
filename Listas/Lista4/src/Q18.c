/*
18. Leia quatro números inteiros armazenados em quatro variáveis distintas e implemente
o procedimento void ordenar4(int *a, int *b, int *c, int *d). Ao final da exe-
cução da função, deverá ser satisfeita a condição:
∗a ≤ ∗b ≤ ∗c ≤ ∗d
Não utilize vetores ou matrizes auxiliares.
*/

#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void ordenar4(int *ptra, int *ptrb, int *ptrc, int *ptrd){
  for(int i=0;i<12;++i){
    if((*ptra>*ptrb)&&(*ptrb>*ptrc)&&(*ptrc>*ptrd)){
      break;
    }
    if(*ptra < *ptrb){
      swap(ptra,ptrb);
    }
    if(*ptrb < *ptrc){
      swap(ptrb,ptrc);
    }
    if(*ptrc < *ptrd){
      swap(ptrc,ptrd);
    }
  }
}

void main(){
  int a,b,c,d;
  printf("Digite o valor a, b, c e d : \n ");
  scanf("%d %d %d %d",&a,&b,&c,&d);

  ordenar4(&a,&b,&c,&d);

  printf("Novos endereços %d,%d,%d,%d",a,b,c,d);
}
