/*
Lista 8 - Struct -> Classes (versão C++ / POO)

7. (Lista encadeada de tarefas) Manter uma lista de tarefas pendentes, permitindo adicionar
tarefas ao final, consultar a listagem e remover a última tarefa.

(a) Classes:
      Tarefa: codigo (int) e descricao (até 50 caracteres);
      Celula: ponteiro tarefa (Tarefa*) e ponteiro proxima (Celula*);
      Lista:  ponteiro primeira (Celula*). Sem célula sentinela; vazia -> primeira == nullptr.
    Cada célula e sua tarefa são alocadas separadamente.
(b) Criação da lista: inicia com primeira = nullptr.
(c) Tarefa:  static Tarefa *ler();  (aloca, lê, retorna o endereço ou nullptr se falhar;
             descrição com espaços)   e   void imprimir() const;
(d) bool inserirFinal(Tarefa *tarefa);  aloca uma célula com a tarefa e insere no final.
    Retorna false se a alocação da célula falhar (a lista fica inalterada e a tarefa NÃO é
    liberada pela função).
(e) void listar() const;  imprime as tarefas na ordem de inserção, ou uma mensagem se vazia.
(f) Tarefa *removerFinal();  remove a última célula. Casos: lista vazia (retorna nullptr),
    uma única célula (primeira vira nullptr), várias células (penúltima->proxima = nullptr).
(g) void liberar();  libera todas as tarefas e células e coloca primeira = nullptr.
(h) Programa principal com o menu:
      1. Adicionar uma tarefa ao final;
      2. Listar as tarefas;
      3. Remover a última tarefa;
      4. Encerrar o programa.
    Opção inexistente -> mensagem de opção inválida. Na inserção: se ler() retornar nullptr,
    informe a falha; se a inserção falhar, libere a tarefa e informe. Na remoção, informe se
    removeu (imprimindo e desalocando a tarefa) ou se a lista estava vazia.
    Antes de encerrar, libere tudo.

Versão POO:
  - criarLista / inicializarLista  ->  CONSTRUTOR da Lista  (Lista lista; já nasce vazia)
  - liberarLista                   ->  método liberar() + DESTRUTOR ~Lista() que o chama.
                                       Mesmo se o programa esquecer, a memória é liberada.
  - Celula é um detalhe de implementação da Lista, então ela é uma classe ANINHADA PRIVADA:
    ninguém fora da Lista consegue criar ou mexer em células.
  - Sobre (f): o enunciado diz que removerFinal libera a tarefa, mas também que ela retorna a
    Tarefa* e o (h) pede para imprimir a removida e depois desalocar. Retornar um ponteiro já
    liberado seria erro (use-after-free), então removerFinal libera só a CÉLULA e devolve a
    tarefa; quem chama imprime e dá delete (igual à Q7_corrigido.c em C).
*/

#include <iostream>
#include <string>
#include <new>

using namespace std;

class Tarefa{
private:
  int codigo;
  string descricao;

public:
  Tarefa() : codigo(0), descricao(""){}

  // (c)
  static Tarefa *ler(){
    Tarefa *t = new (nothrow) Tarefa;
    if(t == nullptr){
      return nullptr;
    }

    cout << "Codigo : ";
    cin >> t->codigo;

    cout << "Descrição : ";
    cin >> ws;
    getline(cin,t->descricao);
    if(t->descricao.size() > 50){
      t->descricao = t->descricao.substr(0,50);
    }

    return t;
  }

  void imprimir() const{
    cout << "Codigo : [" << codigo << "] | Descrição : [" << descricao << "]" << endl;
  }
};

class Lista{
private:
  class Celula{
  public:
    Tarefa *tarefa;
    Celula *proxima;

    Celula(Tarefa *tarefa) : tarefa(tarefa), proxima(nullptr){}
  };

  Celula *primeira;

public:
  // (b)
  Lista() : primeira(nullptr){}

  Lista(const Lista &) = delete;
  Lista &operator=(const Lista &) = delete;

  ~Lista(){
    liberar();
  }

  bool vazia() const{
    return primeira == nullptr;
  }

  // (d)
  bool inserirFinal(Tarefa *tarefa){
    Celula *nova = new (nothrow) Celula(tarefa);
    if(nova == nullptr){
      return false;
    }

    if(primeira == nullptr){
      primeira = nova;
    }else{
      Celula *atual = primeira;
      while(atual->proxima != nullptr){
        atual = atual->proxima;
      }
      atual->proxima = nova;
    }
    return true;
  }

  // (e)
  void listar() const{
    if(vazia()){
      cout << "A lista está vazia." << endl;
      return;
    }
    for(Celula *atual = primeira; atual != nullptr; atual = atual->proxima){
      atual->tarefa->imprimir();
    }
  }

  // (f)
  Tarefa *removerFinal(){
    if(primeira == nullptr){
      return nullptr;
    }

    Tarefa *tarefa;

    if(primeira->proxima == nullptr){
      tarefa = primeira->tarefa;
      delete primeira;
      primeira = nullptr;
      return tarefa;
    }

    Celula *penultima = primeira;
    while(penultima->proxima->proxima != nullptr){
      penultima = penultima->proxima;
    }

    tarefa = penultima->proxima->tarefa;
    delete penultima->proxima;
    penultima->proxima = nullptr;

    return tarefa;
  }

  // (g)
  void liberar(){
    Celula *atual = primeira;
    while(atual != nullptr){
      Celula *proxima = atual->proxima;
      delete atual->tarefa;
      delete atual;
      atual = proxima;
    }
    primeira = nullptr;
  }
};

int main(){
  Lista lista;   // (h) o construtor faz o papel do inicializarLista
  int op;

  do{
    cout << endl << "1. Adicionar uma tarefa ao final" << endl;
    cout << "2. Listar as tarefas" << endl;
    cout << "3. Remover a última tarefa" << endl;
    cout << "4. Encerrar o programa" << endl;
    cout << "Opção : ";
    cin >> op;

    if(op == 1){
      Tarefa *tarefa = Tarefa::ler();
      if(tarefa == nullptr){
        cout << "Falha ao criar a tarefa." << endl;
      }else if(!lista.inserirFinal(tarefa)){
        delete tarefa;
        cout << "A tarefa não foi adicionada." << endl;
      }else{
        cout << "Tarefa adicionada." << endl;
      }
    }else if(op == 2){
      lista.listar();
    }else if(op == 3){
      Tarefa *removida = lista.removerFinal();
      if(removida == nullptr){
        cout << "A lista estava vazia." << endl;
      }else{
        cout << "Tarefa removida : ";
        removida->imprimir();
        delete removida;
      }
    }else if(op != 4){
      cout << "Opção inválida." << endl;
    }
  }while(op != 4);

  lista.liberar();   // pedido pelo enunciado (o destrutor também faria)

  return 0;
}
