/*
Lista 6 - Strings (versão C++ / POO)

7. Implemente a função:
char* unirStrings(const char *s1, const char *s2);
A função deverá criar uma string alocada dinamicamente formada pelos caracteres da string s1
seguidos dos caracteres da string s2 e retornar o ponteiro para a string criada.

Versão POO: em vez de devolver um char* que o main teria que lembrar de liberar, a operação
vira a sobrecarga do operador + e devolve um OBJETO novo. A memória é alocada com new[]
dentro da classe e liberada automaticamente pelo destinatário (destrutor).
Diferente do +=, o + NÃO altera nenhum dos operandos (por isso é um método const).
*/

#include <iostream>

using namespace std;

class StringDinamica{
private:
  char *dados;

  static int comprimento(const char *str){
    int i = 0;
    while(str[i] != '\0'){
      i++;
    }
    return i;
  }

  static void copiar(const char *origem, char *destino){
    int i = 0;
    while(origem[i] != '\0'){
      destino[i] = origem[i];
      i++;
    }
    destino[i] = '\0';
  }

public:
  StringDinamica(const char *str = ""){
    dados = new char[comprimento(str) + 1];
    copiar(str,dados);
  }

  StringDinamica(const StringDinamica &outra){
    dados = new char[comprimento(outra.dados) + 1];
    copiar(outra.dados,dados);
  }

  StringDinamica &operator=(const StringDinamica &outra){
    if(this != &outra){
      delete[] dados;
      dados = new char[comprimento(outra.dados) + 1];
      copiar(outra.dados,dados);
    }
    return *this;
  }

  ~StringDinamica(){
    delete[] dados;
  }

  // unirStrings
  StringDinamica operator+(const StringDinamica &s2) const{
    int t1 = comprimento(dados);
    int t2 = comprimento(s2.dados);

    StringDinamica resultado;
    delete[] resultado.dados;               // descarta a string vazia do construtor
    resultado.dados = new char[t1 + t2 + 1];

    copiar(dados,resultado.dados);
    copiar(s2.dados,resultado.dados + t1);  // continua a partir do fim de s1

    return resultado;
  }

  void imprimir() const{
    cout << dados << endl;
  }
};

int main(){
  char buffer[100];

  cout << "=====================" << endl;
  cout << "Digite a primeira String :" << endl;
  cout << "=====================" << endl;
  cin.getline(buffer,100);
  StringDinamica s1(buffer);

  cout << "=====================" << endl;
  cout << "Digite a segunda String :" << endl;
  cout << "=====================" << endl;
  cin.getline(buffer,100);
  StringDinamica s2(buffer);

  StringDinamica unida = s1 + s2;

  cout << "Resultado : ";
  unida.imprimir();

  return 0;
}
