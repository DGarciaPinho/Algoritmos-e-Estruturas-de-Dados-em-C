/*
Lista 7 - Recursividade (versão C++ / POO)

2. Implemente uma função recursiva para imprimir em ordem inversa os elementos de um vetor de
inteiros de tamanho n.

Truque: é a Q1 com a impressão DEPOIS da chamada recursiva. A impressão só acontece na
"volta" da recursão, então sai do último para o primeiro.
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  void imprimirInversoRec(int i) const{
    if(i == (int)dados.size()){
      return;
    }
    imprimirInversoRec(i + 1);
    cout << "[" << dados[i] << "]";
  }

public:
  void ler(){
    int n;
    cout << "=====================" << endl;
    cout << "Digite o tamanho :" << endl;
    cout << "=====================" << endl;
    cin >> n;

    dados.resize(n);
    for(int i=0;i<n;i++){
      cout << "Elemento [" << i+1 << "] : ";
      cin >> dados[i];
    }
  }

  void imprimirInverso() const{
    imprimirInversoRec(0);
    cout << endl;
  }
};

int main(){
  VetorInteiros vetor;
  vetor.ler();

  cout << "Vetor invertido : ";
  vetor.imprimirInverso();

  return 0;
}
