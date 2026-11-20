// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 7. (Lista encadeada de tarefas) - versão corrigida de Q7.c
//
// Observação sobre o enunciado: o item (f) diz que removerFinal deve liberar a tarefa, mas
// também diz que ela retorna Tarefa*, e o item (h) pede para imprimir a tarefa removida e
// depois desalocá-la. Retornar um ponteiro já liberado seria um erro (use-after-free), então
// aqui removerFinal libera só a CÉLULA e devolve a tarefa; quem chama imprime e dá free nela.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int codigo;
  char descricao[51];
}Tarefa;

typedef struct Celula{
  Tarefa *tarefa;
  struct Celula *proxima;
}Celula;

typedef struct{
  Celula *primeira;
}Lista;

Lista *criarLista(){
  Lista *lista = malloc(sizeof(Lista));
  if(lista == NULL){
    return NULL;
  }
  lista->primeira = NULL;
  return lista;
}

Tarefa *lerTarefa(){
  Tarefa *tarefa = malloc(sizeof(Tarefa));
  if(tarefa == NULL){
    return NULL;
  }

  printf("Codigo : \n");
  scanf("%d",&tarefa->codigo);
  getchar();
  printf("Descrição : \n");
  fgets(tarefa->descricao,sizeof(tarefa->descricao),stdin);
  tarefa->descricao[strcspn(tarefa->descricao,"\n")] = '\0';

  return tarefa;
}

void imprimirTarefa(const Tarefa *tarefa){
  printf("Codigo : [%d] \n",tarefa->codigo);
  printf("Descrição : [%s] \n",tarefa->descricao);
}

int inserirFinal(Lista *lista, Tarefa *tarefa){
  Celula *nova = malloc(sizeof(Celula));
  if(nova == NULL){
    return 0; 
  }
  nova->tarefa = tarefa;
  nova->proxima = NULL;

  if(lista->primeira == NULL){
    lista->primeira = nova;
  }else{
    Celula *atual = lista->primeira;
    while(atual->proxima != NULL){
      atual = atual->proxima;
    }
    atual->proxima = nova;
  }

  return 1;
}

void listarTarefas(const Lista *lista){
  if(lista->primeira == NULL){
    printf("A lista está vazia. \n");
    return;
  }

  for(Celula *atual = lista->primeira; atual != NULL; atual = atual->proxima){
    printf("===================== \n");
    imprimirTarefa(atual->tarefa);
  }
  printf("===================== \n");
}

Tarefa *removerFinal(Lista *lista){
  // Lista vazia
  if(lista->primeira == NULL){
    return NULL;
  }

  Tarefa *tarefa;

  if(lista->primeira->proxima == NULL){
    tarefa = lista->primeira->tarefa;
    free(lista->primeira);
    lista->primeira = NULL;
    return tarefa;
  }

  Celula *penultima = lista->primeira;
  while(penultima->proxima->proxima != NULL){
    penultima = penultima->proxima;
  }

  tarefa = penultima->proxima->tarefa;
  free(penultima->proxima);
  penultima->proxima = NULL;

  return tarefa;
}

void liberarLista(Lista *lista){
  Celula *atual = lista->primeira;
  while(atual != NULL){
    Celula *proxima = atual->proxima; 
    free(atual->tarefa);
    free(atual);
    atual = proxima;
  }
  lista->primeira = NULL;
}

int main(){
  Lista *lista = criarLista();
  if(lista == NULL){
    printf("Erro ao criar a lista. \n");
    return 1;
  }

  int op;

  do{
    printf("\n1. Adicionar uma tarefa ao final \n");
    printf("2. Listar as tarefas \n");
    printf("3. Remover a última tarefa \n");
    printf("4. Encerrar o programa \n");
    printf("Opção : ");

    if(op == 1){
      Tarefa *tarefa = lerTarefa();
      if(tarefa == NULL){
        printf("Falha ao alocar a tarefa. \n");
      }else if(!inserirFinal(lista,tarefa)){
        free(tarefa);
        printf("Falha ao alocar a célula: tarefa não adicionada. \n");
      }else{
        printf("Tarefa adicionada. \n");
      }
    }else if(op == 2){
      listarTarefas(lista);
    }else if(op == 3){
      Tarefa *removida = removerFinal(lista);
      if(removida == NULL){
        printf("A lista estava vazia. \n");
      }else{
        printf("Tarefa removida: \n");
        imprimirTarefa(removida);
        free(removida);
      }
  }while(op != 4);

  liberarLista(lista);
  free(lista);

  return 0;
}
