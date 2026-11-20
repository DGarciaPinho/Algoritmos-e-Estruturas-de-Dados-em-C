/*
Lista 6 - Strings (versão C++ / POO)

17. Implemente a função:
int substituirCaractere(char *str, const char original, const char substituto);
A função deverá substituir, na própria string, todas as ocorrências do caractere original pelo
substituto e retornar a quantidade de substituições. Ex.: 'a' por 'o' em "banana" -> "bonono",
retorna 3.
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

  int substituirCaractere(char original, char substituto){
    int quantidade = 0;
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] == original){
        texto[i] = substituto;
        quantidade++;
      }
    }
    return quantidade;
  }
};

int main(){
  MinhaString str;
  char original, substituto;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  str.ler();

  cout << "Caractere original : ";
  cin >> original;
  cout << "Caractere substituto : ";
  cin >> substituto;

  int quantidade = str.substituirCaractere(original,substituto);

  cout << "Resultado : ";
  str.imprimir();
  cout << "Substituições : " << quantidade << endl;

  return 0;
}
