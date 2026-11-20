/*
 * Crie um programa que escreva de 1 até 10 em um arquivo, armazenando um número por linha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 

void main(){
  
  FILE *arq = fopen("saida.txt", "w");
  if (arq == NULL) {
        perror("Erro ao abrir saida.txt");
        return 1;
  }

  for(int i=0;i<10;++i){
    fprintf(arq, "[%d] \n", i);
  }

  fclose(arq);
}
