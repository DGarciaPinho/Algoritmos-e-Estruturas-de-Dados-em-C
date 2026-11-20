/*1. Desenvolva um programa em C para realizar as operações a seguir:
(a) Declare um arranjo de caracteres com 30 posições.
(b) Leia uma palavra, isto é, uma string que não contém espaços em branco, utilizando a função scanf com o
formatador %s. Limite a quantidade de caracteres lidos para evitar que a capacidade do arranjo seja
ultrapassada.
(c) Imprima a palavra utilizando a função printf com o formatador %s.
(d) Imprima a palavra utilizando a função puts.
(e) Percorra a string e imprima cada um de seus caracteres utilizando a função printf com o formatador %c. Os
caracteres deverão ser apresentados em uma única linha */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  //A)
  char *ptr = malloc(30 * sizeof(char));

  //B)
  scanf("%s",ptr);

  //C)
  printf("%s \n",ptr);

  //D)
  puts(ptr);
  printf("\n");

  //E)
  for(int i=0;i<30;++i){
    printf("%c \n",ptr[i]);
  }
}
