/*
Lista 6 - Strings (versão C++ / POO)

27. (Processamento de registros em formato textual) Cada estudante vem em uma única string no
formato:
  nome;idade;curso
Ex.: Ana Souza;21;Engenharia de Computacao
Leia a quantidade de registros e, em seguida, os registros. Separe nome, idade (convertida para
inteiro) e curso. Depois apresente:
  - nome, idade e curso de cada estudante;
  - o estudante mais velho (em caso de empate, o que aparecer primeiro na entrada).
No máximo 50 registros, cada um com no máximo 149 caracteres, exatamente dois ';'.

Exemplo de entrada:
4
Ana Souza;21;Engenharia de Computacao
Bruno Lima;24;Sistemas de Informacao
Carla Mendes;22;Engenharia de Computacao
Daniel Alves;24;Ciencia da Computacao

Saída esperada:
*Estudantes:

Nome: Ana Souza               | Idade: 21    | Curso: Engenharia de Computacao
Nome: Bruno Lima              | Idade: 24    | Curso: Sistemas de Informacao
Nome: Carla Mendes            | Idade: 22    | Curso: Engenharia de Computacao
Nome: Daniel Alves            | Idade: 24    | Curso: Ciencia da Computacao

*Estudante mais velho:
Nome: Bruno Lima              | Idade: 24    | Curso: Sistemas de Informacao

Versão POO (no C eram 3 arranjos separados):
  - Estudante: junta nome/idade/curso num objeto. O método ESTÁTICO fromRegistro() funciona
    como uma "fábrica": recebe a linha "nome;idade;curso" e devolve um Estudante pronto.
  - CadastroAcademico: guarda um vector<Estudante> e sabe listar e achar o mais velho.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Estudante{
private:
  string nome;
  int idade;
  string curso;

public:
  Estudante(const string &nome, int idade, const string &curso)
    : nome(nome), idade(idade), curso(curso){}

  static Estudante fromRegistro(const string &registro){
    size_t p1 = registro.find(';');
    size_t p2 = registro.find(';',p1 + 1);

    string nome = registro.substr(0,p1);
    int idade = stoi(registro.substr(p1 + 1,p2 - p1 - 1));
    string curso = registro.substr(p2 + 1);

    return Estudante(nome,idade,curso);
  }

  int getIdade() const{
    return idade;
  }

  void imprimir() const{
    cout << "Nome: " << left << setw(24) << nome
         << "| Idade: " << setw(6) << idade
         << "| Curso: " << curso << endl;
  }
};

class CadastroAcademico{
private:
  static const int MAX = 50;
  vector<Estudante> estudantes;

public:
  bool adicionar(const Estudante &e){
    if((int)estudantes.size() >= MAX){
      return false;
    }
    estudantes.push_back(e);
    return true;
  }

  void listar() const{
    for(const Estudante &e : estudantes){
      e.imprimir();
    }
  }

  // Retorna ponteiro para não precisar copiar; nullptr se o cadastro estiver vazio
  const Estudante *maisVelho() const{
    if(estudantes.empty()){
      return nullptr;
    }
    const Estudante *maior = &estudantes[0];
    for(const Estudante &e : estudantes){
      if(e.getIdade() > maior->getIdade()){   // > estrito: no empate fica o primeiro
        maior = &e;
      }
    }
    return maior;
  }
};

int main(){
  int n;
  cin >> n;
  cin.ignore();   // descarta o '\n' que ficou depois do número

  CadastroAcademico cadastro;

  for(int i=0;i<n;i++){
    string linha;
    getline(cin,linha);
    cadastro.adicionar(Estudante::fromRegistro(linha));
  }

  cout << "*Estudantes:" << endl << endl;
  cadastro.listar();

  const Estudante *velho = cadastro.maisVelho();
  if(velho != nullptr){
    cout << endl << "*Estudante mais velho:" << endl;
    velho->imprimir();
  }

  return 0;
}
