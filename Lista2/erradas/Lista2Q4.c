/*4. Leia um vetor com 15 números inteiros e determine se existe uma posição na qual a
soma dos elementos localizados à esquerda seja igual à soma dos elementos local-
izados à direita. Caso exista, apresente a posição encontrada. Exemplo: No vetor 1
2 3 4 6, o índice 3 (o qual armazena o valor 4) é o ponto de equilíbrio porque a soma
dos valores à esquerda (1 + 2 + 3 = 6) é igual à soma dos elementos à direita. Nesse
caso, o próprio valor 6, armazenado no índice 4.*/ 

#include <stdio.h>

void main(){
  int v[15],sright=0,sleft=0,x,ver=0;

  // Lendo os 15 valores 
  for(int i=0;i<15;++i){
    printf("Digite o %d valor",i+1);
    scanf("%d",&v[i]);
    sright = sright + v[i];
  }
  printf("Valores Recebidos, analisando... ");

  for(int i=0;i<15;++i){
    sright = sright - v[i];
    if(i!=0){
        sleft = sleft + v[i-1];
      }

    // Verificando se sright(soma dos valores a direita do indice) é igual
    // ao sleft(soma dos valores a esquerda do indice)
    if(sleft == sright){
        x = i; // x é o valor do indice que vai ser apresentado como equilíbrio
        ver = 1;
      }
    }

    if(ver==0){
        printf("Não existe ponto de equilíbrio");
      }else{
          printf("O ponto de equilíbrio é o indice %d (O %d valor inserido) ",x,x+1);
        }
}
