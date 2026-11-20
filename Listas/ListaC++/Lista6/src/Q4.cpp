/*
Lista 6 - Strings (versão C++ / POO)

Parte 2: não poderão ser utilizadas as funções prontas de <string.h> (<cstring>), a não ser
que seja solicitado.

4. Implemente a função:
int comprimentoString(char *str);
A função deverá receber uma string e retornar a quantidade de caracteres nela armazenados, sem
considerar o caractere nulo '\0'.

Versão POO: a função vira o método comprimento() da classe MinhaString.
*/

#include <iostream>

using namespace std;

class MinhaString{
private:
  static const int TAM = 100;
  char texto[TAM];

public:
  MinhaString(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  void imprimir() const{
    cout << texto << endl;
  }

  int comprimento() const{
    int i = 0;
    while(texto[i] != '\0'){
      i++;
    }
    return i;
  }
};

int main(){
  MinhaString str;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  str.ler();

  cout << "=====================" << endl;
  cout << "O tamanho da String é igual a : " << str.comprimento() << endl;
  cout << "=====================" << endl;

  return 0;
}
