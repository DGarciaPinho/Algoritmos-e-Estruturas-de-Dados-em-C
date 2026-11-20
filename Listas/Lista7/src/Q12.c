/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

12. Implemente uma função recursiva que retorna o maior elemento de um vetor de inteiros de tamanho n.
*/

#include <stdio.h>
#include <stdlib.h>

int maior(const int *vetor, int n) {
  if (n == 1) {
    return vetor[0];
  }

  int maior_restante = maior(vetor + 1, n - 1);

  if (vetor[0] > maior_restante) {
    return vetor[0];
  }

  return maior_restante;
}

int main(void) {
  int n;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("O tamanho deve ser maior que zero.\n");
    return 1;
  }

  int *vetor = malloc(n * sizeof(int));

  if (vetor == NULL) {
    printf("Erro ao alocar memoria.\n");
    return 1;
  }

  printf("Digite os %d elementos do vetor:\n", n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }

  printf("Maior elemento: %d\n", maior(vetor, n));

  free(vetor);
  return 0;
}
