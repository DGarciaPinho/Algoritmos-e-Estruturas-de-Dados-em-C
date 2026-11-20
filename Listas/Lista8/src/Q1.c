// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 1. (Cadastro de um aluno) Um programa deve armazenar e apresentar a matrícula, o nome e a nota de um aluno.
// Desenvolva o programa em C seguindo as etapas abaixo.
//
// (a) Definição da struct
//
// Defina uma struct Aluno com os seguintes campos:
//   - matricula: número inteiro;
//   - nome: vetor de caracteres com capacidade para armazenar até 50 caracteres, além do terminador '\0';
//   - nota: número real.
//
// (b) Inicialização e impressão
//
// Na função main, declare uma variável do tipo struct Aluno e utilize uma lista de inicialização para atribuir os
// seguintes dados:
//   - Matrícula: 20261001;
//   - Nome: "Ana Souza";
//   - Nota: 7.5.
//
// Em seguida, imprima todos os dados do aluno. Apresente a nota com uma casa decimal.
//
// (c) Impressão por uma função
//
// Altere o programa para que a impressão seja realizada pela função:
//
//     void imprimirAluno(struct Aluno aluno);
//
// A função deve receber o aluno e imprimir seus dados. Na função main, substitua os comandos de impressão
// por uma chamada a essa função.
//
// (d) Leitura por uma função
//
// Altere o programa para que os dados do aluno sejam digitados pelo usuário, substituindo a lista de
// inicialização pela leitura realizada pela função:
//
//     void lerAluno(struct Aluno *aluno);
//
// A função deve receber o endereço da variável e preencher seus campos com os dados digitados. A leitura do
// nome deve permitir espaços. Na função main, declare a variável, chame lerAluno para preencher seus dados
// e, depois, chame imprimirAluno para apresentá-los.

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
