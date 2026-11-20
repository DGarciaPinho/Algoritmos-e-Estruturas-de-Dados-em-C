/*
Lista 7 - Recursividade (versão C++ / POO)

15. (Soma de dígitos) Implemente uma função que calcula a soma dos dígitos de um número inteiro,
tratando-o como inteiro (sem converter para string ou char). Ex.:
  1342 -> 10;   700 -> 7;   9 -> 9.
Dica: (i) o dígito menos significativo é n % 10; (ii) para desprezá-lo, use n / 10.
(a) Implemente sua solução usando abordagem iterativa.
(b) Implemente sua solução usando abordagem recursiva.

Versão POO: a mesma classe oferece as duas versões como métodos diferentes; o main confere que
dão o mesmo resultado.
*/

#include <iostream>

using namespace std;

class Numero{
private:
  int valor;

  static int somaDigitosRec(int n){
    if(n < 10){
      return n;
    }
    return n % 10 + somaDigitosRec(n / 10);
  }

  int valorAbsoluto() const{
    return valor < 0 ? -valor : valor;
  }

public:
  Numero(int valor) : valor(valor){}

  // (a)
  int somaDigitosIterativa() const{
    int n = valorAbsoluto();
    int soma = 0;
    while(n > 0){
      soma += n % 10;
      n /= 10;
    }
    return soma;
  }

  // (b)
  int somaDigitosRecursiva() const{
    return somaDigitosRec(valorAbsoluto());
  }
};

int main(){
  int n;

  cout << "Digite um número inteiro : ";
  cin >> n;

  Numero numero(n);

  cout << "(a) Iterativa : " << numero.somaDigitosIterativa() << endl;
  cout << "(b) Recursiva : " << numero.somaDigitosRecursiva() << endl;

  return 0;
}
