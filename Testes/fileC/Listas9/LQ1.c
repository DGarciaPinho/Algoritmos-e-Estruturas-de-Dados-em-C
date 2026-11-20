/*
1. Crie um programa para manipular arquivos, conforme os passos a seguir.
(a) Escreva de 1 até 10 em um arquivo chamado “exercicio1.txt”, armazenando um número por linha. Confira o
arquivo em um editor de texto.
(b) Abra o mesmo arquivo em modo atualização e adicione os números de 11 a 20 ao fim do arquivo, um
número por linha. Ao final, seu arquivo terá os números de 1 a 20. Confira o arquivo em um editor de texto.
(c) Leia o conteúdo do mesmo arquivo e imprima todos os números lidos separados por espaço no console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  FILE *arq = fopen("LQ1.txt", "w");
  if (arq == NULL) {
        perror("Erro ao abrir LQ1.txt");
  }

  for(int i=0;i<10;++i){
    fprintf(arq, "[%d] \n", i+1);
  }

  fclose(arq);

  FILE *arqe = fopen("LQ1.txt","a+");

  for(int i=10;i<20;++i){
    fprintf(arqe,"[%d] \n", i+1);
  }

  fclose(arqe);
}
