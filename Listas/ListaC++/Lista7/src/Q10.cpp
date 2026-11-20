/*
Lista 7 - Recursividade (versão C++ / POO)

10. Escreva uma função recursiva que recebe uma string, um caractere original e um caractere
substituto. A função deverá substituir, na própria string, todas as ocorrências do original pelo
substituto e retornar a quantidade de substituições. Ex.: 'a' por 'o' em "banana" -> "bonono",
retorna 3. Leia a string e os dois caracteres, chame a função e imprima a string modificada e a
quantidade.
*/

#include <iostream>

using namespace std;

class Texto{
private:
  static const int TAM = 100;
  char texto[TAM];

  int substituirRec(char original, char substituto, int i){
    if(texto[i] == '\0'){
      return 0;
    }
    int trocou = 0;
    if(texto[i] == original){
      texto[i] = substituto;
      trocou = 1;
    }
    return trocou + substituirRec(original,substituto,i + 1);
  }

public:
  Texto(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  void imprimir() const{
    cout << texto << endl;
  }

  int substituir(char original, char substituto){
    return substituirRec(original,substituto,0);
  }
};

int main(){
  Texto texto;
  char original, substituto;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  texto.ler();

  cout << "Caractere original : ";
  cin >> original;
  cout << "Caractere substituto : ";
  cin >> substituto;

  int quantidade = texto.substituir(original,substituto);

  cout << "Resultado : ";
  texto.imprimir();
  cout << "Substituições : " << quantidade << endl;

  return 0;
}
