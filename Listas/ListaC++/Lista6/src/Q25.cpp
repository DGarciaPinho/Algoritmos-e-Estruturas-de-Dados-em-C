/*
Lista 6 - Strings (versão C++ / POO)

25. (Compactação de texto) Uma sequência de caracteres iguais é representada pelo caractere
seguido da quantidade de vezes que ele aparece consecutivamente.
Ex.: "aaabbccccdaa" -> "a3b2c4d1a2".
Diferencia maiúsculas de minúsculas. Entrada só com letras, no máximo 100 caracteres. A string
compactada deve ser armazenada antes de ser impressa. Ao final, informe se houve redução.
Exemplo:
  Entrada: aaaaaabbbbcc
  Saida: a6b4c2
  Houve reducao: sim

Versão POO: o objeto Compactador guarda o original e o compactado como atributos.
O compactado é calculado no construtor e consultado pelos getters.
*/

#include <iostream>
#include <string>

using namespace std;

class Compactador{
private:
  string original;
  string compactado;

  void compactar(){
    compactado.clear();
    size_t i = 0;
    while(i < original.size()){
      char atual = original[i];
      int contador = 0;
      while(i < original.size() && original[i] == atual){
        contador++;
        i++;
      }
      compactado += atual;
      compactado += to_string(contador);
    }
  }

public:
  Compactador(const string &texto) : original(texto){
    compactar();
  }

  string getOriginal() const{ return original; }
  string getCompactado() const{ return compactado; }

  bool houveReducao() const{
    return compactado.size() < original.size();
  }
};

int main(){
  string texto;

  cout << "Entrada: ";
  getline(cin,texto);

  Compactador compactador(texto);

  cout << "Saida: " << compactador.getCompactado() << endl;
  cout << "Houve reducao: " << (compactador.houveReducao() ? "sim" : "nao") << endl;

  return 0;
}
