/*
Lista 6 - Strings (versão C++ / POO)

15. Implemente a função:
void removerCaractere(char *str, char caractere);
A função deverá remover da própria string todas as ocorrências do caractere informado. Os
caracteres restantes deverão ser deslocados para que não existam posições vazias. Ex.: remover
'a' de "abacate" -> "bcte". Não deverá ser utilizado outro arranjo.
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

  // Dois índices: i lê, j escreve. Só avança o j quando o caractere fica.
  void removerCaractere(char caractere){
    int j = 0;
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] != caractere){
        texto[j] = texto[i];
        j++;
      }
    }
    texto[j] = '\0';
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
  cout << "Caractere a remover :" << endl;
  cout << "=====================" << endl;
  cin >> c;

  str.removerCaractere(c);

  cout << "Resultado : ";
  str.imprimir();

  return 0;
}
