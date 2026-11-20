/*
Lista 6 - Strings (versão C++ / POO)

13. Uma string é palíndroma quando pode ser lida da mesma forma da esquerda para a direita e da
direita para a esquerda. Implemente a função:
int isPalindromo(const char *str);
A função deverá retornar 1 quando a string for palíndroma e 0 caso contrário. Diferenças entre
maiúsculas e minúsculas deverão ser desconsideradas, mas os espaços e os demais caracteres
participam da comparação. Ex.: "Arara" é palíndroma.

Versão POO: em C++ existe o tipo bool, então o método retorna true/false.
*/

#include <iostream>

using namespace std;

class MinhaString{
private:
  static const int TAM = 100;
  char texto[TAM];

  static char paraMinuscula(char c){
    if(c >= 'A' && c <= 'Z'){
      return c - 'A' + 'a';
    }
    return c;
  }

public:
  MinhaString(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  int comprimento() const{
    int i = 0;
    while(texto[i] != '\0'){
      i++;
    }
    return i;
  }

  bool isPalindromo() const{
    int i = 0;
    int j = comprimento() - 1;
    while(i < j){
      if(paraMinuscula(texto[i]) != paraMinuscula(texto[j])){
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};

int main(){
  MinhaString str;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  str.ler();

  if(str.isPalindromo()){
    cout << "É palíndromo." << endl;
  }else{
    cout << "Não é palíndromo." << endl;
  }

  return 0;
}
