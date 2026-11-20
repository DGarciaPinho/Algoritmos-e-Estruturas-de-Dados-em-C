/*
Lista 7 - Recursividade (versão C++ / POO)

17. (MDC pelo algoritmo de Euclides) O MDC de dois inteiros positivos é o maior número que
divide ambos sem deixar resto. Pelo algoritmo de Euclides, substitui-se repetidamente o par
(a, b) por (b, a mod b), até que o segundo número seja zero; o primeiro é o MDC.
Leia dois inteiros positivos e calcule o MDC usando uma função RECURSIVA.
  Entrada: 48 18
  Saída:   6

Versão POO: a classe ParDeInteiros guarda (a, b). O método recursivo é ESTÁTICO, porque o
algoritmo não depende do objeto: ele só usa os parâmetros. Bônus: mmc() reaproveita o mdc().
*/

#include <iostream>

using namespace std;

class ParDeInteiros{
private:
  int a;
  int b;

public:
  ParDeInteiros(int a, int b) : a(a), b(b){}

  static int mdc(int a, int b){
    if(b == 0){
      return a;
    }
    return mdc(b,a % b);
  }

  int mdc() const{
    return mdc(a,b);
  }

  int mmc() const{
    return a / mdc() * b;
  }
};

int main(){
  int a, b;
  cin >> a >> b;

  ParDeInteiros par(a,b);

  cout << par.mdc() << endl;

  return 0;
}
