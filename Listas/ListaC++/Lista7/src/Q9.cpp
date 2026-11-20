/*
Lista 7 - Recursividade (versão C++ / POO)

9. Escreva uma função recursiva que conta a quantidade de vezes que um caractere informado
aparece em uma string informada.
*/

#include <iostream>

using namespace std;

class Texto{
private:
  static const int TAM = 100;
  char texto[TAM];

  int contarRec(char c, int i) const{
    if(texto[i] == '\0'){
      return 0;
    }
    return (texto[i] == c ? 1 : 0) + contarRec(c,i + 1);
  }

public:
  Texto(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  int contar(char c) const{
    return contarRec(c,0);
  }
};

int main(){
  Texto texto;
  char c;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  texto.ler();

  cout << "Digite o caractere : ";
  cin >> c;

  cout << "O caractere '" << c << "' aparece " << texto.contar(c) << " vez(es)." << endl;

  return 0;
}
