/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

6. Implemente uma função recursiva que, dado um vetor de inteiros de tamanho n, retorna um novo vetor de
tamanho n com os elementos do vetor recebido em ordem invertida. O vetor recebido como parâmetro não
pode ser alterado.
*/

#include <stdio.h>
#include <stdlib.h>

int *inverter(const int *ptr1,int n){
  if(n==1){
    int *new = malloc(sizeof(int));
    new[0] = ptr1[0];

    return new;
  }

  int *new = inverter(ptr1+1,n-1);

  new = realloc(new,n*sizeof(int));
  
  new[n-1] = ptr1[0];

  return new;
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);

  int *ptr = calloc(n,sizeof(int));

  for(int i=0;i<n;++i){
    printf("Elemento [%d] \n",i+1);
    scanf("%d",&ptr[i]);
  }

  int *ptrclone;

  ptrclone = inverter(ptr,n);

  printf("Vetor invertido : \n");

  for(int i=0;i<n;++i){
    printf("[%d]",ptrclone[i]);
  }
}
