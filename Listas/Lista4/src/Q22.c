/*
22. Considere as variáveis int a, int b e int *p, declaradas no programa principal. Im-
plemente a função void apontaMaior(int **p, int *a, int *b). A função deverá
fazer com que p passe a apontar para a variável que contém o maior valor. Caso os
valores sejam iguais, p deverá apontar para a. Após a chamada da função, o programa
principal deverá alterar o maior valor para zero utilizando somente o ponteiro p.
*/

#include <stdio.h>

void apontaMaior(int **p, int *a, int *b){
  if(*a > *b){
    *p = a;
  }else if(*b > *a){
    *p = b;
  }
}

void main(){
  int n,m;
  printf("Digite n : \n");
  scanf("%d",&n);
  printf("Digite m : \n");
  scanf("%d",&m);

  int *ptr = NULL;

  apontaMaior(&ptr,&n,&m);

  *ptr = 0;

  printf("Valor atual de n : %d \n Valor atual de m : %d",n,m);

}
