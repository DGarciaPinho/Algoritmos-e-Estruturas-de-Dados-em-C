/*
Lista 7 - Recursividade (versão C++ / POO)

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal
para ler os dados, chamar a função e apresentar o resultado. Não poderão ser utilizadas as
funções prontas de <math.h> (<cmath>) e <string.h> (<cstring>), a não ser que seja solicitado.

1. Implemente uma função recursiva para imprimir os elementos de um vetor de inteiros de
tamanho n.

Versão POO (padrão usado em toda a lista): o método PÚBLICO imprimir() não recebe índice
nenhum; ele chama um método PRIVADO recursivo que carrega o índice. Quem usa a classe não
precisa saber que existe recursão lá dentro.
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  void imprimirRec(int i) const{
    if(i == (int)dados.size()){   // caso base: passou do último
      return;
    }
    cout << "[" << dados[i] << "]";
    imprimirRec(i + 1);
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

  void imprimir() const{
    imprimirRec(0);
    cout << endl;
  }
};

int main(){
  VetorInteiros vetor;
  vetor.ler();

  cout << "Vetor : ";
  vetor.imprimir();

  return 0;
}
