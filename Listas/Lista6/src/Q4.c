/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

4. Implemente a função:
int comprimentoString(char *str);
A função deverá receber uma string e retornar a quantidade de caracteres nela armazenados, sem considerar o
caractere nulo '\0'. Desenvolva um programa para ler uma string, chamar a função e imprimir o comprimento
calculado.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comprimentoString(char *str){
  int tamanho=0,i=0;
  
  while(str[i]!='\0'){
    tamanho = (i+1);
    i++;
  }

  return tamanho;
}

void main (){
  
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str = calloc(n+1,sizeof(char));

  printf("=====================\n");
  printf("Digite a String :\n");
  printf("=====================\n");

  fgets(str,n+1,stdin);

  int z = comprimentoString(str);

  printf("=====================\n");
  printf("O tamanho da String é igual a : %d \n",z);
  printf("=====================\n");

}
