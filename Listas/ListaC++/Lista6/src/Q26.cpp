/*
Lista 6 - Strings (versão C++ / POO)

26. (Cifra de César) Cada letra da mensagem é substituída por outra algumas posições adiante no
alfabeto. Leia uma mensagem e um deslocamento entre 0 e 25. Ao passar do final do alfabeto, a
contagem continua do início. Regras:
  - maiúsculas continuam maiúsculas e minúsculas continuam minúsculas;
  - espaços, algarismos, pontuação e outros caracteres não são modificados;
  - a mensagem original deve ser preservada e o texto codificado armazenado em outra string.
Ex.: "Ataque as 10 horas!" com deslocamento 3 -> "Dwdtxh dv 10 krudv!".
Apresente a mensagem original e a codificada.

Versão POO: a CHAVE (deslocamento) é o estado do objeto CifraDeCesar. O mesmo objeto pode
codificar várias mensagens. Bônus: decodificar() usa o deslocamento inverso.
*/

#include <iostream>
#include <string>

using namespace std;

class CifraDeCesar{
private:
  int deslocamento;

  static char deslocar(char c, int d){
    if(c >= 'a' && c <= 'z'){
      return 'a' + (c - 'a' + d) % 26;
    }
    if(c >= 'A' && c <= 'Z'){
      return 'A' + (c - 'A' + d) % 26;
    }
    return c;
  }

public:
  CifraDeCesar(int deslocamento){
    // normaliza para 0..25 (aceita até valores negativos)
    this->deslocamento = ((deslocamento % 26) + 26) % 26;
  }

  // const string& : recebe a original sem copiar e sem poder alterar
  string codificar(const string &mensagem) const{
    string codificada = mensagem;
    for(char &c : codificada){
      c = deslocar(c,deslocamento);
    }
    return codificada;
  }

  string decodificar(const string &mensagem) const{
    string decodificada = mensagem;
    for(char &c : decodificada){
      c = deslocar(c,26 - deslocamento);
    }
    return decodificada;
  }
};

int main(){
  string mensagem;
  int deslocamento;

  cout << "=====================" << endl;
  cout << "Digite a mensagem :" << endl;
  cout << "=====================" << endl;
  getline(cin,mensagem);

  do{
    cout << "Deslocamento (0 a 25) : ";
    cin >> deslocamento;
  }while(deslocamento < 0 || deslocamento > 25);

  CifraDeCesar cifra(deslocamento);
  string codificada = cifra.codificar(mensagem);

  cout << "Original : " << mensagem << endl;
  cout << "Codificada : " << codificada << endl;

  return 0;
}
