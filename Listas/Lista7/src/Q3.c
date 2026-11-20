/*
Algoritmos e Estruturas de Dados I
Lista de Exercícios – Recursividade

Parte 1 – Implementação de funções recursivas

Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<math.h> e <string.h>, a não ser que seja solicitado.

3. Implemente uma função recursiva para calcular o tamanho de uma string.
*/

#include <stdio.h>
#include <stdlib.h>

int sizeStr(char *str,int i){
  if(str[i]=='\0' || str[i]=='\n'){ // Aqui estou desconsiderando o \0 e o \n, o que novamente pode ser alterado 
    return 0; // Desconsiderando o \0, para mudar isso basta trocar o 0 por 1
  }else{
    return 1 + sizeStr(str,i+1);
  }
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str1 = malloc((n+1) * sizeof(char));

  printf("=====================\n");
  printf("Digite a String1 :\n");
  printf("=====================\n");

  fgets(str1,n+1,stdin);

  int size = sizeStr(str1,0);

  printf("Tamanho = [%d]",size);
}
