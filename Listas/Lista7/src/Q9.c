/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

9. Escreva uma função recursiva que conta a quantidade de vezes que um caractere informado aparece em uma
string informada.
*/

#include <stdio.h>
#include <stdlib.h>

int contar(const char *str,const char c){
  if(*str=='\0' || *str=='\n'){
    return 0;
  }else{
    return (*str == c) + contar(str+1,c);
  }
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

  printf("=====================\n");
  printf("Digite o char :\n");
  printf("=====================\n");

  char c;
  scanf("%c",&c);

  int vezes = contar(str1,c);

  printf("=====================\n");
  printf("O char [%c] apareceu : [%d] \n",c,vezes);
  printf("=====================\n");

}
