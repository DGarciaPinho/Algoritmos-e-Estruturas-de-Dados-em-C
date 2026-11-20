/*
Lista 7 - Recursividade (versão C++ / POO)

12. Implemente uma função recursiva que retorna o maior elemento de um vetor de inteiros de
tamanho n.

  maior(n) = v[0]                          se n == 1
  maior(n) = max(v[n-1], maior(n-1))       caso contrário
*/

#include <iostream>
#include <vector>

using namespace std;

class VetorInteiros{
private:
  vector<int> dados;

  int maiorRec(int n) const{
    if(n == 1){
      return dados[0];
    }
    int maiorDoResto = maiorRec(n - 1);
    return dados[n - 1] > maiorDoResto ? dados[n - 1] : maiorDoResto;
  }

public:
  void ler(){
    int n;
    do{
      cout << "=====================" << endl;
      cout << "Digite o tamanho (>= 1) :" << endl;
      cout << "=====================" << endl;
      cin >> n;
    }while(n < 1);

    dados.resize(n);
    for(int i=0;i<n;i++){
      cout << "Elemento [" << i+1 << "] : ";
      cin >> dados[i];
    }
  }

  int maior() const{
    return maiorRec((int)dados.size());
  }
};

int main(){
  VetorInteiros vetor;
  vetor.ler();

  cout << "Maior elemento : " << vetor.maior() << endl;

  return 0;
}
