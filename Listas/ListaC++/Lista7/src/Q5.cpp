/*
Lista 7 - Recursividade (versão C++ / POO)

5. Implemente uma função recursiva que inverte os elementos de um vetor de inteiros de tamanho
n. O vetor recebido como parâmetro deve ser alterado.

Versão POO: inverter() altera o próprio objeto (não é const). A recursão troca as pontas
(inicio, fim) e chama para o miolo (inicio+1, fim-1).
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  void inverterRec(int inicio, int fim){
    if(inicio >= fim){
      return;
    }
    int temp = dados[inicio];
    dados[inicio] = dados[fim];
    dados[fim] = temp;
    inverterRec(inicio + 1,fim - 1);
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

  void inverter(){
    inverterRec(0,(int)dados.size() - 1);
  }

  void imprimir() const{
    for(int x : dados){
      cout << "[" << x << "]";
    }
    cout << endl;
  }
};

int main(){
  VetorInteiros vetor;
  vetor.ler();

  vetor.inverter();

  cout << "Vetor invertido : ";
  vetor.imprimir();

  return 0;
}
