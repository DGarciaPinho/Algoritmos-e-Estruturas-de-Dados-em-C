/*
Lista 7 - Recursividade (versão C++ / POO)

3. Implemente uma função recursiva para calcular o tamanho de uma string.

Versão POO: a classe Texto guarda um arranjo de char. Não pode usar strlen nem .size():
o tamanho é contado recursivamente até achar o '\0'.
  tamanho(i) = 0                    se texto[i] == '\0'
  tamanho(i) = 1 + tamanho(i + 1)   caso contrário
*/

#include <iostream>

using namespace std;

class Texto{
private:
  static const int TAM = 100;
  char texto[TAM];

  int tamanhoRec(int i) const{
    if(texto[i] == '\0'){
      return 0;
    }
    return 1 + tamanhoRec(i + 1);
  }

public:
  Texto(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  int tamanho() const{
    return tamanhoRec(0);
  }
};

int main(){
  Texto texto;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  texto.ler();

  cout << "Tamanho : " << texto.tamanho() << endl;

  return 0;
}
