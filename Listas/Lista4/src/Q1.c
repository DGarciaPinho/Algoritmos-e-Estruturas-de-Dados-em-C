/*
1. Escreva um programa em C que declare uma variável inteira e um ponteiro para essa
variável. Leia um valor para a variável e, em seguida, exiba:
(a) o valor armazenado na variável;
(b) o endereço da variável;
(c) o conteúdo armazenado no ponteiro;
(d) o valor acessado por meio do ponteiro
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
  int n = 1;
  int *ptr = &n;

  printf("%d",n);
  printf("%p",&n);
  printf("%p",ptr);
  printf("%d",*ptr);
}
