/*4. Leia um vetor com 15 números inteiros e determine se existe uma posição na qual a
soma dos elementos localizados à esquerda seja igual à soma dos elementos local-
izados à direita. Caso exista, apresente a posição encontrada. Exemplo: No vetor 1
2 3 4 6, o índice 3 (o qual armazena o valor 4) é o ponto de equilíbrio porque a soma
dos valores à esquerda (1 + 2 + 3 = 6) é igual à soma dos elementos à direita. Nesse
caso, o próprio valor 6, armazenado no índice 4.*/

#include <stdio.h>

int main(){
  int v[15];
  int pos, achou = 0;

  for(int i = 0; i < 15; i++){
    scanf("%d", &v[i]);
  }

  for(int i = 0; i < 15; i++){
    int sleft = 0, sright = 0;

    for(int j = 0; j < i; j++){
      sleft += v[j];
    }
    for(int j = i + 1; j < 15; j++){
      sright += v[j];
    }

    if(sleft == sright){
      pos = i;
      achou = 1;
      break;
    }
  }

  if(achou){
    printf("Posição: %d", pos + 1);
  }else{
    //printf("Não existe ponto de equilíbrio");
  }

  return 0;
}
