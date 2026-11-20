/*
Lista 7 - Recursividade (versão C++ / POO)

7. Escreva uma função recursiva que, dado dois números x e n, calcula o valor x*n (x
multiplicado por n). Sua função não pode usar o operador de multiplicação.

  x * 0 = 0
  x * n = x + x * (n - 1)
  x * n = -(x * (-n))   se n < 0

Versão POO: a classe Numero guarda o valor x; multiplicarPor(n) é o método recursivo.
*/

#include <iostream>

using namespace std;

class Numero{
private:
  int valor;

public:
  Numero(int valor) : valor(valor){}

  int multiplicarPor(int n) const{
    if(n == 0){
      return 0;
    }
    if(n < 0){
      return -multiplicarPor(-n);
    }
    return valor + multiplicarPor(n - 1);
  }
};

int main(){
  int x, n;

  cout << "Digite x : ";
  cin >> x;
  cout << "Digite n : ";
  cin >> n;

  Numero numero(x);

  cout << x << " * " << n << " = " << numero.multiplicarPor(n) << endl;

  return 0;
}
