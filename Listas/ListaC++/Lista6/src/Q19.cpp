/*
Lista 6 - Strings (versão C++ / POO)

19. Implemente a função:
int localizarSubstring(const char *texto, const char *termo);
A função deverá procurar a primeira ocorrência de termo dentro de texto e retornar a posição em
que ela começa, ou -1 se não for encontrado. Posições a partir de zero, diferenciando
maiúsculas de minúsculas. Ex.: texto = "estrutura de dados", termo = "dados" -> 13.
*/

#include <iostream>

using namespace std;

class MinhaString{
private:
  static const int TAM = 100;
  char texto[TAM];

public:
  MinhaString(){
    texto[0] = '\0';
  }

  void ler(){
    cin.getline(texto,TAM);
  }

  int localizarSubstring(const MinhaString &termo) const{
    if(termo.texto[0] == '\0'){
      return 0;   // termo vazio "aparece" no início (mesmo comportamento do strstr)
    }

    for(int i=0;texto[i]!='\0';i++){
      int j = 0;
      while(termo.texto[j] != '\0' && texto[i + j] == termo.texto[j]){
        j++;
      }
      if(termo.texto[j] == '\0'){
        return i;
      }
    }
    return -1;
  }
};

int main(){
  MinhaString texto, termo;

  cout << "=====================" << endl;
  cout << "Digite o texto :" << endl;
  cout << "=====================" << endl;
  texto.ler();

  cout << "=====================" << endl;
  cout << "Digite o termo :" << endl;
  cout << "=====================" << endl;
  termo.ler();

  cout << "Posição : " << texto.localizarSubstring(termo) << endl;

  return 0;
}
