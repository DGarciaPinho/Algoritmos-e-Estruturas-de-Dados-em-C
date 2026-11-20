// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 3. (Alunos de uma turma) Uma turma possui vários alunos, cada um identificado por matrícula, nome e nota.
// Desenvolva um programa em C para cadastrar os alunos e apresentar informações sobre o desempenho da
// turma, seguindo as etapas abaixo.
//
// (a) Cadastro da turma
//
// Reutilize a struct Aluno definida no exercício anterior. Na função main, declare um arranjo com capacidade
// para armazenar 50 alunos. Leia a quantidade de alunos da turma, que deve estar entre 1 e 50. Em seguida,
// preencha os dados de cada aluno utilizando a função lerAluno do exercício anterior. Considere que as notas
// informadas estão entre 0 e 10.
//
// (b) Listagem da turma
//
// Crie uma função que receba o arranjo e a quantidade de alunos e imprima os dados de todos eles. Utilize a
// função imprimirAluno para apresentar cada registro.
//
// (c) Nota média da turma
//
// Crie uma função que receba o arranjo e a quantidade de alunos e retorne a média das notas da turma. Na
// função main, imprima o resultado com duas casas decimais.
//
// (d) Quantidade de aprovados e reprovados
//
// Crie uma função que receba o arranjo e a quantidade de alunos e retorne a quantidade de aprovados. Na
// função main, imprima as quantidades de aprovados e reprovados. Determine a quantidade de reprovados a
// partir do total de alunos e da quantidade de aprovados.
//
// (e) Listagem dos aprovados e reprovados
//
// Crie duas funções: uma para imprimir os dados dos alunos aprovados e outra para imprimir os dados dos
// reprovados. Ambas devem receber o arranjo e a quantidade de alunos e utilizar imprimirAluno para
// apresentar cada registro.
//
// (f) Maior nota da turma
//
// Crie uma função que receba o arranjo e a quantidade de alunos e retorne a maior nota encontrada. Na
// função main, imprima essa nota e os dados de todos os alunos que a obtiveram.
//
// (g) Alunos acima da média
//
// Utilizando a média calculada na etapa (c), imprima os dados dos alunos cuja nota seja estritamente maior
// que a média da turma.

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

void aprovados(Aluno *aluno, int n,int *aprovados,int *reprovados){
  for(int i=0;i<n;++i){
    if(aluno[i]->nota >= 7){
      printf("Aprovado : \n");
      imprimirAluno(aluno[i]);
    }else{
      printf("Reprovado : \n");
      imprimirAluno(aluno[i]);
    }
  }
}

void main(){
  int n;
  printf("Digite o numero de alunos : \n");
  scanf("%d",&n);
  getchar();

  int media;


  Aluno *ptr = calloc(n,sizeof(Aluno));

  for(int i=0;i<n;++i){
    lerAluno(&ptr[i]);
    media = ptr[i]->nota;
  }

  media = media / n ;

  for(int i=0;i<n;++i){
    imprimirAluno(ptr[i]);
  }

  int maior = ptr[0]->nota;

  for(int i=1;i<n;++i){
    if(ptr[i]->nota>maior){
      maior = ptr[i]->nota;
    }
  }
  int aprovados = 0, reprovados = 0;

  aprovados(ptr,n,&aprovados,&reprovados);

  printf("Media da turma : %d \n",media);

  printf("Maior nota da turma : %d \n",maior);

  free(ptr);
}
