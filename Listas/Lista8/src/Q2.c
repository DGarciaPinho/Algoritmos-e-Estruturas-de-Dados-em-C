// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 2. Altere a versão final do exercício 1 para utilizar typedef para a struct Aluno, com o novo tipo também se
// chamando Aluno.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  short matricula;
  char nome[51];
  int nota;
}Aluno;

void imprimirAluno(Aluno aluno){

  printf("===================== \n");
  printf("Nome : [%s] \n",aluno.nome);
  printf("Matricula : [%d] \n",aluno.matricula);
  printf("Nota : [%d] \n",aluno.nota);
  printf("===================== \n");

}

void lerAluno(Aluno *aluno){
  printf("===\n");
  printf("ALUNO  \n");
  printf("Nome : \n");
  
  fgets(aluno->nome,50, stdin);

  int i=0;

  while (aluno->nome[i] != '\0') {
      if (aluno->nome[i] == '\n') {
          aluno->nome[i] = '\0';
          break;
      }

      i++;
  }

  printf("Matricula : \n");
  scanf("%d",&aluno->matricula);
  printf("nota : \n");
  scanf("%d",&aluno->nota);
  getchar();

  printf("===\n");


}

void main(){
  int n;
  printf("Digite o numero de alunos : \n");
  scanf("%d",&n);
  getchar();


  Aluno *ptr = calloc(n,sizeof(Aluno));

  for(int i=0;i<n;++i){
    lerAluno(&ptr[i]);
  }

  for(int i=0;i<n;++i){
    imprimirAluno(ptr[i]);
  }
}
