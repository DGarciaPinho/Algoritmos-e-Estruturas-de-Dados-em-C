/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

13. Uma string é considerada palíndroma quando pode ser lida da mesma forma da esquerda para a direita e da
direita para a esquerda. Implemente a função:
int isPalindromo(const char *str);
A função deverá retornar 1 quando a string for palíndroma e 0 caso contrário. Diferenças entre letras maiúsculas
e minúsculas deverão ser desconsideradas, mas os espaços e os demais caracteres deverão participar da
comparação. Por exemplo, “Arara” deverá ser considerada palíndroma. Desenvolva um programa para ler uma
string, chamar a função e informar o resultado.

*/ 

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int isPalindromo(const char *str){
  int i=0,j=0;
  while(str[i]!='\0'){
    i++;
  }
  i--;


  while(i>j){
    char temp = str[j];
    char temp2 = str[i];
    if ((temp >= 'A') && (temp <= 'Z')) {
      temp = temp + ('a' - 'A');
    }
    if ((temp2 >= 'A') && (temp2 <= 'Z')) {
      temp2 = temp2 + ('a' - 'A');
    }
    
    if(temp!=temp2){
      return 0;
    }
    i--;
    j++;   
  }
  return 1;
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

  int i = 0;

  while (str1[i] != '\0') {
      if (str1[i] == '\n') {
          str1[i] = '\0';
          break;
      }

      i++;
  }

  int res = isPalindromo(str1);

  printf("=====================\n");
  printf("Palindromo : [%d]\n",res);
  printf("=====================\n");

}
