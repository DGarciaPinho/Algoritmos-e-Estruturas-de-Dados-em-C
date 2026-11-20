/*
Lista 6 - Strings (versão C++ / POO)

Parte 3 - Problemas contextualizados
(A restrição de <string.h> era da Parte 2; aqui já é usado std::string.)

23. (Validação de senha) Leia uma senha e verifique se ela satisfaz simultaneamente:
  - pelo menos oito caracteres;
  - pelo menos uma letra maiúscula;
  - pelo menos uma letra minúscula;
  - pelo menos um algarismo;
  - pelo menos um caractere especial (qualquer coisa que não seja letra, algarismo ou espaço);
  - não possuir espaços em branco.
Imprima "Senha valida" ou "Senha invalida".
Ex.: "algoritmo12" -> invalida; "alGoritmo@12" -> valida.

Versão POO: a classe Senha guarda o texto e tem um método para cada regra. O método
ehValida() só combina as regras.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Senha{
private:
  string texto;

  // Verifica se existe algum caractere que satisfaz o teste recebido
  bool possui(int (*teste)(int)) const{
    for(char c : texto){
      if(teste((unsigned char)c)){
        return true;
      }
    }
    return false;
  }

  static int ehEspecial(int c){
    return !isalnum(c) && c != ' ';
  }

  static int ehEspaco(int c){
    return c == ' ';
  }

public:
  Senha(const string &texto) : texto(texto){}

  bool temTamanhoMinimo() const{ return texto.size() >= 8; }
  bool temMaiuscula() const{ return possui(isupper); }
  bool temMinuscula() const{ return possui(islower); }
  bool temAlgarismo() const{ return possui(isdigit); }
  bool temEspecial() const{ return possui(ehEspecial); }
  bool temEspaco() const{ return possui(ehEspaco); }

  bool ehValida() const{
    return temTamanhoMinimo() && temMaiuscula() && temMinuscula() &&
           temAlgarismo() && temEspecial() && !temEspaco();
  }
};

int main(){
  string entrada;

  cout << "=====================" << endl;
  cout << "Digite a senha :" << endl;
  cout << "=====================" << endl;
  getline(cin,entrada);

  Senha senha(entrada);

  if(senha.ehValida()){
    cout << "Senha valida" << endl;
  }else{
    cout << "Senha invalida" << endl;
  }

  return 0;
}
