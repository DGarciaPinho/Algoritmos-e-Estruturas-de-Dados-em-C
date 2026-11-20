/*
Lista 7 - Recursividade (versão C++ / POO)

6. Implemente uma função recursiva que, dado um vetor de inteiros de tamanho n, retorna um novo
vetor de tamanho n com os elementos do vetor recebido em ordem invertida. O vetor recebido como
parâmetro não pode ser alterado.

Versão POO: invertido() é const (garante que o original não muda) e retorna um NOVO objeto
VetorInteiros. Compare com a Q5, onde inverter() altera o próprio objeto.
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  void preencherInvertidoRec(VetorInteiros &destino, int i) const{
    int n = (int)dados.size();
    if(i == n){
      return;
    }
    destino.dados[n - 1 - i] = dados[i];
    preencherInvertidoRec(destino,i + 1);
  }

public:
  VetorInteiros(int n = 0) : dados(n){}

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

  VetorInteiros invertido() const{
    VetorInteiros novo((int)dados.size());
    preencherInvertidoRec(novo,0);
    return novo;
  }

  void imprimir() const{
    for(int x : dados){
      cout << "[" << x << "]";
    }
    cout << endl;
  }
};

int main(){
  VetorInteiros original;
  original.ler();

  VetorInteiros invertido = original.invertido();

  cout << "Original : ";
  original.imprimir();
  cout << "Invertido : ";
  invertido.imprimir();

  return 0;
}
