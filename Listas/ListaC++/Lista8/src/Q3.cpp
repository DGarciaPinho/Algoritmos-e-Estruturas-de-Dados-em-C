/*
Lista 8 - Struct -> Classes (versão C++ / POO)

3. (Alunos de uma turma) Cadastrar os alunos e apresentar informações sobre o desempenho da
turma.

(a) Cadastro da turma
    Reutilize a classe Aluno. A turma tem capacidade para 50 alunos. Leia a quantidade de
    alunos (entre 1 e 50) e preencha cada um usando o método ler(). Notas entre 0 e 10.
(b) Listagem da turma: imprimir todos os alunos usando o imprimir() de cada um.
(c) Nota média da turma, impressa no main com duas casas decimais.
(d) Quantidade de aprovados; no main, imprima aprovados e reprovados (reprovados = total -
    aprovados).
(e) Listagem dos aprovados e dos reprovados (duas funções).
(f) Maior nota da turma; no main, imprima essa nota e todos os alunos que a obtiveram.
(g) Alunos acima da média: os alunos com nota estritamente maior que a média.

Versão POO: as "funções que recebem o arranjo e a quantidade" viram MÉTODOS da classe Turma.
O arranjo e a quantidade são atributos privados da Turma, então não precisam ser passados
como parâmetro. E a regra de aprovação fica dentro do Aluno (aluno.aprovado()).
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
  static constexpr double NOTA_MINIMA = 7.0;   // mesmo critério da versão em C

  Aluno() : matricula(0), nome(""), nota(0){}

  double getNota() const{
    return nota;
  }

  bool aprovado() const{
    return nota >= NOTA_MINIMA;
  }

  void imprimir() const{
    cout << "Matricula : " << matricula
         << " | Nome : " << nome
         << " | Nota : " << fixed << setprecision(1) << nota << endl;
  }

  void ler(){
    cout << "Matricula : ";
    cin >> matricula;

    cout << "Nome : ";
    cin >> ws;
    getline(cin,nome);

    do{
      cout << "Nota (0 a 10) : ";
      cin >> nota;
    }while(nota < 0 || nota > 10);
  }
};

class Turma{
private:
  static const int CAPACIDADE = 50;
  Aluno alunos[CAPACIDADE];
  int quantidade;

public:
  Turma() : quantidade(0){}

  // (a)
  void cadastrar(){
    do{
      cout << "Quantidade de alunos (1 a " << CAPACIDADE << ") : ";
      cin >> quantidade;
    }while(quantidade < 1 || quantidade > CAPACIDADE);

    for(int i=0;i<quantidade;i++){
      cout << "===== Aluno " << i+1 << " =====" << endl;
      alunos[i].ler();
    }
  }

  int getQuantidade() const{
    return quantidade;
  }

  // (b)
  void listar() const{
    for(int i=0;i<quantidade;i++){
      alunos[i].imprimir();
    }
  }

  // (c)
  double media() const{
    double soma = 0;
    for(int i=0;i<quantidade;i++){
      soma += alunos[i].getNota();
    }
    return soma / quantidade;
  }

  // (d)
  int quantidadeAprovados() const{
    int aprovados = 0;
    for(int i=0;i<quantidade;i++){
      if(alunos[i].aprovado()){
        aprovados++;
      }
    }
    return aprovados;
  }

  // (e)
  void listarAprovados() const{
    for(int i=0;i<quantidade;i++){
      if(alunos[i].aprovado()){
        alunos[i].imprimir();
      }
    }
  }

  void listarReprovados() const{
    for(int i=0;i<quantidade;i++){
      if(!alunos[i].aprovado()){
        alunos[i].imprimir();
      }
    }
  }

  // (f)
  double maiorNota() const{
    double maior = alunos[0].getNota();
    for(int i=1;i<quantidade;i++){
      if(alunos[i].getNota() > maior){
        maior = alunos[i].getNota();
      }
    }
    return maior;
  }

  void listarComNota(double nota) const{
    for(int i=0;i<quantidade;i++){
      if(alunos[i].getNota() == nota){
        alunos[i].imprimir();
      }
    }
  }

  // (g)
  void listarAcimaDe(double valor) const{
    for(int i=0;i<quantidade;i++){
      if(alunos[i].getNota() > valor){
        alunos[i].imprimir();
      }
    }
  }
};

int main(){
  Turma turma;

  turma.cadastrar();

  cout << endl << "===== (b) Turma =====" << endl;
  turma.listar();

  double media = turma.media();
  cout << endl << "===== (c) Média =====" << endl;
  cout << fixed << setprecision(2) << media << endl;

  int aprovados = turma.quantidadeAprovados();
  cout << endl << "===== (d) Aprovados / Reprovados =====" << endl;
  cout << "Aprovados : " << aprovados << endl;
  cout << "Reprovados : " << turma.getQuantidade() - aprovados << endl;

  cout << endl << "===== (e) Aprovados =====" << endl;
  turma.listarAprovados();
  cout << "===== (e) Reprovados =====" << endl;
  turma.listarReprovados();

  double maior = turma.maiorNota();
  cout << endl << "===== (f) Maior nota : " << fixed << setprecision(1) << maior << " =====" << endl;
  turma.listarComNota(maior);

  cout << endl << "===== (g) Acima da média =====" << endl;
  turma.listarAcimaDe(media);

  return 0;
}
