/*
Lista 8 - Struct -> Classes (versão C++ / POO)

4. (Cadastro de produtos com ponteiros) Uma loja precisa cadastrar produtos e atualizar suas
quantidades em estoque. Cada produto deve ser alocado dinamicamente e manipulado por ponteiro.

(a) Classe Produto com: codigo (int), nome (até 50 caracteres), preco (real) e quantidade (int).
(b) Alocação, leitura e impressão
      static Produto *ler();          aloca um Produto, lê os dados e retorna o endereço
                                      (ou nullptr se a alocação falhar). Nome com espaços.
      void imprimir() const;          preço com duas casas decimais.
(c) Cadastro: leia n > 0 e guarde os ponteiros num arranjo de tamanho definido na execução.
    Se alguma alocação falhar, libere os produtos já criados e encerre.
(d) Listagem: imprima todos os produtos.
(e) Busca pelo código:  Produto *buscar(int codigo);  retorna o ponteiro ou nullptr. Códigos
    são distintos. No main, leia um código e mostre o produto ou "não encontrado".
(f) Atualização do estoque: se encontrado, leia uma nova quantidade não negativa, atualize
    pelo ponteiro retornado e liste novamente.
(g) Liberação da memória: libere cada produto antes de encerrar.

C -> C++:
  - malloc / free          ->  new / delete
  - malloc retorna NULL    ->  new lança exceção (std::bad_alloc). Para manter o "retorna NULL
                               se falhar" do enunciado, usa-se  new (nothrow) Produto;
  - VLA  Produto *v[n];    ->  VLA NÃO existe em C++ padrão. O substituto é vector<Produto*>.
  - Função "lerProduto()"  ->  método ESTÁTICO Produto::ler() (pertence à classe, não a um
                               objeto; funciona como uma "fábrica" de produtos).
  - Etapas (c), (d), (e), (g) viram métodos da classe Estoque. O destrutor do Estoque faz a
    etapa (g) sozinho: quando o objeto sai de escopo, os produtos são liberados (RAII).
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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

  // (b)
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
  vector<Produto*> produtos;

public:
  Estoque(){}

  // Como o Estoque é "dono" dos ponteiros, copiar o Estoque geraria delete duplo -> proibido
  Estoque(const Estoque &) = delete;
  Estoque &operator=(const Estoque &) = delete;

  // (g)
  ~Estoque(){
    for(Produto *p : produtos){
      delete p;
    }
  }

  // (c) Retorna false se alguma alocação falhar (os já criados são liberados pelo destrutor)
  bool cadastrar(int n){
    for(int i=0;i<n;i++){
      cout << "===== Produto " << i+1 << " =====" << endl;
      Produto *p = Produto::ler();
      if(p == nullptr){
        return false;
      }
      produtos.push_back(p);
    }
    return true;
  }

  // (d)
  void listar() const{
    for(const Produto *p : produtos){
      p->imprimir();
    }
  }

  // (e)
  Produto *buscar(int codigo){
    for(Produto *p : produtos){
      if(p->getCodigo() == codigo){
        return p;
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

  Estoque estoque;

  if(!estoque.cadastrar(n)){
    cout << "Erro de alocação. Encerrando." << endl;
    return 1;   // o destrutor do estoque libera o que já foi criado
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

    // (f)
    int novaQuantidade;
    do{
      cout << "Nova quantidade : ";
      cin >> novaQuantidade;
    }while(!encontrado->setQuantidade(novaQuantidade));

    cout << endl << "===== Produtos (atualizado) =====" << endl;
    estoque.listar();
  }

  return 0;   // (g) acontece aqui, no destrutor de estoque
}
