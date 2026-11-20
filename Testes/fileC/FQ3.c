#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int matricula;
  char nome[50];
}Aluno;

Aluno lerAluno(){
  printf("Lendo Aluno...");
  Aluno *ptr = calloc(1,sizeof(Aluno));

  // Codigo 
   
  printf("Digite a matricula : \n");
  scanf("%d",&ptr->matricula);
  getchar();

  // Descrição

  printf("Digite o nome : \n");
  fgets(ptr->nome,50, stdin);

  int i=0;

  while (ptr->nome[i] != '\0') {
      if (ptr->nome[i] == '\n') {
          ptr->nome[i] = '\0';
          break;
      }

      i++;
  }

  return *ptr;
}

void imprimirAlunos(Aluno *ptr){
  FILE *arq = fopen("saida.txt", "r");
    if (arq == NULL) {
        perror("Erro");
    }
    char linha[100];
    int n = 1;
    while (fgets(linha, sizeof(linha), arq) != NULL){
        linha[strcspn(linha, "\n")] = '\0';
        printf("Linha %d: [%s]\n", n++, linha);
    }
    printf("\n");
    fclose(arq);
}

void main(){
  int n;
  printf("Digite quantos alunos : \n");
  scanf("%d",&n);
  Aluno lista[n];

  for(int i=0;i<n;++i){
    lista[i] = lerAluno();
    printf("Teste : %d %d \n",i+1,lista[i].matricula);
  }

  FILE *arq = fopen("saida.txt", "w");
    if (arq == NULL) {
        perror("Erro ao abrir saida.txt");
    }

  for(int i=0;i<n;++i){
    fprintf(arq, "Aluno [%d] | Matricula [%d] | Nome [%s] \n", i, lista[i].matricula, lista[i].nome);
  }

  fclose(arq);

  int p = 1;

  while(p!=0){ 
    printf("Dados armazenados | 2 \n");
    printf("Sair do programa | 0 \n");

    scanf("%d",&p);

    if(p == 2){
      imprimirAlunos(lista);
    }else if(p == 1){
      continue;
    }

  }
}
