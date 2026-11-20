/*
Lista 7 - Recursividade (versão C++ / POO)

16. (Cifra de César) Leia uma mensagem e um deslocamento inteiro entre 0 e 25. Codifique a
mensagem aplicando o deslocamento a todas as letras (passando do fim do alfabeto, volta ao
início). Regras:
  - maiúsculas continuam maiúsculas e minúsculas continuam minúsculas;
  - espaços, algarismos, pontuação e outros caracteres não são modificados;
  - a mensagem original deve ser preservada; o texto codificado fica em outra string.
Ex.: "Ataque as 10 horas!" com deslocamento 3 -> "Dwdtxh dv 10 krudv!".
Apresente a original e a codificada. A função de codificação deve usar RECURSIVIDADE.

Versão POO: mesma classe CifraDeCesar da Lista 6 (Q26), mas o laço virou recursão.
*/

#include <iostream>

using namespace std;

class CifraDeCesar{
private:
  int deslocamento;

  char deslocar(char c) const{
    if(c >= 'a' && c <= 'z'){
      return 'a' + (c - 'a' + deslocamento) % 26;
    }
    if(c >= 'A' && c <= 'Z'){
      return 'A' + (c - 'A' + deslocamento) % 26;
    }
    return c;
  }

  void codificarRec(const char *origem, char *destino, int i) const{
    destino[i] = deslocar(origem[i]);   // o '\0' passa sem mudar
    if(origem[i] == '\0'){
      return;
    }
    codificarRec(origem,destino,i + 1);
  }

public:
  CifraDeCesar(int deslocamento) : deslocamento(deslocamento % 26){}

  void codificar(const char *origem, char *destino) const{
    codificarRec(origem,destino,0);
  }
};

int main(){
  char mensagem[200];
  char codificada[200];
  int deslocamento;

  cout << "=====================" << endl;
  cout << "Digite a mensagem :" << endl;
  cout << "=====================" << endl;
  cin.getline(mensagem,200);

  do{
    cout << "Deslocamento (0 a 25) : ";
    cin >> deslocamento;
  }while(deslocamento < 0 || deslocamento > 25);

  CifraDeCesar cifra(deslocamento);
  cifra.codificar(mensagem,codificada);

  cout << "Original : " << mensagem << endl;
  cout << "Codificada : " << codificada << endl;

  return 0;
}
