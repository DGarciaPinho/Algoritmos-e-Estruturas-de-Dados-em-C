#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n)
{
  if (n > -10 && n < 10) {
    return n < 0 ? -n : n;
  }

  int algarismo = n % 10;

  if (algarismo < 0) {
    algarismo = -algarismo;
  }

  return algarismo + soma_digitos(n / 10);
}

void main(){
  int z;

  printf("Digite o valor : \n");

  scanf("%d",&z);

  int soma = soma_digitos(z);

  printf("[%d]",soma);
}
