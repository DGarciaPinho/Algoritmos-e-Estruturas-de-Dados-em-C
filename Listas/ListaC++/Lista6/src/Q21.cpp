/*
Lista 6 - Strings (versão C++ / POO)

21. Implemente a função:
int separarPalavras(const char *frase, char palavras[][30]);
A função deverá separar as palavras da frase e armazená-las, individualmente, nas linhas da
matriz palavras, cada uma finalizada com '\0'. Palavra = sequência de caracteres diferentes de
espaço. A frase original não pode ser modificada. Retorna a quantidade de palavras.
Considere: frase com no máximo 99 caracteres, no máximo 20 palavras, cada palavra com no
máximo 29 caracteres, e somente ' ' como separador.
Sua solução deverá utilizar a função strtok de <string.h>.

Versão POO: a classe SeparadorDePalavras guarda a matriz de palavras e a quantidade como
atributos. O construtor recebe a frase e já faz a separação.
O strtok ESTRAGA a string que recebe (coloca '\0' nos separadores), então ele trabalha numa
cópia local -> a frase original fica intacta (por isso ela é const char*).
*/

#include <iostream>
#include <cstring>

using namespace std;

class SeparadorDePalavras{
private:
  static const int MAX_PALAVRAS = 20;
  static const int TAM_PALAVRA = 30;
  static const int TAM_FRASE = 100;

  char palavras[MAX_PALAVRAS][TAM_PALAVRA];
  int quantidade;

public:
  SeparadorDePalavras(const char *frase){
    quantidade = separarPalavras(frase);
  }

  int separarPalavras(const char *frase){
    char copia[TAM_FRASE];
    strncpy(copia,frase,TAM_FRASE - 1);
    copia[TAM_FRASE - 1] = '\0';

    int n = 0;
    char *token = strtok(copia," ");
    while(token != nullptr && n < MAX_PALAVRAS){
      strncpy(palavras[n],token,TAM_PALAVRA - 1);
      palavras[n][TAM_PALAVRA - 1] = '\0';
      n++;
      token = strtok(nullptr," ");
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
