/*
3. Faça um programa em C que solicite ao usuário a quantidade de alunos de uma turma e leia
   a nota de cada aluno, armazenando-a em memória alocada dinamicamente. A nota é um número
   real de dupla precisão (double). Imprima todas as notas e também a média das notas.
*/
#include <stdio.h>
#include <stdlib.h>

void main(){
  int n;
  printf("Digite o numero de alunos : \n");
  scanf("%d",&n);

  /* 
  int **arr = malloc(2 * sizeof(int*));
  arr[0] = malloc(n * sizeof(int));
  arr[1] = malloc(n * sizeof(int));
  */

  double *ptr = malloc(n * sizeof(double));
  int soma =0;

  for(int i=0;i<n;++i){
    printf("Nota do aluno [%d]",i+1);
    scanf("%f",&ptr[i]);
    soma = soma + ptr[i];
  }
  
  soma = soma / n ;

  printf("Media da turma = %d \n ",soma);

  for(int i=0;i<n;++i){
    printf("Nota do aluno [%d] : %d \n ",i+1,ptr[i]);
  }
  
}
