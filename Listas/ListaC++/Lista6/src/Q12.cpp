/*
Lista 6 - Strings (versão C++ / POO)

12. Implemente a função:
void inverterString(char *str);
A função deverá inverter a ordem dos caracteres da própria string recebida. Não deverá ser
criado outro arranjo para armazenar a string invertida. Ex.: "algoritmo" -> "omtirogla".

Versão POO: diferente da Q11, aqui o método NÃO é const, porque altera o próprio objeto.
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

  void inverter(){
    int i = 0;
    int j = comprimento() - 1;
    while(i < j){
      char temp = texto[i];
      texto[i] = texto[j];
      texto[j] = temp;
      i++;
      j--;
    }
  }
};

int main(){
  MinhaString str;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  str.ler();

  str.inverter();

  cout << "Invertida : ";
  str.imprimir();

  return 0;
}
