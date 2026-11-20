/*
Lista 6 - Strings (versão C++ / POO)

22. Repita o exercício 21, porém sem utilizar a função strtok de <string.h>.

Versão POO: mesma interface pública da Q21 (construtor, getQuantidade, imprimirPalavras).
Só a implementação PRIVADA mudou -> quem usa a classe nem percebe a diferença.
Isso é o encapsulamento na prática.
*/

#include <iostream>

using namespace std;

class SeparadorDePalavras{
private:
  static const int MAX_PALAVRAS = 20;
  static const int TAM_PALAVRA = 30;

  char palavras[MAX_PALAVRAS][TAM_PALAVRA];
  int quantidade;

public:
  SeparadorDePalavras(const char *frase){
    quantidade = separarPalavras(frase);
  }

  int separarPalavras(const char *frase){
    int n = 0;
    int i = 0;

    while(frase[i] != '\0' && n < MAX_PALAVRAS){
      // pula os espaços antes da palavra
      while(frase[i] == ' '){
        i++;
      }
      if(frase[i] == '\0'){
        break;
      }

      // copia a palavra até o próximo espaço
      int j = 0;
      while(frase[i] != ' ' && frase[i] != '\0'){
        if(j < TAM_PALAVRA - 1){
          palavras[n][j] = frase[i];
          j++;
        }
        i++;
      }
      palavras[n][j] = '\0';
      n++;
    }

    return n;
  }

  int getQuantidade() const{
    return quantidade;
  }

  void imprimirPalavras() const{
    for(int i=0;i<quantidade;i++){
      cout << "palavras[" << i << "]: \"" << palavras[i] << "\"" << endl;
    }
  }
};

int main(){
  char frase[100];

  cout << "=====================" << endl;
  cout << "Digite a frase :" << endl;
  cout << "=====================" << endl;
  cin.getline(frase,100);

  SeparadorDePalavras separador(frase);

  cout << "Quantidade de palavras : " << separador.getQuantidade() << endl;
  separador.imprimirPalavras();

  return 0;
}
