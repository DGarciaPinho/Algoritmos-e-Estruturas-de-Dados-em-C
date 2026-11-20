/*
 * Trabalho Prático – Classe e Herança
 * Algoritmos e Estruturas de Dados I – PUC Minas
 *
 * Jogo simples de combate por turnos entre um Mago e um Guerreiro.
 *
 * Entrada : valor(es) do ataque-base lido(s) da entrada padrão.
 *           - Se houver dois valores, o primeiro é o ataque do Mago e o
 *             segundo o do Guerreiro.
 *           - Se houver apenas um valor, ele é usado para os dois.
 * Processamento: rodadas de combate enquanto ambos estiverem vivos
 *           (Mago ataca primeiro, Guerreiro contra-ataca).
 * Saída   : vida máxima de cada personagem, resultado de cada rodada
 *           e o vencedor da disputa.
 */

#include <iostream>
#include <string>
#include <random>

using namespace std;

/* ===================================================================
 * Classe-base Personagem
 * =================================================================== */
class Personagem {
protected:
    string nome;     // nome do personagem
    int ataque;      // ataque-base
    int vida;        // vida atual
    int vidaMaxima;  // vida máxima

public:
    // Construtor: recebe nome, ataque-base e vida máxima (nessa ordem).
    // A vida atual começa igual à vida máxima.
    Personagem(string nome, int ataque, int vidaMaxima) {
        this->nome = nome;
        this->ataque = ataque;
        this->vidaMaxima = vidaMaxima;
        this->vida = vidaMaxima;
    }

    // Destrutor virtual: boa prática quando a classe tem métodos virtuais
    virtual ~Personagem() {}

    // Retorna o nome do personagem
    string getNome() { return nome; }

    // Retorna a vida atual
    int getVida() { return vida; }

    // Retorna a vida máxima
    int getVidaMaxima() { return vidaMaxima; }

    // Retorna o ataque-base
    int getAtaque() { return ataque; }

    // Retorna true se a vida atual for maior que zero
    bool estaVivo() { return vida > 0; }

    // virtual: permite que as classes filhas (Mago) sobrescrevam com override.
    // Se estiver vivo, retorna o ataque-base; se estiver derrotado, retorna 0.
    // Não altera o adversário (quem aplica o dano é o main).
    virtual int atacar() {
        if (estaVivo()) {
            return ataque;
        }
        return 0;
    }

    // Reduz a vida (sem deixá-la negativa) e retorna a vida efetivamente
    // perdida. Dano zero ou negativo não altera a vida e retorna 0.
    int receberDano(int dano) {
        if (dano <= 0) {
            return 0;
        }
        int perdida = (dano > vida) ? vida : dano; // não perde mais do que tem
        vida -= perdida;
        return perdida;
    }

    // Se estiver vivo e pontos > 0, recupera vida sem ultrapassar a vida
    // máxima e retorna a quantidade efetivamente recuperada; senão retorna 0.
    int recuperarVida(int pontos) {
        if (!estaVivo() || pontos <= 0) {
            return 0;
        }
        int falta = vidaMaxima - vida;                     // quanto falta para encher
        int recuperada = (pontos > falta) ? falta : pontos;
        vida += recuperada;
        return recuperada;
    }
};

/* ===================================================================
 * Classe Guerreiro (herança pública de Personagem)
 * Vida máxima fixa em 150. Usa todos os métodos herdados.
 * =================================================================== */
class Guerreiro : public Personagem {
public:
    // Chama o construtor da classe-base com vida máxima 150
    Guerreiro(string nome, int ataque) : Personagem(nome, ataque, 150) {}
};

/* ===================================================================
 * Classe Mago (herança pública de Personagem)
 * Vida máxima fixa em 90. Ataca com efeitos especiais sorteados:
 *   0 - Ataque comum   : dano = ataque-base
 *   1 - Ataque crítico : dano = 2 * ataque-base
 *   2 - Drenagem de vida: dano = ataque-base e recupera até 10 de vida
 *   3 - Magia falhou   : dano = 0
 * =================================================================== */
class Mago : public Personagem {
private:
    int ultimoEfeito; // código do último efeito sorteado (-1 antes do 1º ataque)
    int ultimoDano;   // dano calculado no último ataque (0 antes do 1º ataque)

public:
    // Chama o construtor da classe-base com vida máxima 90
    Mago(string nome, int ataque) : Personagem(nome, ataque, 90) {
        ultimoEfeito = -1;
        ultimoDano = 0;
    }

    // Ataque do Mago (redefine o atacar() da classe-base).
    // Se estiver derrotado, retorna -1 sem modificar os atributos.
    int atacar() override {
        // Gerador local estático com semente fixa 42: é criado uma única vez
        // e mantém a sequência entre as chamadas.
        static mt19937 gerador(42);

        if (!estaVivo()) {
            return -1;
        }

        int efeito = gerador() % 4; // sorteia o efeito de 0 a 3
        int dano = 0;

        switch (efeito) {
            case 0: // ataque comum
                dano = ataque;
                break;
            case 1: // ataque crítico
                dano = 2 * ataque;
                break;
            case 2: // drenagem de vida
                dano = ataque;
                recuperarVida(10); // reutiliza o método da classe-base
                break;
            case 3: // magia falhou
                dano = 0;
                break;
        }

        ultimoEfeito = efeito;
        ultimoDano = dano;
        return dano;
    }

    // Retorna o código do último efeito sorteado
    int getUltimoEfeito() { return ultimoEfeito; }

    // Retorna o dano calculado no último ataque
    int getUltimoDano() { return ultimoDano; }
};

/* ===================================================================
 * Programa principal
 * =================================================================== */
int main() {
    int ataqueMago, ataqueGuerreiro;

    // Lê o ataque-base; se houver um segundo valor, ele é o do Guerreiro
    cin >> ataqueMago;
    if (!(cin >> ataqueGuerreiro)) {
        ataqueGuerreiro = ataqueMago;
    }

    Mago mago("Gandolf", ataqueMago);
    Guerreiro guerreiro("Kratos", ataqueGuerreiro);

    // Mostra a vida máxima de cada personagem
    cout << "Vida Máxima do Mago " << mago.getNome() << ": "
         << mago.getVidaMaxima() << endl;
    cout << "Vida Máxima do Guerreiro " << guerreiro.getNome() << ": "
         << guerreiro.getVidaMaxima() << endl;
    cout << endl;

    int i =0;

    // Rodadas enquanto ambos estiverem vivos
    while (mago.estaVivo() && guerreiro.estaVivo()) {
      i++;
      if(i%2!=0){
        // 1. O Mago ataca primeiro
        guerreiro.receberDano(mago.atacar());
      
        // 2. Mostra o efeito, o dano e a vida dos dois
        cout << "O mago atacou com o efeito " << mago.getUltimoEfeito()
             << " com dano igual a " << mago.getUltimoDano() << "." << endl;
        cout << "Vida restante do Mago: " << mago.getVida() << endl;
        cout << "Vida restante do Guerreiro: " << guerreiro.getVida() << endl;
      }else{
        // 3. O Guerreiro contra-ataca 
        mago.receberDano(guerreiro.atacar());
        cout << "Vida restante do Mago: " << mago.getVida() << endl;
        cout << "Vida restante do Guerreiro: " << guerreiro.getVida() << endl;
      }
    }

    // Informa o vencedor
    if (mago.estaVivo()) {
        cout << "O Mago " << mago.getNome() << " venceu a disputa!" << endl;
    } else {
        cout << "O Guerreiro " << guerreiro.getNome() << " venceu a disputa!" << endl;
    }

    return 0;
}
