// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 4. (Cadastro de produtos com ponteiros) Uma loja precisa cadastrar produtos e atualizar suas quantidades em
// estoque. Cada produto deve ser alocado dinamicamente e manipulado por meio de um ponteiro. Desenvolva um
// programa em C seguindo as etapas abaixo.
//
// (a) Definição do tipo Produto
//
// Defina uma struct com os seguintes campos e utilize typedef para nomear o tipo como Produto:
//   - codigo: número inteiro;
//   - nome: vetor de caracteres com capacidade para armazenar até 50 caracteres, além do terminador '\0';
//   - preco: número real;
//   - quantidade: número inteiro que representa a quantidade disponível em estoque.
//
// Utilize o nome Produto nas declarações de variáveis e nos parâmetros das funções.
//
// (b) Alocação, leitura e impressão
//
// Implemente as funções:
//
//     Produto *lerProduto();
//     void imprimirProduto(const Produto *produto);
//
// A função lerProduto deve alocar dinamicamente um registro do tipo Produto, preencher seus campos com
// os dados digitados pelo usuário e retornar seu endereço. Caso a alocação falhe, deve retornar NULL. A
// leitura do nome deve permitir espaços. Considere que o preço e a quantidade informados são não negativos.
// A função imprimirProduto deve imprimir todos os dados do produto, apresentando o preço com duas casas
// decimais.
//
// (c) Cadastro dos produtos
//
// Na função main, leia uma quantidade positiva n de produtos. Em seguida, declare um arranjo de ponteiros
// com tamanho definido durante a execução, utilizando um VLA:
//
//     Produto *produtos[n];
//
// Para cada posição do arranjo, chame lerProduto, armazene o ponteiro retornado e verifique se a alocação foi
// realizada. Caso alguma alocação falhe, libere os produtos já criados e encerre o programa.
//
// (d) Listagem dos produtos
//
// Percorra o arranjo e utilize imprimirProduto para apresentar os dados de cada produto cadastrado.
//
// (e) Busca pelo código
//
// Implemente a função:
//
//     Produto *buscarProduto(Produto *produtos[], int n, int codigo);
//
// A função deve retornar o ponteiro para o produto com o código informado ou NULL caso ele não seja
// encontrado. Considere que os códigos cadastrados são distintos. Na função main, leia um código e realize a
// busca. Se o produto existir, imprima seus dados; caso contrário, apresente uma mensagem informando que
// ele não foi encontrado.
//
// (f) Atualização do estoque
//
// Caso o produto seja encontrado, leia uma nova quantidade não negativa e utilize o ponteiro retornado pela
// busca para atualizar seu campo quantidade. Depois, apresente novamente a listagem dos produtos para
// verificar a alteração.
//
// (g) Liberação da memória
//
// Antes de encerrar o programa, percorra o arranjo e libere cada produto com free. O arranjo de ponteiros é
// um VLA e possui duração automática; somente os registros criados dinamicamente devem ser liberados com
// free.

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
