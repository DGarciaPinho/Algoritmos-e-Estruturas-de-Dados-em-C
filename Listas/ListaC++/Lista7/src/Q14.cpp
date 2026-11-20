/*
Lista 7 - Recursividade (versão C++ / POO)

Parte 2 - Problemas contextualizados

14. (Palíndromo) Implemente uma função recursiva que determina se uma string é palíndromo,
retornando 1 (sim) ou 0 (não). Diferenças entre maiúsculas e minúsculas são desconsideradas,
mas espaços e demais caracteres participam da comparação. Ex.: "Arara" é palíndroma.
  Exemplo 1: Entrada: Arara    Saída: SIM
  Exemplo 2: Entrada: Caraiva  Saída: NÃO

  palindromo(i, j) = true                     se i >= j
  palindromo(i, j) = false                    se texto[i] != texto[j]
  palindromo(i, j) = palindromo(i+1, j-1)     caso contrário
*/

#include <iostream>

using namespace std;

class Texto{
private:
  static const int TAM = 100;
  char texto[TAM];

  static char paraMinuscula(char c){
    if(c >= 'A' && c <= 'Z'){
      return c - 'A' + 'a';
    }
    return c;
  }

  int tamanhoRec(int i) const{
    if(texto[i] == '\0'){
      return 0;
    }
    return 1 + tamanhoRec(i + 1);
  }

  bool palindromoRec(int i, int j) const{
    if(i >= j){
      return true;
    }
    if(paraMinuscula(texto[i]) != paraMinuscula(texto[j])){
      return false;
    }
    return palindromoRec(i + 1,j - 1);
  }

public:
  Texto(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  bool ehPalindromo() const{
    return palindromoRec(0,tamanhoRec(0) - 1);
  }
};

int main(){
  Texto texto;

  cout << "Entrada: ";
  texto.ler();

  cout << "Saída: " << (texto.ehPalindromo() ? "SIM" : "NÃO") << endl;

  return 0;
}
