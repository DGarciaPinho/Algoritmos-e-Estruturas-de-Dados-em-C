/*
Lista 6 - Strings (versão C++ / POO)

24. (Análise da frequência de uma palavra) Leia um texto e uma palavra, e conte quantas vezes a
palavra aparece no texto:
  - diferenças entre maiúsculas e minúsculas são desconsideradas;
  - somente palavras completas são contabilizadas ("dado" não conta dentro de "dados");
  - espaços e sinais de pontuação são separadores;
  - uma palavra é uma sequência de letras.
Ex.: "Dados sao importantes. Analisar dados permite transformar dados em informacao." e
"dados" -> "Frequencia: 3".
Texto com no máximo 500 caracteres; palavra com no máximo 30.

Versão POO: o AnalisadorDeTexto quebra o texto em palavras (em minúsculas) UMA vez, no
construtor, e guarda num vector. Depois dá para consultar a frequência de várias palavras sem
reprocessar o texto.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class AnalisadorDeTexto{
private:
  vector<string> palavras;

  static string paraMinusculas(const string &s){
    string resultado = s;
    for(char &c : resultado){
      c = tolower((unsigned char)c);
    }
    return resultado;
  }

public:
  AnalisadorDeTexto(const string &texto){
    string atual;
    for(char c : texto){
      if(isalpha((unsigned char)c)){
        atual += tolower((unsigned char)c);
      }else if(!atual.empty()){
        palavras.push_back(atual);
        atual.clear();
      }
    }
    if(!atual.empty()){
      palavras.push_back(atual);
    }
  }

  int frequencia(const string &palavra) const{
    string procurada = paraMinusculas(palavra);
    int quantidade = 0;
    for(const string &p : palavras){
      if(p == procurada){
        quantidade++;
      }
    }
    return quantidade;
  }
};

int main(){
  string texto, palavra;

  cout << "=====================" << endl;
  cout << "Digite o texto :" << endl;
  cout << "=====================" << endl;
  getline(cin,texto);

  cout << "=====================" << endl;
  cout << "Digite a palavra :" << endl;
  cout << "=====================" << endl;
  getline(cin,palavra);

  AnalisadorDeTexto analisador(texto);

  cout << "Frequencia: " << analisador.frequencia(palavra) << endl;

  return 0;
}
