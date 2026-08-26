/*
24. Considere uma matriz estática de inteiros com dimensões 3 X 3. Leia os elementos
da matriz e implemente uma função que calcule a soma de todos os seus elementos
utilizando um ponteiro para inteiro para percorrer sequencialmente as posições de
memória da matriz. Utilize o cabeçalho int somaMatriz(int *p, int quantidade).
A chamada da função poderá ser realizada utilizando o endereço do primeiro elemento
da matriz. Não utilize índices dentro da função somaMatriz, somente aritmética
de ponteiros.
*/
#include <stdio.h>
#include <stdlib.h>

int somaMatriz(int *p, int quantidade){
  int n = 0,soma = 0;
  while(n<9){
    soma = soma + *ptr;
    n++;
    ptr++;
  }
}

void main(){
  int m[3][3];

  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
      printf("Preenchendo o elemento [%d][%d] \n",i+1,j+1);
      scanf("%d",&m[i][j]);
    }
  }

  int *ptr = m[0][0];
  int q = somaMatriz(ptr,9);

  printf("A soma é igual a %d",q);
}
