/*
2. Desenvolva um programa em C para realizar as operações a seguir:
(a) Declare um arranjo de caracteres com 100 posições.
(b) Leia uma frase, isto é, uma string que pode conter espaços em branco, utilizando a função scanf com o
formatador %[^\n]. Limite a quantidade de caracteres lidos para evitar que a capacidade do arranjo seja
ultrapassada.
(c) Imprima a frase utilizando a função printf com o formatador %s.
(d) Imprima a frase utilizando a função puts.
(e) Percorra a string e imprima cada um de seus caracteres em uma linha diferente. Os espaços em branco
também deverão ser impressos, produzindo uma linha aparentemente vazia na saída.
(f) Percorra novamente a string e imprima seus caracteres em uma única linha, desconsiderando todos os
espaços em branco. A string original não deverá ser modificada.
*/ 

#include <stdio.h>
#include <stdlib.h>

void main(){
  //A)
  char *arr = calloc(100,sizeof(char));

  //B)
  scanf("%[^\n]", arr);

  //C)
  printf("%s \n",arr);

  //D)
  puts(arr);

  //E)
  for(int i=0;i<100;++i){
    printf("%c \n",arr[i]);
  }

  //F)
  for(int i=0;arr[i]!='\0';i++){
    if((arr[i]!=' ')){
      printf("%c \n",arr[i]);
    }
  }
}
