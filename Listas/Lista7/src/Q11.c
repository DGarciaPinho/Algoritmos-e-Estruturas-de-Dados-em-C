/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

11. Implemente uma função recursiva que verifica se duas strings são iguais.
*/

#include <stdio.h>
#include <stdlib.h>

int iguais(const char *str1, const char *str2) {
  if (*str1 != *str2) {
    return 0;
  }

  if (*str1 == '\0') {
    return 1;
  }

  return iguais(str1 + 1, str2 + 1);
}

int main(void) {
  int n;

  printf("=====================\n");
  printf("Digite o tamanho maximo das strings:\n");
  printf("=====================\n");
  scanf("%d", &n);
  getchar();

  if (n <= 0) {
    printf("O tamanho deve ser maior que zero.\n");
    return 1;
  }

  char *str1 = malloc((n + 2) * sizeof(char));
  char *str2 = malloc((n + 2) * sizeof(char));

  if (str1 == NULL || str2 == NULL) {
    printf("Erro ao alocar memoria.\n");
    free(str1);
    free(str2);
    return 1;
  }

  printf("=====================\n");
  printf("Digite a primeira string:\n");
  printf("=====================\n");
  fgets(str1, n + 2, stdin);

  printf("=====================\n");
  printf("Digite a segunda string:\n");
  printf("=====================\n");
  fgets(str2, n + 2, stdin);

  if (iguais(str1, str2)) {
    printf("As strings sao iguais.\n");
  } else {
    printf("As strings sao diferentes.\n");
  }

  free(str1);
  free(str2);
  return 0;
}
