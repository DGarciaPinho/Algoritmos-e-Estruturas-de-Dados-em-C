/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

6. Implemente a função:
void concatenarStrings(const char *origem, char *destino);
A função deverá acrescentar os caracteres da string origem ao final da string destino. Desenvolva um programa
para ler duas strings, concatenar a segunda ao final da primeira e imprimir o resultado.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void concatenarStrings(const char *origem, char *destino){
  int i=0,j=0;

  while(destino[i]!='\0'){
    i++;
  }

  while(origem[j]!='\0'){
    destino[i] = origem[j];
    i++;
    j++;
  }

  detino[i]='\0';
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str1 = calloc(n+1,sizeof(char));
  char *str2 = calloc(n+1,sizeof(char));

  printf("=====================\n");
  printf("Digite a String1 :\n");
  printf("=====================\n");

  fgets(str1,n+1,stdin);

  printf("=====================\n");
  printf("Digite a String2 :\n");
  printf("=====================\n");

  fgets(str2,n+1,stdin);

  concatenarStrings(str1,str2);

  printf("=====================\n");
  printf("String nova : [%s]\n",str2);
  printf("=====================\n");

}
