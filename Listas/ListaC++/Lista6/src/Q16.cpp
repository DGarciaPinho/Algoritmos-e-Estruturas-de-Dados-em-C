/*
Lista 6 - Strings (versão C++ / POO)

16. Implemente a função:
void removerEspacosExcedentes(char *str);
A função deverá modificar a própria string de modo que:
  - todos os espaços do início sejam removidos;
  - todos os espaços do final sejam removidos;
  - cada sequência de dois ou mais espaços entre palavras vire um único espaço.
Considere como espaço somente ' '. Não deverá ser utilizado outro arranjo.
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

  void imprimirComDelimitador() const{
    cout << "[" << texto << "]" << endl;
  }

  void removerEspacosExcedentes(){
    int j = 0;
    for(int i=0;texto[i]!='\0';i++){
      if(texto[i] != ' '){
        texto[j] = texto[i];
        j++;
      }else if(j > 0 && texto[j-1] != ' '){
        // só mantém o espaço se não for no início e o anterior não for espaço
        texto[j] = ' ';
        j++;
      }
    }
    // pode ter sobrado um espaço no final
    if(j > 0 && texto[j-1] == ' '){
      j--;
    }
    texto[j] = '\0';
  }
};

int main(){
  MinhaString str;

  cout << "=====================" << endl;
  cout << "Digite a frase :" << endl;
  cout << "=====================" << endl;
  str.ler();

  str.removerEspacosExcedentes();

  cout << "Resultado : ";
  str.imprimirComDelimitador();

  return 0;
}
