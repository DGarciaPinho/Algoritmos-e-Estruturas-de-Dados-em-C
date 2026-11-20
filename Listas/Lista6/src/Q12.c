/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

12. Implemente a função:
void inverterString(char *str);
A função deverá inverter a ordem dos caracteres da própria string recebida. Não deverá ser criado outro arranjo
para armazenar a string invertida. Por exemplo, a string “algoritmo” deverá ser transformada em “omtirogla”.
Desenvolva um programa para ler uma string, chamar a função e imprimir o resultado.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void inverterString(char *str){
  int i=0,j=0;
  while(str[i]!='\0'){
    i++;
  }

  i--;

  char temp;

  while(i>j){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i--;
    j++;
  }
}

void main(){
  int n;
  printf("digite o tamanho da string\n");
  scanf("%d",&n);

  char *str = calloc(n+1,sizeof(char));

  printf("digite a string agora : ");

  getchar();
  fgets(str,n,stdin);

  printf("String : [%s] , Endereço [%p]",str,str);

  inverterString(str);

  printf("A nova string é [%s] no mesmo endereço [%p]",str,str);
}
