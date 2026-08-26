/*
23. Implemente uma função que receba um vetor estático e faça dois ponteiros apontarem,
respectivamente, para o menor e para o maior elemento do vetor. Utilize o cabeçalho
void localizarExtremos(int *vetor, int tamanho, int **menor, int **maior).
No programa principal, exiba os valores e as posições dos elementos apontados por
menor e maior. As posições deverão ser calculadas por meio da diferença entre
ponteiros.
*/

#include <stdio.h>

void localizarExtremos(int *vetor, int tamanho, int **menor, int **maior){
  int sm = vetor,bg = vetor;
  *menor = &sm;
  *maior = &bg;

  for(int i=0;i<tamanho;++i){
    if(*vetor>bg){
      *maior = vetor;
      bg = *vetor;
    }else if(*vetor<sm){
      *menor = vetor;
      sm = *vetor;
    }
    vetor++;
  }
}

void main(){
  int arr[10];

  for(int i=0;i<10;++i){
    printf("Digite o elemento [%d]",i+1);
    scanf("%d",&arr[i]);
  }

  int *ptrM = NULL;
  int *ptrm = NULL;

  localizarExtremos(&arr,10,&ptrm,&ptrM);

  printf("Ponteiro do Maior : Valor = %d, e indice = %d",*ptrM,ptrM-arr);
  printf("Ponteiro do Menor : Valor = %d, e indice = %d",*ptrm,ptrm-arr);

}
