/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

11. Implemente a função:
char* clonarStringInvertida(const char *str);
A função retornar um ponteiro para uma string alocada dinamicamente contendo os caracteres da string
recebida em ordem inversa. Por exemplo, a string “algoritmo” deverá ser transformada em “omtirogla”.
Desenvolva um programa para ler uma string, chamar a função e imprimir o resultado.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char* clonarStringInvertida(const char *str){
  int i=0, j=0;

  while(str[i]!='\0' && str[i]!='\n'){
    i++;
  }

  char *str2 = calloc(1+i,sizeof(char));

  i--;

  while(i>=0){
    str2[j] = str[i];
    j++;
    i--;
  }

  str2[j] = '\0';

  return str2;

}

int main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str1 = malloc((n+1) * sizeof(char));

  printf("=====================\n");
  printf("Digite a String1 :\n");
  printf("=====================\n");

  fgets(str1,n+1,stdin);

  char *ptr = clonarStringInvertida(str1);

  printf("=====================\n");
  printf("String Invertida : [%s]\n",ptr);
  printf("=====================\n");

  return 0;
}
