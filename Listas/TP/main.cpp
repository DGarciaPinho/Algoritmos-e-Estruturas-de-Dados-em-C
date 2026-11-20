#include <iostream>
#include <string>
#include <random>

using namespace std;

class Personagem{
  private : 
    string name;
    int aa; // auto attack
    int chp; // Current Health point
    int hp; // Health point
    
  public : 

    Personagem(string n, int av,int vhpv, int hpv) : name(n), aa(av), chp(vhpv), hp(hpv){}
    virtual ~Personagem() {}
    string getName(){
      return name;
    }
    int getHP(){
      return chp;
    }
    int getMAXHP(){
      return hp;
    }
    int getAA(){}
    bool isAlive(){
      if(chp>0){
        return true;
      }else{
        return false;
      }
    }

    int attack(){
      return aa;
    }
    int Damage(){
      return aa;
    }
    int Heal(){}
};

class Mago: public Personagem {
  private :
    int getLastEffect(){}
    int getLastDamage(){}

  public :
    Mago(string name,int attack){}
    int attack() override{}
};

class Guerreiro: public Personagem {
  public : 
    Guerreiro(string name,int attack){}
};

int main(){
  Mago mago("Gandolf", 90);
  Guerreiro guerreiro("Kratos",150);

  int i = 1;

  while(P1.chp > 0 || P2.chp > 0){
    
    if(i%2!=0){
      guerreiro.Damage(mago.attack());
      cout << "O mago atacou com o efeito " << mago.getLastEffect << " com dano igual a" << mago.getLastDamage << endl;
    }else{
      mago.Damage(guerreiro.attack());
      cout << "O guerreiro atacou com dano igual a" << guerreiro.aa << endl;
    }

    cout << "Vida Máxima do Mago Gandolf:" << mago.hp << endl;
    cout << "Vida Máxima do Guerreiro Kratos: "<< guerreiro.hp << endl;
    i++;
  }

  if(P1.chp < 1){
    cout <<"O mago perdeu" << endl;
  }else{
    cout <<"O guerreiro perdeu" << endl;
  }
  cout <<"O número de turnos foi : " << i << endl;
  return 0;
}
