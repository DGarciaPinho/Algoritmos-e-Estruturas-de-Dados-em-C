// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 5. Altere a questão 4 para os produtos sejam armazenados usando vetor dinâmico ao invés de VLA, isto é, use
// ponteiro para ponteiro para Produto:
//
//     Produto** produtos;
//
// Essencialmente, você irá alterar a etapa (c) para alocar dinamicamente um vetor dinâmico para n ponteiros para
// produto (Produto*). Depois, para cada produto, chame lerProduto, armazene o ponteiro retornado na posição
// correta. Altere as demais etapas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//   - codigo: número inteiro;
//   - nome: vetor de caracteres com capacidade para armazenar até 50 caracteres, além do terminador '\0';
//   - preco: número real;
//   - quantidade: número inteiro que representa a quantidade disponível em estoque.

typedef struct{
  int codigo;
  char nome[51];
  float preco;
  int quantidade;
}Produto;

Produto *buscarProduto(Produto *produtos[], int n, int codigo){
  for(int i=0;i<n;++i){
    if(produtos[i]->codigo==codigo){
      return produtos[i];
    }
  }

  return NULL;
}

Produto *lerProduto(){
  Produto *produto = calloc(1,sizeof(Produto));
  printf("===\n");
  printf("PRODUTO  \n");

  printf("Nome : \n");
  
  fgets(produto->nome,50, stdin);

  int i=0;

  while (produto->nome[i] != '\0') {
      if (produto->nome[i] == '\n') {
          produto->nome[i] = '\0';
          break;
      }

      i++;
  }

  printf("Codigo : \n");
  scanf("%d",&produto->codigo);

  printf("Preço : \n");
  scanf("%f",&produto->preco);

  printf("Quantidade : \n");
  scanf("%d",&produto->quantidade);

  getchar();

  printf("===\n");
  return produto;
}

void imprimirProduto(const Produto *produto){


  printf("===================== \n");
  printf("Nome : [%s] \n",produto->nome);
  printf("Nome : [%d] \n",produto->codigo);
  printf("Preço : [%.2f] \n",produto->preco);
  printf("Quantidade : [%d] \n",produto->quantidade);
  printf("===================== \n");
}

void main(){
  int n;
  scanf("%d",&n);
  getchar();
  Produto *produtos[n];

  for(int i=0;i<n;++i){
    produtos[i] = lerProduto();
  }

  int imprimir = 0;
  printf("Quer imprimir todos os produtos? \n");
  scanf("%d",&imprimir);

  if(imprimir!=0){
    for(int i=0;i<n;++i){
      imprimirProduto(produtos[i]);
    }
  }

  int search;
  printf("Digite o codigo que deseja buscar : \n");
  scanf("%d",&search);

  Produto *ptr = buscarProduto(produtos,n,search);

  int move;

  if(ptr == NULL){
    printf("Produto não encontrado! \n");
  }else{
    printf("Digite a quantidade de produtos que foram movidos : \n");
    scanf("%d",&move);
    ptr->quantidade = ptr->quantidade + move;
    printf("Nova quantidade do Produto[%d] : %d \n",ptr->codigo,ptr->quantidade);
  }

}
