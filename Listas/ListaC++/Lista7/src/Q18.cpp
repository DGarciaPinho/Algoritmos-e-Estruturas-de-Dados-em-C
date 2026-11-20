/*
Lista 7 - Recursividade (versão C++ / POO)

18. (Verificação de ordenação de um vetor) Leia um vetor de inteiros e determine se está em
ordem crescente, permitindo valores repetidos (cada elemento, a partir do segundo, é >= ao
anterior). Use recursividade.
  Entrada: a primeira linha contém N (1 <= N <= 1000); a segunda, os N elementos.
  Saída: SIM se estiver em ordem crescente; caso contrário, NAO.
Exemplo 1: 5 / -3 0 0 7 12 -> SIM
Exemplo 2: 4 / 1 5 3 8     -> NAO
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  bool ordenadoRec(int i) const{
    if(i >= (int)dados.size()){   // chegou ao fim sem achar problema
      return true;
    }
    if(dados[i] < dados[i - 1]){
      return false;
    }
    return ordenadoRec(i + 1);
  }

public:
  void ler(){
    int n;
    cin >> n;
    dados.resize(n);
    for(int i=0;i<n;i++){
      cin >> dados[i];
    }
  }

  bool estaOrdenado() const{
    return ordenadoRec(1);
  }
};

int main(){
  VetorInteiros vetor;
  vetor.ler();

  cout << (vetor.estaOrdenado() ? "SIM" : "NAO") << endl;

  return 0;
}
