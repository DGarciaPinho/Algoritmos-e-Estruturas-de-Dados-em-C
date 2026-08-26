/*
19. Implemente uma função que receba um vetor estático e retorne um ponteiro para o
maior elemento encontrado usando o cabeçalho int *maiorElemento(int *vetor,
int tamanho). No programa principal, utilize o ponteiro retornado para exibir:
• o maior valor;
• o endereço do maior elemento;
• a posição do elemento no vetor, sendo esta calculada utilizando a diferença entre
ponteiros..
*/

#include <stdio.h>

int *maiorElemento(int *vetor, int tamanho){
  int *maior = vetor;
  int m = *vetor;
  for(int i=0;i<tamanho;++i){
    if(*vetor > m){
      m = *vetor;
      maior = vetor;
    }
    vetor++;
  }
  return maior;
}

void main(){
  int n;
  printf("Digite o valor de n \n");
  scanf("%d",&n);
 
  int arr[n];

  for(int i=0;i<n;++i){
    printf("Elemento [%d] : \n",i+1);
    scanf("%d",&arr[i]);
  }

  int *ptr = maiorElemento(arr,n);

  printf("O valor %d \n",*ptr);
  printf("Endereço %p \n ",ptr);
  printf("Posição %d \n",ptr-arr+1);
}
