/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

10. Escreva uma função recursiva que recebe uma string, um caractere original e um caractere substituto. A função
deverá substituir, na própria string, todas as ocorrências do caractere original pelo caractere substituto. A função
deverá retornar a quantidade de substituições realizadas. Por exemplo, ao substituir 'a' por 'o' na string
“banana”, o resultado será “bonono”, e a função retornará 3. Desenvolva um programa para ler uma string e os
dois caracteres, chamar a função e imprimir a string modificada e a quantidade de substituições.
*/

#include <stdio.h>
#include <stdlib.h>

int contar(char *str, const char c, const char d) {
  if (*str == '\0' || *str == '\n') {
    return 0;
  }

  if (*str == c) {
    *str = d;
    return 1 + contar(str + 1, c, d);
  }

  return contar(str + 1, c, d);
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
  int i = 0;

  while (str1[i] != '\0') {
      if (str1[i] == '\n') {
          str1[i] = '\0';
          break;
      }

      i++;
  }

  printf("=====================\n");
  printf("Digite o char original :\n");
  printf("=====================\n");

  char c;
  scanf("%c",&c);
  getchar();

  printf("=====================\n");
  printf("Digite o char substituto :\n");
  printf("=====================\n");

  char d;
  scanf("%c",&d);


  int vezes = contar(str1,c,d);

  printf("=====================\n");
  printf("Nova string : [%s] | Trocas [%d] \n",str1,vezes);
  printf("=====================\n");

}
