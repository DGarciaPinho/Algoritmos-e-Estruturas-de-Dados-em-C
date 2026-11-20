/*
Lista 6 - Strings (versão C++ / POO)

11. Implemente a função:
char* clonarStringInvertida(const char *str);
A função deverá retornar um ponteiro para uma string alocada dinamicamente contendo os
caracteres da string recebida em ordem inversa. Ex.: "algoritmo" -> "omtirogla".

Versão POO: o método clonarInvertida() é const (não mexe no objeto original) e retorna um
NOVO objeto StringDinamica, cuja memória (new[]) é liberada pelo destrutor dele.
*/

#include <iostream>

using namespace std;

class StringDinamica{
private:
  char *dados;
  int tamanho;

  static int comprimento(const char *str){
    int i = 0;
    while(str[i] != '\0'){
      i++;
    }
    return i;
  }

  // Construtor privado: cria uma string "em branco" de tamanho n (uso interno)
  explicit StringDinamica(int n){
    tamanho = n;
    dados = new char[n + 1];
    dados[n] = '\0';
  }

public:
  StringDinamica(const char *str){
    tamanho = comprimento(str);
    dados = new char[tamanho + 1];
    for(int i=0;i<=tamanho;i++){
      dados[i] = str[i];
    }
  }

  StringDinamica(const StringDinamica &outra) : StringDinamica(outra.dados){}

  StringDinamica &operator=(const StringDinamica &outra){
    if(this != &outra){
      delete[] dados;
      tamanho = outra.tamanho;
      dados = new char[tamanho + 1];
      for(int i=0;i<=tamanho;i++){
        dados[i] = outra.dados[i];
      }
    }
    return *this;
  }

  ~StringDinamica(){
    delete[] dados;
  }

  StringDinamica clonarInvertida() const{
    StringDinamica invertida(tamanho);
    for(int i=0;i<tamanho;i++){
      invertida.dados[i] = dados[tamanho - 1 - i];
    }
    return invertida;
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
  StringDinamica invertida = original.clonarInvertida();

  cout << "Original : ";
  original.imprimir();
  cout << "Invertida : ";
  invertida.imprimir();

  return 0;
}
