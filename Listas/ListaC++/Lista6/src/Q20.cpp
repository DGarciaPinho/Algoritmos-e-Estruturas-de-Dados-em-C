/*
Lista 6 - Strings (versão C++ / POO)

20. Implemente a função:
int contarPalavras(const char* str);
A função deverá retornar a quantidade de palavras da string. Palavra = sequência de um ou mais
caracteres diferentes de espaço. Pode haver espaços no início, no final e vários espaços
consecutivos. Ex.: "  Estruturas   de dados  " contém três palavras.
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

  // Conta cada vez que uma palavra COMEÇA: caractere não-espaço precedido de espaço (ou início)
  int contarPalavras() const{
    int quantidade = 0;
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] != ' ' && (i == 0 || texto[i-1] == ' ')){
        quantidade++;
      }
    }
    return quantidade;
  }
};

int main(){
  MinhaString frase;

  cout << "=====================" << endl;
  cout << "Digite a frase :" << endl;
  cout << "=====================" << endl;
  frase.ler();

  cout << "Quantidade de palavras : " << frase.contarPalavras() << endl;

  return 0;
}
