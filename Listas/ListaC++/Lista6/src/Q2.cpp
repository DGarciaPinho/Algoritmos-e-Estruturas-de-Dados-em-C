/*
Lista 6 - Strings (versão C++ / POO)

2. Desenvolva um programa para realizar as operações a seguir:
(a) Declare um arranjo de caracteres com 100 posições.
(b) Leia uma frase, que pode conter espaços (em C: scanf com %[^\n]). Limite a quantidade de
    caracteres lidos.
(c) Imprima a frase (em C: printf %s).
(d) Imprima a frase (em C: puts).
(e) Percorra a string e imprima cada um de seus caracteres em uma linha diferente. Os espaços
    também deverão ser impressos, produzindo uma linha aparentemente vazia na saída.
(f) Percorra novamente a string e imprima seus caracteres em uma única linha, desconsiderando
    todos os espaços em branco. A string original não deverá ser modificada.

Versão POO:
  - scanf("%99[^\n]")  ->  cin.getline(texto, 100)
  - (f) o método é const: o compilador PROÍBE que ele altere os atributos, então a string
    original com certeza não é modificada.
*/

#include <iostream>

using namespace std;

class Frase{
private:
  static const int TAM = 100;
  char texto[TAM];

public:
  Frase(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  void imprimir() const{
    cout << texto << endl;
  }

  void imprimirUmPorLinha() const{
    for(int i=0;texto[i]!='\0';i++){
      cout << texto[i] << endl;
    }
  }

  void imprimirSemEspacos() const{
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] != ' '){
        cout << texto[i];
      }
    }
    cout << endl;
  }
};

int main(){
  Frase frase;

  cout << "=====================" << endl;
  cout << "Digite uma frase :" << endl;
  cout << "=====================" << endl;
  frase.ler();

  cout << "(c) ";
  frase.imprimir();

  cout << "(d) ";
  frase.imprimir();

  cout << "(e)" << endl;
  frase.imprimirUmPorLinha();

  cout << "(f) ";
  frase.imprimirSemEspacos();

  return 0;
}
