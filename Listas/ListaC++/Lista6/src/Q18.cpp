/*
Lista 6 - Strings (versão C++ / POO)

18. Implemente a função:
int obterSubstring(const char *origem, const int inicio, const int quantidade, char *destino);
A função deverá copiar para destino até quantidade caracteres da origem, começando na posição
inicio, finalizando com '\0', e retornar quantos caracteres foram copiados. Se a posição inicial
for inválida ou a quantidade for <= 0, produz string vazia e retorna zero. Se existirem menos
caracteres do que o solicitado, copia apenas até o final da string.

Versão POO: origem é o próprio objeto (método const) e o destino é outro objeto MinhaString
passado por REFERÊNCIA (MinhaString &), para que a alteração apareça no main.
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

  int comprimento() const{
    int i = 0;
    while(texto[i] != '\0'){
      i++;
    }
    return i;
  }

  int obterSubstring(int inicio, int quantidade, MinhaString &destino) const{
    destino.texto[0] = '\0';
    if(inicio < 0 || inicio >= comprimento() || quantidade <= 0){
      return 0;
    }

    int copiados = 0;
    while(copiados < quantidade && texto[inicio + copiados] != '\0'){
      destino.texto[copiados] = texto[inicio + copiados];
      copiados++;
    }
    destino.texto[copiados] = '\0';

    return copiados;
  }
};

int main(){
  MinhaString origem, destino;
  int inicio, quantidade;

  cout << "=====================" << endl;
  cout << "Digite a String :" << endl;
  cout << "=====================" << endl;
  origem.ler();

  cout << "Posição inicial : ";
  cin >> inicio;
  cout << "Quantidade : ";
  cin >> quantidade;

  int copiados = origem.obterSubstring(inicio,quantidade,destino);

  cout << "Substring : ";
  destino.imprimirComDelimitador();
  cout << "Caracteres copiados : " << copiados << endl;

  return 0;
}
