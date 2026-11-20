/* 
5. Faça um programa que leia os elementos de um vetor e altere sua organização real-
izando uma rotação de uma posição para a direita. Após essa operação, o elemento
que originalmente estava na última posição deverá aparecer no início do vetor, en-
quanto os demais deverão manter sua ordem relativa. A operação deverá ser real-
izada sem o uso de um vetor auxiliar.
Exemplo:
Vetor original:
1 2 3 4 5
Vetor resultante:
5 1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

//EMPURRAR A EM B  
void push(int *a,int *b){
  *b = *a;
}

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  int n;

  printf("Digite o valor de n : \n ");
  scanf("%d",&n);

  int *ptr = calloc(n,sizeof(int));;

  for(int i=0;i<n;++i){
    printf("\n Digite o elemento [%d]: ",i+1);
    scanf("%d",&ptr[i]);
  }

  int a = ptr[n-1];
  
  // Nesse loop vamos sobreescrever ptr[n] com ptr[n-1]
  for(int i=n-2;i>=0;--i){
    push(&ptr[i],&ptr[i+1]);
  }
  ptr[0] = a;

  for(int i=0;i<n;++i){
    printf("%d,",ptr[i]);
  }

}
