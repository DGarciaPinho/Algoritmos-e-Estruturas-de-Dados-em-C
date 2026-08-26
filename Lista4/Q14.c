/*14. Utilizando um vetor estático de 10 números inteiros, implemente void contar(int
*vetor, int tamanho, int *positivos, int *negativos, int *zeros). A função
deverá percorrer o vetor utilizando aritmética de ponteiros e informar, por meio
dos parâmetros, a quantidade de valores positivos, negativos e iguais a zero.*/
#include <stdio.h>

void contar(int *vetor, int tamanho, int *positivos, int *negativos, int *zeros){
  for(int i=0;i<tamanho;++i){
    if(*vetor==0){
      *zeros = *zeros + 1;
    }else if(*vetor > 0){
      *positivos = *positivos + 1;
    }else{
      *negativos = *negativos + 1;
    }
    vetor++;
  }
}

void main(){
  int n;
  printf("Digite o numero de elementos : \n");
  scanf("%d",&n);

  int arr[n];

  for(int i=0;i<n;++i){
    printf("Digite o elemento %d",i+1);
    scanf("%d",&arr[i]);
  }

  int ne=0,po=0,ze=0;

  contar(arr,n,&po,&ne,&ze);

  printf("Positivos : %d, Negativos : %d, Zeros : %d", po,ne,ze);
}
