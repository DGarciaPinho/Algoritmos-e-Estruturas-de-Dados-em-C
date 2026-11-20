/*
Lista 7 - Recursividade (versão C++ / POO)

4. Implemente uma função recursiva que calcula a soma dos elementos de um vetor de double de
tamanho n.

Versão POO: aqui o vetor é alocado com new[] e liberado no destrutor, para treinar o
gerenciamento de memória dentro de uma classe. Como a classe tem ponteiro, a cópia foi
PROIBIDA (= delete) para evitar dois objetos com o mesmo ponteiro.
*/

#include <iostream>

using namespace std;

class VetorDouble{
private:
  double *dados;
  int tamanho;

  double somaRec(int n) const{
    if(n == 0){
      return 0;
    }
    return dados[n - 1] + somaRec(n - 1);
  }

public:
  VetorDouble(int tamanho){
    this->tamanho = tamanho;
    dados = new double[tamanho];
  }

  VetorDouble(const VetorDouble &) = delete;
  VetorDouble &operator=(const VetorDouble &) = delete;

  ~VetorDouble(){
    delete[] dados;
  }

  void ler(){
    for(int i=0;i<tamanho;i++){
      cout << "Elemento [" << i+1 << "] : ";
      cin >> dados[i];
    }
  }

  double soma() const{
    return somaRec(tamanho);
  }
};

int main(){
  int n;

  cout << "=====================" << endl;
  cout << "Digite o tamanho :" << endl;
  cout << "=====================" << endl;
  cin >> n;

  VetorDouble vetor(n);
  vetor.ler();

  cout << "Soma : " << vetor.soma() << endl;

  return 0;
}
