/*
Lista 6 - Strings (versão C++ / POO)

1. Desenvolva um programa para realizar as operações a seguir:
(a) Declare um arranjo de caracteres com 30 posições.
(b) Leia uma palavra (sem espaços). Limite a quantidade de caracteres lidos para evitar que a
    capacidade do arranjo seja ultrapassada.
(c) Imprima a palavra (em C: printf com %s).
(d) Imprima a palavra (em C: puts).
(e) Percorra a string e imprima cada um de seus caracteres (em C: printf com %c), em uma única linha.

Versão POO: o arranjo vira um atributo PRIVADO da classe Palavra. Quem usa a classe não
mexe no arranjo diretamente, só chama os métodos (encapsulamento).
  - scanf("%29s")  ->  cin >> setw(30)   (setw limita a leitura, igual ao 29 do scanf)
  - printf("%s")   ->  cout <<
  - puts           ->  cout << ... << endl   (puts imprime e pula linha)
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Palavra{
private:
  static const int TAM = 30;
  char texto[TAM];

public:
  // Construtor: garante que o objeto nasce com uma string válida (vazia)
  Palavra(){
    texto[0] = '\0';
  }

  void ler(){
    cin >> setw(TAM) >> texto;
  }

  void imprimir() const{
    cout << texto;
  }

  void imprimirComQuebra() const{
    cout << texto << endl;
  }

  void imprimirCaracteres() const{
    for(int i=0;texto[i]!='\0';i++){
      cout << texto[i];
    }
    cout << endl;
  }
};

int main(){
  Palavra palavra;

  cout << "=====================" << endl;
  cout << "Digite uma palavra :" << endl;
  cout << "=====================" << endl;
  palavra.ler();

  cout << "(c) ";
  palavra.imprimir();
  cout << endl;

  cout << "(d) ";
  palavra.imprimirComQuebra();

  cout << "(e) ";
  palavra.imprimirCaracteres();

  return 0;
}
