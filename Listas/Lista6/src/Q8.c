/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

8. Implemente a função:
int contarCaractere(const char *str, const char caractere);
A função deverá retornar a quantidade de vezes que o caractere informado aparece na string. A comparação
deverá diferenciar letras maiúsculas de minúsculas. Portanto, por exemplo, os caracteres 'A' e 'a' deverão ser
considerados diferentes. Desenvolva um programa para ler uma string e um caractere, chamar a função e
imprimir a quantidade encontrada. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contarCaractere(const char *str, const char caractere){
  int vezes = 0,i=0;

  while(str[i]!='\0'){
    if(str[i]==caractere){
      vezes++;
    }
    i++;
  }
  
  return vezes;
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str1 = calloc(n+1,sizeof(char));
  printf("=====================\n");
  printf("Digite a String1 :\n");
  printf("=====================\n");

  fgets(str1,n+1,stdin);

  char m;

  printf("=====================\n");
  printf("Digite a letra :\n");
  printf("=====================\n");

  scanf(" %c",&m);

  int z = contarCaractere(str1,m);

  printf("=====================\n");
  printf("A letra [%c] apareceu : [%d] :\n",m,z);
  printf("=====================\n");

}
