/*
Lista 6 - Strings (versão C++ / POO)

14. Implemente a função:
int compararStrings(const char *s1, const char *s2);
A função deverá comparar lexicograficamente as duas strings e retornar:
  -1, caso s1 seja menor que s2;
   0, caso as strings sejam iguais;
  +1, caso s1 seja maior que s2.
A comparação deverá considerar os códigos dos caracteres. Desenvolva um programa para ler duas
strings e informar o resultado, verificando as três possibilidades de retorno.

Versão POO: o método comparar() faz o trabalho e, a partir dele, foram sobrecarregados os
operadores ==, !=, < e >. Assim dá para escrever s1 < s2 como se fosse um tipo nativo.
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

  int comparar(const MinhaString &outra) const{
    int i = 0;
    while(texto[i] != '\0' && texto[i] == outra.texto[i]){
      i++;
    }
    // unsigned char para comparar pelo código (0..255), igual ao strcmp
    unsigned char a = texto[i];
    unsigned char b = outra.texto[i];
    if(a < b){
      return -1;
    }
    if(a > b){
      return 1;
    }
    return 0;
  }

  bool operator==(const MinhaString &outra) const{ return comparar(outra) == 0; }
  bool operator!=(const MinhaString &outra) const{ return comparar(outra) != 0; }
  bool operator<(const MinhaString &outra) const{ return comparar(outra) < 0; }
  bool operator>(const MinhaString &outra) const{ return comparar(outra) > 0; }
};

int main(){
  MinhaString s1, s2;

  cout << "=====================" << endl;
  cout << "Digite a primeira String :" << endl;
  cout << "=====================" << endl;
  s1.ler();

  cout << "=====================" << endl;
  cout << "Digite a segunda String :" << endl;
  cout << "=====================" << endl;
  s2.ler();

  int resultado = s1.comparar(s2);

  cout << "Retorno de comparar : " << resultado << endl;

  if(resultado == -1){
    cout << "s1 é menor que s2." << endl;
  }else if(resultado == 0){
    cout << "As strings são iguais." << endl;
  }else{
    cout << "s1 é maior que s2." << endl;
  }

  // Mesma conclusão usando os operadores sobrecarregados
  cout << "s1 < s2 : " << (s1 < s2 ? "sim" : "nao") << endl;
  cout << "s1 == s2 : " << (s1 == s2 ? "sim" : "nao") << endl;
  cout << "s1 > s2 : " << (s1 > s2 ? "sim" : "nao") << endl;

  return 0;
}
