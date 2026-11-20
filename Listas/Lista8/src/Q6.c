// Algoritmos e Estruturas de Dados I
// Lista de Exercícios – Struct
//
// 6. (Cadastro de funcionários com data de admissão) Uma empresa precisa cadastrar seus funcionários e consultar
// o ano em que foram admitidos. Cada funcionário possui matrícula, nome, salário e data de admissão.
// Desenvolva um programa em C seguindo as etapas abaixo.
//
// (a) Definição da struct Data
//
// Defina uma struct Data com os campos dia, mes e ano, todos do tipo inteiro.
//
// (b) Definição da struct Funcionario
//
// Defina uma struct Funcionario com os seguintes campos:
//   - matricula: número inteiro;
//   - nome: vetor de caracteres com capacidade para armazenar até 50 caracteres, além do terminador '\0';
//   - salario: número real;
//   - dataAdmissao: campo do tipo struct Data.
//
// A data de admissão deve ser armazenada como uma struct incorporada à struct do funcionário.
//
// (c) Inicialização e impressão
//
// Na função main, declare uma variável do tipo struct Funcionario e utilize uma lista de inicialização para
// atribuir os seguintes dados:
//   - Matrícula: 1001;
//   - Nome: "Ana Souza";
//   - Salário: 3500.00;
//   - Data de admissão: 15/03/2022.
//
// Imprima todos os dados do funcionário. Apresente o salário com duas casas decimais e a data no formato
// DD/MM/AAAA, incluindo zeros à esquerda quando necessário.
//
// (d) Funções para manipulação da data
//
// Crie as funções:
//
//     void lerData(struct Data *data);
//     void imprimirData(struct Data* data);
//
// A função lerData deve preencher os campos com o dia, o mês e o ano digitados pelo usuário. Considere que
// a data informada é válida. A função imprimirData deve apresentar a data no formato DD/MM/AAAA. Altere
// a impressão do funcionário para utilizar imprimirData na apresentação da data de admissão.
//
// (e) Funções para manipulação do funcionário
//
// Crie as funções:
//
//     void lerFuncionario(struct Funcionario *funcionario);
//     void imprimirFuncionario(struct Funcionario* funcionario);
//
// A função lerFuncionario deve ler matrícula, nome e salário e utilizar lerData para preencher a data de
// admissão. A leitura do nome deve permitir espaços. A função imprimirFuncionario deve apresentar todos os
// dados do funcionário e utilizar imprimirData para apresentar a data de admissão. Altere a função main para
// substituir a lista de inicialização pela leitura dos dados e utilizar essas funções.
//
// (f) Cadastro de vários funcionários
//
// Altere o programa para armazenar um arranjo com capacidade para 50 funcionários. Leia a quantidade de
// funcionários que serão cadastrados, que deve estar entre 1 e 50. Utilize lerFuncionario para preencher cada
// elemento do arranjo e, depois, imprimirFuncionario para apresentar todos os registros.
//
// (g) Consulta por ano de admissão
//
// Crie a função:
//
//     void listarAdmitidosNoAno(struct Funcionario funcionarios[], int n, int ano);
//
// A função deve imprimir os dados de todos os funcionários admitidos no ano recebido como parâmetro,
// utilizando imprimirFuncionario. Caso nenhum funcionário atenda ao critério, apresente uma mensagem
// informando essa situação. Na função main, leia o ano desejado e chame a função para realizar a consulta.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defina uma struct Data com os campos dia, mes e ano, todos do tipo inteiro.

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

//   - Matrícula: 1001;
//   - Nome: "Ana Souza";
//   - Salário: 3500.00;
//   - Data de admissão: 15/03/2022.een = {}

typedef struct{
  short matricula;
  char nome[50];
  int salario;
  Data data;
}Funcionario;

void imprimirF(const Funcionario f){
  printf("Nome : [%s] \n",f.nome);
  printf("Matricula : [%d] \n",f.matricula);
  printf("Salario : [%d] \n",f.salario);
  printf("Data : [%d/%d/%d]\n",f.data.dia,f.data.mes,f.data.ano);
}

void lerF(Funcionario *funcionario){
  Funcionario *f = calloc(1,sizeof(Funcionario));
  printf("===\n");
  printf("FUNCIONARIO \n");

  printf("Nome : \n");
  
  fgets(f->nome,50, stdin);

  int i=0;

  while (f->nome[i] != '\0') {
      if (f->nome[i] == '\n') {
          f->nome[i] = '\0';
          break;
      }

      i++;
  }

  printf("Preço : \n");
  scanf("%f",&f->preco);

  getchar();

  printf("===\n");
  return produto;
}

void lerD(Data *data){}

void imprimirD(Data* data){}

void main(){

}
