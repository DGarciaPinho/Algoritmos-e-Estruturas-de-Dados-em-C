/*
Lista 6 - Strings (versão C++ / POO)

3. A função fgets pode armazenar na string o caractere de quebra de linha ('\n') produzido quando
o usuário pressiona Enter. Desenvolva um programa para observar e tratar esse comportamento:
(a) Declare um arranjo de caracteres com 100 posições.
(b) Leia uma frase utilizando a função fgets, respeitando a capacidade do arranjo.
(c) Imprima a frase e, logo depois, algum delimitador (o '\n' vai aparecer antes dele).
(d) Percorra a string, localize o caractere '\n' e substitua-o pelo caractere nulo '\0'.
(e) Imprima novamente a frase com o delimitador e constate que o '\n' sumiu.

Versão POO: em C++ o cin.getline já descarta o '\n', então para OBSERVAR o problema a classe
continua usando fgets (de <cstdio>, que também é C++). A correção (d) vira um método.
*/

#include <iostream>
#include <cstdio>

using namespace std;

class Frase{
private:
  static const int TAM = 100;
  char texto[TAM];

public:
  Frase(){
    texto[0] = '\0';
  }

  void lerComFgets(){
    fgets(texto,TAM,stdin);
  }

  void imprimirComDelimitador() const{
    cout << "[" << texto << "]" << endl;
  }

  // Retorna true se encontrou e removeu o '\n'
  bool removerQuebraDeLinha(){
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] == '\n'){
        texto[i] = '\0';
        return true;
      }
    }
    return false;
  }
};

int main(){
  Frase frase;

  cout << "=====================" << endl;
  cout << "Digite uma frase :" << endl;
  cout << "=====================" << endl;
  frase.lerComFgets();

  cout << "Antes : ";
  frase.imprimirComDelimitador();

  if(frase.removerQuebraDeLinha()){
    cout << "O '\\n' foi encontrado e substituido por '\\0'." << endl;
  }

  cout << "Depois : ";
  frase.imprimirComDelimitador();

  return 0;
}
