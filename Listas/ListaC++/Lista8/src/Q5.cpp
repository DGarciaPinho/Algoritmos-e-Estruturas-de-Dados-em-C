/*
Lista 8 - Struct -> Classes (versão C++ / POO)

5. Altere a questão 4 para que os produtos sejam armazenados usando vetor dinâmico ao invés de
VLA, isto é, use ponteiro para ponteiro para Produto:
    Produto** produtos;
Essencialmente, altere a etapa (c) para alocar dinamicamente um vetor de n ponteiros para
produto (Produto*). Depois, para cada produto, chame ler() e armazene o ponteiro na posição
correta. Altere as demais etapas.

Versão POO: a classe Produto é a mesma da Q4. Só a parte PRIVADA do Estoque mudou: em vez de
vector<Produto*>, agora é um Produto** gerenciado na mão:
  - construtor : produtos = new Produto*[n];          (vetor de ponteiros)
  - destrutor  : delete em cada produto  +  delete[] no vetor de ponteiros
Atenção: new[] combina com delete[], e new combina com delete. Misturar é erro.
A interface pública (cadastrar, listar, buscar) continua igual -> o main quase não muda.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <new>

using namespace std;

class Produto{
private:
  int codigo;
  string nome;
  double preco;
  int quantidade;

public:
  Produto() : codigo(0), nome(""), preco(0), quantidade(0){}

  static Produto *ler(){
    Produto *p = new (nothrow) Produto;
    if(p == nullptr){
      return nullptr;
    }

    cout << "Codigo : ";
    cin >> p->codigo;

    cout << "Nome : ";
    cin >> ws;
    getline(cin,p->nome);
    if(p->nome.size() > 50){
      p->nome = p->nome.substr(0,50);
    }

    do{
      cout << "Preco : ";
      cin >> p->preco;
    }while(p->preco < 0);

    do{
      cout << "Quantidade : ";
      cin >> p->quantidade;
    }while(p->quantidade < 0);

    return p;
  }

  void imprimir() const{
    cout << "Codigo : " << codigo
         << " | Nome : " << nome
         << " | Preco : R$ " << fixed << setprecision(2) << preco
         << " | Quantidade : " << quantidade << endl;
  }

  int getCodigo() const{
    return codigo;
  }

  bool setQuantidade(int quantidade){
    if(quantidade < 0){
      return false;
    }
    this->quantidade = quantidade;
    return true;
  }
};

class Estoque{
private:
  Produto **produtos;
  int capacidade;
  int quantidade;   // quantos foram realmente criados (importa se uma alocação falhar)

public:
  Estoque(int capacidade){
    this->capacidade = capacidade;
    quantidade = 0;
    produtos = new (nothrow) Produto*[capacidade];
    if(produtos == nullptr){
      this->capacidade = 0;
    }
  }

  Estoque(const Estoque &) = delete;
  Estoque &operator=(const Estoque &) = delete;

  ~Estoque(){
    for(int i=0;i<quantidade;i++){
      delete produtos[i];
    }
    delete[] produtos;
  }

  bool alocado() const{
    return produtos != nullptr;
  }

  bool cadastrar(){
    for(int i=0;i<capacidade;i++){
      cout << "===== Produto " << i+1 << " =====" << endl;
      Produto *p = Produto::ler();
      if(p == nullptr){
        return false;
      }
      produtos[i] = p;
      quantidade++;
    }
    return true;
  }

  void listar() const{
    for(int i=0;i<quantidade;i++){
      produtos[i]->imprimir();
    }
  }

  Produto *buscar(int codigo){
    for(int i=0;i<quantidade;i++){
      if(produtos[i]->getCodigo() == codigo){
        return produtos[i];
      }
    }
    return nullptr;
  }
};

int main(){
  int n;
  do{
    cout << "Quantidade de produtos : ";
    cin >> n;
  }while(n <= 0);

  Estoque estoque(n);

  if(!estoque.alocado() || !estoque.cadastrar()){
    cout << "Erro de alocação. Encerrando." << endl;
    return 1;
  }

  cout << endl << "===== Produtos =====" << endl;
  estoque.listar();

  int codigo;
  cout << endl << "Codigo para buscar : ";
  cin >> codigo;

  Produto *encontrado = estoque.buscar(codigo);

  if(encontrado == nullptr){
    cout << "Produto não encontrado." << endl;
  }else{
    encontrado->imprimir();

    int novaQuantidade;
    do{
      cout << "Nova quantidade : ";
      cin >> novaQuantidade;
    }while(!encontrado->setQuantidade(novaQuantidade));

    cout << endl << "===== Produtos (atualizado) =====" << endl;
    estoque.listar();
  }

  return 0;
}
