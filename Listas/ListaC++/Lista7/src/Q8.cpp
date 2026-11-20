/*
Lista 7 - Recursividade (versão C++ / POO)

8. Escreva uma função recursiva que dado dois números x e n, calcula o valor x^n (x elevado a n).
(Sem usar pow de <cmath>.)

  x^0 = 1
  x^n = x * x^(n-1)
  x^n = 1 / x^(-n)   se n < 0
*/

#include <iostream>

using namespace std;

class Numero{
private:
  double valor;

public:
  Numero(double valor) : valor(valor){}

  double elevadoA(int n) const{
    if(n == 0){
      return 1;
    }
    if(n < 0){
      return 1 / elevadoA(-n);
    }
    return valor * elevadoA(n - 1);
  }
};

int main(){
  double x;
  int n;

  cout << "Digite x : ";
  cin >> x;
  cout << "Digite n : ";
  cin >> n;

  Numero numero(x);

  cout << x << " ^ " << n << " = " << numero.elevadoA(n) << endl;

  return 0;
}
