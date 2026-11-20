/*
Lista 6 - Strings (versão C++ / POO)

9. Implemente a função:
int localizarCaractere(const char *str, const char caractere);
A função deverá procurar a primeira ocorrência do caractere informado na string e retornar sua
posição. Caso o caractere não seja encontrado, a função deverá retornar -1. As posições são
numeradas a partir de zero.
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

  int localizarCaractere(char caractere) const{
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] == caractere){
        return i;
      }
    }
    return -1;
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

  int pos = str.localizarCaractere(c);

  if(pos == -1){
    cout << "Caractere não encontrado (-1)." << endl;
  }else{
    cout << "Primeira ocorrência na posição : " << pos << endl;
  }

  return 0;
}
