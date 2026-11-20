#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  int numero;
  char titular[50];
  float saldo;
}Conta;

void lerConta(Conta *conta){
  printf("===\n");
  printf("Conta  \n");
  printf("===\n");
  printf("Titular : \n");
  fgets(conta->titular,50, stdin);

  int i=0;

  while (conta->titular[i] != '\0') {
      if (conta->titular[i] == '\n') {
          conta->titular[i] = '\0';
          break;
      }

      i++;
  }

  printf("Numero : \n");
  scanf("%d",&conta->numero);
  printf("Saldo : \n");
  scanf("%f",&conta->saldo);
  getchar();

}

void imprimirConta(const Conta *conta){
  printf("Titular : [%s] \n",conta->titular);
  printf("Numero : [%d] \n",conta->numero);
  printf("Saldo : [%f] \n",conta->saldo);
}

Conta *buscarConta(Conta *contas,int n, int numero){
  
  Conta *search;

  int i=0;
  while(i<n){
    if(contas->numero == numero){
      search = contas;
      return search;
    }
    i++;
  }
}

void depositar(Conta *conta, float valor){
  conta->saldo += valor;
}

void main(){
  int n;
  printf("Digite o numero de contas : \n ");
  scanf("%d",&n);
  getchar();

  Conta *contas = calloc(n,sizeof(Conta)); 

  for(int i=0;i<n;++i){
    lerConta(&contas[i]);
  }

  int s = 1,c;

  while(s!=0){
    printf("============================\n");
    printf("Digite um numero de conta : \n");
    printf("============================\n");

    scanf("%d",&c);

    Conta *buscada = buscarConta(contas,n,c);

    imprimirConta(buscada);

    printf("============================\n");
    printf("Digite (1) para escolher outra conta\n");
    printf("Digite (2) para ver a conta \n");
    printf("Digite (3) para fazer um deposito \n");
    printf("Digite (0) para fechar o programa \n");
    printf("============================\n");

    scanf("%d",&s);

    if(s==2){
      imprimirConta(buscada);
    }
    if(s==3){
      float valor;
      printf("Digite a quantidade : \n");
      scanf("%f",&valor);
      depositar(buscada,valor);
      imprimirConta(buscada);
    }
  }


}
