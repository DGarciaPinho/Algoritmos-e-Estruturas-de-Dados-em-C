#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct{
  char titulo[100];
  Data Publicacao;
}Livro;

void lerLivro(Livro *livro){
  printf("===\n");
  printf("Livro  \n");
  printf("===\n");
  printf("Titulo : \n");
  fgets(livro->titulo,100, stdin);

  int i=0;

  while (livro->titulo[i] != '\0') {
      if (livro->titulo[i] == '\n') {
          livro->titulo[i] = '\0';
          break;
      }

      i++;
  }

  printf("Dia : \n");
  scanf("%d",&livro->Publicacao.dia);
  printf("Mes : \n");
  scanf("%d",&livro->Publicacao.mes);
  printf("Ano : \n");
  scanf("%d",&livro->Publicacao.ano);
  getchar();
}

void imprimirLivro(const Livro *livro){
  printf("Titulo : [%s] \n",livro->titulo);
  printf("Data : [%d/%d/%d]\n",livro->Publicacao.dia,livro->Publicacao.mes,livro->Publicacao.ano);
}

void main(){
  int n;
  printf("Digite o numero de livros a serem registrados : \n");
  scanf("%d",&n);
  getchar(); 

  Livro *livros = calloc(n,sizeof(Livro));

  for(int i=0;i<n;++i){
    lerLivro(&livros[i]);
  }

  for(int i=0;i<n;++i){
    imprimirLivro(&livros[i]);
  }
}
