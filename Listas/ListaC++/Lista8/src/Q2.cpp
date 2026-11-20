/*
Lista 8 - Struct -> Classes (versão C++ / POO)

2. Original: "Altere a versão final do exercício 1 para utilizar typedef para a struct Aluno,
com o novo tipo também se chamando Aluno."

Em C++ isso não é necessário: o nome de uma class (ou struct) JÁ É um tipo. Em C era preciso
escrever "struct Aluno a;" e o typedef servia para escrever só "Aluno a;". Em C++ já se escreve
"Aluno a;" direto. (O equivalente moderno do typedef é o "using", mostrado abaixo só como
exemplo.)

Versão POO desta questão: evoluir a classe da Q1 com
  - GETTERS (consultar atributos privados) e SETTERS (alterar com validação);
  - nota sempre entre 0 e 10 (o setter garante isso -> esse é o ganho do encapsulamento);
  - sobrecarga do operador << para escrever  cout << aluno;
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
  Aluno() : matricula(0), nome(""), nota(0){}

  Aluno(int matricula, const string &nome, double nota) : matricula(matricula){
    setNome(nome);
    setNota(nota);
  }

  // Getters
  int getMatricula() const{ return matricula; }
  string getNome() const{ return nome; }
  double getNota() const{ return nota; }

  // Setters
  void setMatricula(int matricula){
    this->matricula = matricula;
  }

  void setNome(const string &nome){
    this->nome = nome.size() > 50 ? nome.substr(0,50) : nome;
  }

  // Retorna false se a nota for inválida (e não altera nada)
  bool setNota(double nota){
    if(nota < 0 || nota > 10){
      return false;
    }
    this->nota = nota;
    return true;
  }

  void imprimir() const{
    cout << "Matricula : " << matricula << endl;
    cout << "Nome : " << nome << endl;
    cout << "Nota : " << fixed << setprecision(1) << nota << endl;
  }

  void ler(){
    cout << "Matricula : ";
    cin >> matricula;

    cout << "Nome : ";
    string n;
    cin >> ws;
    getline(cin,n);
    setNome(n);

    double x;
    cout << "Nota (0 a 10) : ";
    cin >> x;
    while(!setNota(x)){
      cout << "Nota inválida, digite novamente : ";
      cin >> x;
    }
  }

  // friend: não é método da classe, mas pode acessar os atributos privados
  friend ostream &operator<<(ostream &out, const Aluno &a){
    out << "[" << a.matricula << "] " << a.nome << " - "
        << fixed << setprecision(1) << a.nota;
    return out;
  }
};

using TipoAluno = Aluno;   // equivalente C++ do typedef (só para mostrar; não é necessário)

int main(){
  TipoAluno aluno;

  cout << "===== Digite os dados do aluno =====" << endl;
  aluno.ler();

  cout << endl << "===== imprimir() =====" << endl;
  aluno.imprimir();

  cout << endl << "===== operator<< =====" << endl;
  cout << aluno << endl;

  cout << endl << "===== getters =====" << endl;
  cout << "Nome : " << aluno.getNome() << endl;

  return 0;
}
