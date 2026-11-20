/*
Lista 7 - Recursividade (versão C++ / POO)

13. Converter um número inteiro da forma decimal para a forma binária. Ex.: 25 -> 11001.
Escreva uma função recursiva que recebe um número inteiro e imprime a sua representação binária.

Ideia: o último bit é n % 2. Imprime primeiro o binário de n / 2 (recursão) e DEPOIS o n % 2,
assim os bits saem na ordem certa (do mais significativo para o menos).
*/

#include <iostream>

using namespace std;

class Numero{
private:
  int valor;

  static void imprimirBinarioRec(unsigned int n){
    if(n > 1){
      imprimirBinarioRec(n / 2);
    }
    cout << n % 2;
  }

public:
  Numero(int valor) : valor(valor){}

  void imprimirBinario() const{
    if(valor < 0){
      cout << "-";
      imprimirBinarioRec(-(long long)valor);
    }else{
      imprimirBinarioRec(valor);
    }
    cout << endl;
  }
};

int main(){
  int n;

  cout << "Digite um número inteiro : ";
  cin >> n;

  Numero numero(n);

  cout << n << " em binário : ";
  numero.imprimirBinario();

  return 0;
}
