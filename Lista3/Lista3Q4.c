/* 
4. Considere um vetor que ainda possua espaço disponível para armazenar novos ele-
mentos. Faça um programa que leia os valores inicialmente presentes no vetor e, de-
pois, leia um novo valor e a posição em que ele deverá ser inserido. Após a inserção,
todos os valores deverão aparecer na ordem correta, incluindo o novo elemento na
posição informada.
Exemplo:
Vetor:
10 20 30 40
Novo valor: 99
Posicao: 2
Vetor resultante:
10 20 99 30 40
*/ 

#include <stdio.h>
#include <stdlib.h>

//EMPURRAR A EM B  
void push(int *a,int *b){
  *b = *a;
}

void main(){
  int n;

  printf("Digite o número de valores : \n ");
  scanf("%d",&n);

  int *ptr = calloc(n+1,sizeof(int));

  for(int i=0;i<n;++i){
    printf("\n Digite o elemento [%d]: ",i+1);
    scanf("%d",&ptr[i]);
  }

  int a,x;
  printf("\n Digite o indice para o valor X entrar : \n");
  scanf("%d",&a);
  printf("\n Digite o valor de X :");
  scanf("%d",&x);

 
  for(int i=n-1;i>=a;--i){
    push(&ptr[i],&ptr[i+1]);
  }
  ptr[a] = x;

  for(int i=0;i<=n;++i){
    printf("%d,",ptr[i]);
  }
}
