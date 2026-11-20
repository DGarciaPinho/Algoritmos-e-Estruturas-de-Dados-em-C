/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

9. Implemente a função:
int localizarCaractere(const char *str, const char caractere);
A função deverá procurar a primeira ocorrência do caractere informado na string e retornar sua posição. Caso o
caractere não seja encontrado, a função deverá retornar -1. As posições da string deverão ser numeradas a
partir de zero. Desenvolva um programa para ler uma string e um caractere, chamar a função e imprimir o
resultado.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int localizarCaractere(const char *str, const char caractere){
  int i=0,j;

  while(str[i]!='\0'){
    if(str[i]==caractere){
      j = i;
      
      return j;
    }
    i++;
  }

  return -1;
}

void main(){
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

  char m = 'o'; 
  
  printf("=====================\n");
  printf("Digite a letra :\n");
  printf("=====================\n");

  m = getchar();
 
  int z = localizarCaractere(str1,m);

  printf("=====================\n");
  printf("Primeira ocorrencia de [%c] : [%d]\n",m,z);
  printf("=====================\n");

}
