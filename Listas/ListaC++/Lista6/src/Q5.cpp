/*
Lista 6 - Strings (versão C++ / POO)

5. Implemente a função:
void copiarString(const char *origem, char *destino);
A função deverá copiar todos os caracteres da string origem para a string destino, incluindo o
caractere nulo '\0'. Desenvolva um programa para ler uma string, copiá-la para outro arranjo e
imprimir a string copiada.

Versão POO: "copiar um objeto para outro" em C++ é feito por dois membros especiais:
  - construtor de cópia : StringDinamica copia = original;   (cria um objeto NOVO a partir de outro)
  - operador =          : outra = original;                  (o objeto já existia)
Como a classe guarda um ponteiro (char *dados alocado com new[]), a cópia precisa alocar o SEU
próprio arranjo e copiar os caracteres (cópia profunda). Se a classe usasse a cópia padrão, os
dois objetos apontariam para o mesmo arranjo e o destrutor daria delete[] duas vezes.
Isso é a "Regra dos Três": destrutor + construtor de cópia + operator=.
*/

#include <iostream>

using namespace std;

class StringDinamica{
private:
  char *dados;

  static int comprimento(const char *str){
    int i = 0;
    while(str[i] != '\0'){
      i++;
    }
    return i;
  }

  // A função pedida no enunciado (copia incluindo o '\0')
  static void copiarString(const char *origem, char *destino){
    int i = 0;
    while(origem[i] != '\0'){
      destino[i] = origem[i];
      i++;
    }
    destino[i] = '\0';
  }

public:
  StringDinamica(const char *str = ""){
    dados = new char[comprimento(str) + 1];
    copiarString(str,dados);
  }

  // Construtor de cópia
  StringDinamica(const StringDinamica &outra){
    dados = new char[comprimento(outra.dados) + 1];
    copiarString(outra.dados,dados);
  }

  // Operador de atribuição
  StringDinamica &operator=(const StringDinamica &outra){
    if(this != &outra){        // proteção contra s = s;
      delete[] dados;
      dados = new char[comprimento(outra.dados) + 1];
      copiarString(outra.dados,dados);
    }
    return *this;
  }

  ~StringDinamica(){
    delete[] dados;
  }

  void imprimir() const{
    cout << dados << endl;
  }
};

int main(){
  char buffer[100];

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  cin.getline(buffer,100);

  StringDinamica original(buffer);

  StringDinamica copia = original;   // construtor de cópia
  StringDinamica outra;
  outra = original;                  // operator=

  cout << "Original : ";
  original.imprimir();
  cout << "Copia (construtor de copia) : ";
  copia.imprimir();
  cout << "Copia (operator=) : ";
  outra.imprimir();

  return 0;
}
