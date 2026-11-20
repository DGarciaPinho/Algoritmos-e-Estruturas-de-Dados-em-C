/*
Lista 8 - Struct -> Classes (versão C++ / POO)

1. (Cadastro de um aluno) Armazenar e apresentar a matrícula, o nome e a nota de um aluno.

(a) Definição da classe
    Defina uma classe Aluno com os atributos:
      matricula: número inteiro;
      nome: texto com até 50 caracteres;
      nota: número real.
(b) Inicialização e impressão
    No main, crie um objeto Aluno inicializado com:
      Matrícula: 20261001;  Nome: "Ana Souza";  Nota: 7.5.
    Imprima todos os dados, com a nota com uma casa decimal.
(c) Impressão por um método
    A impressão deve ser feita pelo método  void imprimir() const;
(d) Leitura por um método
    Os dados devem ser digitados pelo usuário pelo método  void ler();
    A leitura do nome deve permitir espaços.

Struct (C)  ->  Classe (C++):
  - struct Aluno {...}                   ->  class Aluno { private: ... public: ... };
  - lista de inicialização {20261001,..} ->  CONSTRUTOR  Aluno(int, string, double)
  - void imprimirAluno(struct Aluno a)   ->  MÉTODO  a.imprimir()   (não precisa passar o aluno,
                                             o método já trabalha no próprio objeto: this)
  - void lerAluno(struct Aluno *a)       ->  MÉTODO  a.ler()        (não precisa de ponteiro)
  - Os atributos são private: fora da classe ninguém faz aluno.nota = -3.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Aluno{
private:
  int matricula;
  string nome;
  double nota;

public:
  // Construtor padrão (para o caso (d), em que o objeto é criado vazio e depois lido)
  Aluno() : matricula(0), nome(""), nota(0){}

  // (b) Construtor com lista de inicialização de membros
  Aluno(int matricula, const string &nome, double nota)
    : matricula(matricula), nome(nome), nota(nota){}

  // (c)
  void imprimir() const{
    cout << "Matricula : " << matricula << endl;
    cout << "Nome : " << nome << endl;
    cout << "Nota : " << fixed << setprecision(1) << nota << endl;
  }

  // (d)
  void ler(){
    cout << "Matricula : ";
    cin >> matricula;

    cout << "Nome : ";
    cin >> ws;               // descarta o '\n' (e espaços) que sobrou do cin >> matricula
    getline(cin,nome);
    if(nome.size() > 50){
      nome = nome.substr(0,50);
    }

    cout << "Nota : ";
    cin >> nota;
  }
};

int main(){
  // (b) e (c)
  Aluno ana(20261001,"Ana Souza",7.5);

  cout << "===== Aluno inicializado =====" << endl;
  ana.imprimir();

  // (d)
  Aluno aluno;

  cout << endl << "===== Digite os dados do aluno =====" << endl;
  aluno.ler();

  cout << endl << "===== Aluno lido =====" << endl;
  aluno.imprimir();

  return 0;
}
