/*
Lista 6 - Strings (versão C++ / POO)

6. Implemente a função:
void concatenarStrings(const char *origem, char *destino);
A função deverá acrescentar os caracteres da string origem ao final da string destino.
Desenvolva um programa para ler duas strings, concatenar a segunda ao final da primeira e
imprimir o resultado.

Versão POO: o "destino" é o próprio objeto (this). O método concatenar recebe a origem por
referência constante (const MinhaString &) para não copiar o objeto e não poder alterá-lo.
Também foi feita a sobrecarga do operador += para chamar o mesmo método.
*/

#include <iostream>

using namespace std;

class MinhaString{
private:
  static const int TAM = 200;
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

  void concatenar(const MinhaString &origem){
    int fim = comprimento();
    int i = 0;
    // fim+i < TAM-1 garante espaço para o '\0'
    while(origem.texto[i] != '\0' && fim + i < TAM - 1){
      texto[fim + i] = origem.texto[i];
      i++;
    }
    texto[fim + i] = '\0';
  }

  MinhaString &operator+=(const MinhaString &origem){
    concatenar(origem);
    return *this;
  }
};

int main(){
  MinhaString s1, s2;

  cout << "=====================" << endl;
  cout << "Digite a primeira String :" << endl;
  cout << "=====================" << endl;
  s1.ler();

  cout << "=====================" << endl;
  cout << "Digite a segunda String :" << endl;
  cout << "=====================" << endl;
  s2.ler();

  s1 += s2;   // mesmo que s1.concatenar(s2);

  cout << "Resultado : ";
  s1.imprimir();

  return 0;
}
