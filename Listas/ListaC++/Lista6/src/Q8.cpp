/*
Lista 6 - Strings (versão C++ / POO)

8. Implemente a função:
int contarCaractere(const char *str, const char caractere);
A função deverá retornar a quantidade de vezes que o caractere informado aparece na string.
A comparação deverá diferenciar letras maiúsculas de minúsculas ('A' e 'a' são diferentes).
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

  int contarCaractere(char caractere) const{
    int quantidade = 0;
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] == caractere){
        quantidade++;
      }
    }
    return quantidade;
  }
};

int main(){
  MinhaString str;
  char c;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  str.ler();

  cout << "=====================" << endl;
  cout << "Digite o caractere :" << endl;
  cout << "=====================" << endl;
  cin >> c;

  cout << "O caractere '" << c << "' aparece " << str.contarCaractere(c) << " vez(es)." << endl;

  return 0;
}
