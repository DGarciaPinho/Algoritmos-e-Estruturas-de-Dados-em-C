// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 7. (Lista encadeada de tarefas) Um programa deve manter uma lista de tarefas pendentes, permitindo adicionar
// tarefas ao final, consultar a listagem e remover a última tarefa. Desenvolva o programa em C seguindo as etapas
// abaixo.
//
// (a) Definição dos tipos
//
// Utilize typedef para definir os tipos:
//   - Tarefa: contém um campo inteiro codigo e um campo descricao, com capacidade para armazenar
//     até 50 caracteres, além do terminador '\0';
//   - Celula: contém um ponteiro tarefa, do tipo Tarefa*, e um ponteiro proxima, que aponta para a
//     próxima célula;
//   - Lista: contém um ponteiro primeira, do tipo Celula*, que aponta para a primeira célula.
//
// Cada célula e a tarefa associada devem ser alocadas separadamente. A lista não possui célula sentinela.
// Quando estiver vazia, seu campo primeira deve ser NULL.
//
// (b) Criação da lista
//
// Implemente a função:
//
//     Lista* ciarLista();
//
// A função alocar uma lista vazia dinamicamente (deve atribuir NULL ao campo primeira) e retornar um
// ponteiro para a listra criada.
//
// (c) Leitura e impressão de uma tarefa
//
// Implemente as funções:
//
//     Tarefa *lerTarefa();
//     void imprimirTarefa(const Tarefa *tarefa);
//
// A função lerTarefa deve alocar dinamicamente uma tarefa, ler seus campos e retornar seu endereço. A
// descrição deve permitir espaços. Caso a alocação falhe, deve retornar NULL. A função imprimirTarefa deve
// apresentar o código e a descrição da tarefa recebida.
//
// (d) Inserção no final
//
// Implemente a função:
//
//     int inserirFinal(Lista *lista, Tarefa *tarefa);
//
// A função deve alocar uma célula, armazenar nela o ponteiro recebido em tarefa e inseri-la no final da lista. O
// campo proxima da nova célula deve receber NULL. Se a lista estiver vazia, o campo primeira deve passar a
// apontar para a nova célula. Retorne 1 quando a inserção for realizada e 0 caso a alocação da célula falhe. Em
// caso de falha, a lista deve permanecer inalterada e a função não deve liberar a tarefa recebida.
//
// (e) Listagem das tarefas
//
// Implemente a função:
//
//     void listarTarefas(const Lista *lista);
//
// A função deve percorrer as células a partir de primeira e utilizar imprimirTarefa para apresentar cada tarefa,
// na ordem em que foi inserida. Caso a lista esteja vazia, apresente uma mensagem informando essa situação.
//
// (f) Remoção no final
//
// Implemente a função:
//
//     Tarefa* removerFinal(Lista *lista);
//
// A função deve remover a última célula e liberar tanto a tarefa associada quanto a própria célula. Considere
// os seguintes casos:
//   - Lista vazia: retorne NULL;
//   - Lista com uma única célula: realize a remoção e atualize primeira para NULL;
//   - Lista com várias células: atualize o campo proxima da penúltima célula para NULL.
//
// (g) Liberação da lista
//
// Implemente a função:
//
//     void liberarLista(Lista *lista);
//
// A função deve percorrer a lista, liberar todas as tarefas e células e atualizar o campo primeira para NULL.
//
// (h) Programa principal
//
// Na função main, declare uma variável do tipo Lista e utilize inicializarLista. Em seguida, apresente
// repetidamente o seguinte menu:
//
//   1. Adicionar uma tarefa ao final;
//   2. Listar as tarefas;
//   3. Remover a última tarefa;
//   4. Encerrar o programa.
//
// Para uma opção inexistente, apresente uma mensagem de opção inválida.
//
// Na inserção, utilize lerTarefa e inserirFinal. Se a leitura retornar NULL, informe a falha. Se a tarefa for criada, mas
// a inserção falhar, libere a tarefa e informe que ela não foi adicionada.
//
// Na remoção, informe se uma tarefa foi removida ou se a lista estava vazia. Caso tenha sido removida, imprimir a
// tarefa desaloca-la.
//
// Antes de encerrar, utilize liberarLista para liberar todas as tarefas e células alocadas dinamicamente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int codigo;
  char s[51];
}Tarefa;

typedef struct{
  Tarefa *tarefa;
  Celula *proxima;
}Celula;

typedef struct{
  Celula *primeira;
}Lista;

Lista* criarLista(){
  Lista *ptr = calloc(1,sizeof(Lista));
  ptr->primeira = NULL;
  return ptr;
}

 Tarefa *lerTarefa(){
  printf("Lendo Tarefa...");
  Tarefa *ptr = calloc(1,sizeof(Tarefa));

  // Codigo 
   
  printf("Digite o codigo da tarefa : \n");
  scanf("%d",ptr->codigo);
  getchar();

  // Descrição

  printf("Digite a descrição : \n");
  fgets(ptr->s,51, stdin);

  int i=0;

  while (ptr->s[i] != '\0') {
      if (ptr->s[i] == '\n') {
          ptr->s[i] = '\0';
          break;
      }

      i++;
  }

  return ptr;
}

void imprimirTarefa(const Tarefa *tarefa){
  printf("Codigo : [%d] \n");
  getchar();
  printf("Descrição : [%s] \n");
  getchar();
}

int inserirFinal(Lista *lista, Tarefa *tarefa){
  Celula celula = calloc(1,sizeof(Celula));
  if(lista->primeira == NULL){
    lista->primeira = celula;
    celula->tarefa = tarefa;
    celula->proxima = NULL;
  }else{
    Celula c2 = lista->primeira;
    while(c2->proxima!=NULL){
      c2 = c2->proxima;
    }
    c2->proxima = celula;
    c2 = c2->proxima;
    c2->tarefa = *tarefa;
    c2->proxima = NULL;
  }
}

void listarTarefas(const Lista *lista){
  Celula *c2 = lista->primeira;
  while(c2 != NULL){
    imprimirTarefa(c2->tarefa);
    if(c2->proxima != NULL){
      c2 = c2->proxima;
    }else{
      break;
    }
  }
}

void removerFinal(Lista *lista){
  Celula *c2 = lista->primeira;
  while(c2->proxima != NULL){
    c2 = c2->proxima;
  }

  free(c2->tarefa);
  free(c2);
}

void liberarLista(Lista *lista){
  Celula *c1;
  Celula *c2 = lista->primeira;
  while(c2->proxima != NULL){
    
  }
}

void main(){
  Lista nt;

  int op;

  printf("1. Adicionar uma tarefa ao final \n");
  printf("2. Listar as tarefas \n");
  printf("3. Remover a última tarefa \n");
  printf("4. Encerrar o programa \n");

  scanf("%d",&op);

  if(op>4 || op<1){
    printf("Opção inválida \n");
    printf("Escolha de novo \n");
    scanf("%d",&op);
  }

  if(op == 1){
    inserirFinal(&nt, lerTarefa());
  }

  if(op == 2){
    listarTarefas(&nt);
  }

  if(op == 3){
    removerFinal(&nt);
  }

  if(op == 4){
    liberarLista(&nt);
  }
}
