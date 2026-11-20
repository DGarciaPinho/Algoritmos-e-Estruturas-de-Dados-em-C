/*
Lista 8 - Struct -> Classes (versão C++ / POO)

6. (Cadastro de funcionários com data de admissão) Cada funcionário possui matrícula, nome,
salário e data de admissão.

(a) Classe Data com dia, mes e ano (inteiros).
(b) Classe Funcionario com matricula (int), nome (até 50 caracteres), salario (real) e
    dataAdmissao (um objeto Data DENTRO do funcionário).
(c) Inicialização e impressão: crie um funcionário com
      Matrícula: 1001;  Nome: "Ana Souza";  Salário: 3500.00;  Admissão: 15/03/2022.
    Salário com duas casas e data no formato DD/MM/AAAA (com zeros à esquerda).
(d) Métodos da Data:  void ler();   void imprimir() const;
    A impressão do funcionário deve usar o imprimir() da data.
(e) Métodos do Funcionario:  void ler();   void imprimir() const;
    ler() lê matrícula, nome (com espaços) e salário e usa o ler() da Data.
(f) Cadastro de vários funcionários: capacidade para 50; leia a quantidade (1 a 50), leia
    todos e imprima todos.
(g) Consulta por ano de admissão:
      void listarAdmitidosNoAno(int ano) const;
    Imprime os admitidos no ano informado, ou uma mensagem se não houver nenhum.

Versão POO - COMPOSIÇÃO: "struct dentro de struct" vira "objeto dentro de objeto"
(Funcionario TEM UMA Data). O construtor do Funcionario inicializa a Data na lista de
inicialização: dataAdmissao(dia, mes, ano).
Cada classe só imprime o que é dela: o Funcionario não sabe formatar data, ele pede para a
própria Data se imprimir. As funções sobre o arranjo de funcionários viram métodos da Empresa.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Data{
private:
  int dia;
  int mes;
  int ano;

public:
  Data(int dia = 1, int mes = 1, int ano = 2000) : dia(dia), mes(mes), ano(ano){}

  int getAno() const{
    return ano;
  }

  void ler(){
    cout << "Dia : ";
    cin >> dia;
    cout << "Mes : ";
    cin >> mes;
    cout << "Ano : ";
    cin >> ano;
  }

  void imprimir() const{
    cout << setfill('0') << setw(2) << dia << "/"
         << setw(2) << mes << "/"
         << setw(4) << ano << setfill(' ');
  }
};

class Funcionario{
private:
  int matricula;
  string nome;
  double salario;
  Data dataAdmissao;   // composição

public:
  Funcionario() : matricula(0), nome(""), salario(0){}

  // (c)
  Funcionario(int matricula, const string &nome, double salario, int dia, int mes, int ano)
    : matricula(matricula), nome(nome), salario(salario), dataAdmissao(dia,mes,ano){}

  int getAnoAdmissao() const{
    return dataAdmissao.getAno();
  }

  // (e)
  void ler(){
    cout << "Matricula : ";
    cin >> matricula;

    cout << "Nome : ";
    cin >> ws;
    getline(cin,nome);
    if(nome.size() > 50){
      nome = nome.substr(0,50);
    }

    cout << "Salario : ";
    cin >> salario;

    cout << "Data de admissão" << endl;
    dataAdmissao.ler();
  }

  void imprimir() const{
    cout << "Matricula : " << matricula
         << " | Nome : " << nome
         << " | Salario : R$ " << fixed << setprecision(2) << salario
         << " | Admissão : ";
    dataAdmissao.imprimir();
    cout << endl;
  }
};

class Empresa{
private:
  static const int CAPACIDADE = 50;
  Funcionario funcionarios[CAPACIDADE];
  int quantidade;

public:
  Empresa() : quantidade(0){}

  // (f)
  void cadastrar(){
    do{
      cout << "Quantidade de funcionários (1 a " << CAPACIDADE << ") : ";
      cin >> quantidade;
    }while(quantidade < 1 || quantidade > CAPACIDADE);

    for(int i=0;i<quantidade;i++){
      cout << "===== Funcionário " << i+1 << " =====" << endl;
      funcionarios[i].ler();
    }
  }

  void listar() const{
    for(int i=0;i<quantidade;i++){
      funcionarios[i].imprimir();
    }
  }

  // (g)
  void listarAdmitidosNoAno(int ano) const{
    bool achou = false;
    for(int i=0;i<quantidade;i++){
      if(funcionarios[i].getAnoAdmissao() == ano){
        funcionarios[i].imprimir();
        achou = true;
      }
    }
    if(!achou){
      cout << "Nenhum funcionário admitido em " << ano << "." << endl;
    }
  }
};

int main(){
  // (c)
  Funcionario ana(1001,"Ana Souza",3500.00,15,3,2022);
  cout << "===== Funcionário inicializado =====" << endl;
  ana.imprimir();

  // (f)
  cout << endl;
  Empresa empresa;
  empresa.cadastrar();

  cout << endl << "===== Funcionários =====" << endl;
  empresa.listar();

  // (g)
  int ano;
  cout << endl << "Ano de admissão para consultar : ";
  cin >> ano;
  empresa.listarAdmitidosNoAno(ano);

  return 0;
}
