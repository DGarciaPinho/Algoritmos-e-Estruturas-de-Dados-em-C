/*
21. Implemente uma função que procure um determinado valor em um vetor estático
usando o cabeçalho int *buscar(int *vetor, int tamanho, int valor). Caso o
valor seja encontrado, a função deverá retornar um ponteiro para a primeira ocorrên-
cia encontrada. Caso contrário, deverá retornar NULL. No programa principal, caso o
valor seja encontrado, determine sua posição utilizando aritmética de ponteiros.
*/

#include <stdio.h>


int *buscar(int *vetor, int tamanho, int valor){
  for(int i=0;i<tamanho;++i){
    if(*vetor==valor){
      return vetor;
    }
    vetor++;
  }
  return nullptr;
}

void main(){
  int arr[10],n;

  for(int i=0;i<10;++i){
    scanf("%d",&arr[i]);
  }

  printf("Digite o valor que vc quer buscar : \n");
  scanf("%d",&n);

  int *ptr = buscar(arr,10,n);

  printf("A primeira ocorrencia é : %d",ptr-arr+1);
}
