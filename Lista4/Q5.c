/*
5. Implemente uma função com o cabeçalho void incrementar(int *valor). A função
deverá acrescentar uma unidade ao conteúdo da variável apontada por valor. No
programa principal, leia um número inteiro, chame a função e exiba o valor antes e
depois da chamada.
*/

#include <stdio.h>

void incrementar(int *valor){
  *valor = *valor + 1;
}

void main(){
  int a;
  scanf("%d",&a);

  incrementar(&a);

  printf("Novo valor de a %d",a);
}
