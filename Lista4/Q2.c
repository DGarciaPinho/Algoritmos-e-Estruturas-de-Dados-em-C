/* 
2. Escreva um programa que leia um número inteiro e armazene seu endereço em um
ponteiro. Utilizando apenas o ponteiro, altere o valor da variável para o dobro de seu
valor original. Exiba o valor antes e depois da alteração.
*/
#include <stdio.h>

void main(){
  int n;
  printf("Digite o valor de n: \n");
  scanf("%d",&n);

  int *ptr = &n;

  *ptr = 2 * *ptr;

  printf("O dobro é igual a : %d \n", *ptr);
}
