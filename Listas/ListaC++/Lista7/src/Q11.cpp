/*
Lista 7 - Recursividade (versão C++ / POO)

11. Implemente uma função recursiva que verifica se duas strings são iguais.

Versão POO: o método igual() é recursivo e o operador == foi sobrecarregado para usá-lo,
então dá para escrever if(s1 == s2).
Repare que um método da classe pode acessar os atributos PRIVADOS de OUTRO objeto da mesma
classe (outra.texto) - o private é por classe, não por objeto.
*/

#include <iostream>

using namespace std;

class Texto{
private:
  static const int TAM = 100;
  char texto[TAM];

  bool igualRec(const Texto &outra, int i) const{
    if(texto[i] != outra.texto[i]){
      return false;
    }
    if(texto[i] == '\0'){   // chegaram juntas ao fim
      return true;
    }
    return igualRec(outra,i + 1);
  }

public:
  Texto(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  bool igual(const Texto &outra) const{
    return igualRec(outra,0);
  }

  bool operator==(const Texto &outra) const{
    return igual(outra);
  }
};

int main(){
  Texto s1, s2;

  cout << "=====================" << endl;
  cout << "Digite a primeira String :" << endl;
  cout << "=====================" << endl;
  s1.ler();

  cout << "=====================" << endl;
  cout << "Digite a segunda String :" << endl;
  cout << "=====================" << endl;
  s2.ler();

  if(s1 == s2){
    cout << "As strings são iguais." << endl;
  }else{
    cout << "As strings são diferentes." << endl;
  }

  return 0;
}
