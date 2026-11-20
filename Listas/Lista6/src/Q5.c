/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

5. Implemente a função:
void copiarString(const char *origem, char *destino);
A função deverá copiar todos os caracteres da string origem para a string destino, incluindo o caractere nulo '\0'.
Desenvolva um programa para ler uma string, copiá-la para outro arranjo e imprimir a string copiada.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copiarString(const char *origem, char *destino){
  int i=0;
  while(origem[i]!='\0'){
    destino[i] = origem[i];
  }
}

void main(){
  
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str = calloc(n+1,sizeof(char));
  char *strcp = calloc(n+1,sizeof(char));

  printf("=====================\n");
  printf("Digite a String :\n");
  printf("=====================\n");

  fgets(str,n+1,stdin);

  copiarString(str,strcp);

  printf("=====================\n");
  printf("String nova : [%s]\n",strcp);
  printf("=====================\n");

}

