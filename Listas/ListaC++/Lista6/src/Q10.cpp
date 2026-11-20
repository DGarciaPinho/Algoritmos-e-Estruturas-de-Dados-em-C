/*
Lista 6 - Strings (versão C++ / POO)

10. Implemente a função:
void contarCaracteres(const char *str, int *vogais, int *consoantes, int *algarismos);
A função deverá percorrer a string e determinar a quantidade de vogais, consoantes e algarismos.
Os resultados deverão ser devolvidos por meio dos parâmetros. Letras maiúsculas e minúsculas
deverão ser consideradas. Caracteres que não sejam letras nem algarismos são desconsiderados.
Vogais: apenas a, e, i, o, u (maiúsculas e minúsculas, sem acento).

Versão POO: em vez de 3 ponteiros de saída, os resultados viram ATRIBUTOS de um objeto
ContadorCaracteres. O construtor recebe o texto e já faz a contagem; os resultados são lidos
pelos getters. (A versão com parâmetros de saída também existe, usando REFERÊNCIAS int&, que é
o jeito C++ de fazer o que em C se fazia com ponteiros.)
*/

#include <iostream>

using namespace std;

class ContadorCaracteres{
private:
  int vogais;
  int consoantes;
  int algarismos;

  static bool ehLetra(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  static bool ehVogal(char c){
    if(c >= 'A' && c <= 'Z'){
      c = c - 'A' + 'a';
    }
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  static bool ehAlgarismo(char c){
    return c >= '0' && c <= '9';
  }

public:
  ContadorCaracteres(const char *str){
    contarCaracteres(str,vogais,consoantes,algarismos);
  }

  // Versão "parâmetros de saída" com referências
  static void contarCaracteres(const char *str, int &vogais, int &consoantes, int &algarismos){
    vogais = consoantes = algarismos = 0;
    for(int i=0;str[i]!='\0';i++){
      if(ehLetra(str[i])){
        if(ehVogal(str[i])){
          vogais++;
        }else{
          consoantes++;
        }
      }else if(ehAlgarismo(str[i])){
        algarismos++;
      }
    }
  }

  int getVogais() const{ return vogais; }
  int getConsoantes() const{ return consoantes; }
  int getAlgarismos() const{ return algarismos; }
};

int main(){
  char texto[100];

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  cin.getline(texto,100);

  ContadorCaracteres contador(texto);

  cout << "Vogais : " << contador.getVogais() << endl;
  cout << "Consoantes : " << contador.getConsoantes() << endl;
  cout << "Algarismos : " << contador.getAlgarismos() << endl;

  return 0;
}
