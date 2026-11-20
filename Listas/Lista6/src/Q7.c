/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

7. Implemente a função:
char* unirStrings(const char *s1, const char *s2);
A função deverá criar uma string alocada dinamicamente formada pelos caracteres da string s1 seguidos dos
caracteres da string s2 e retornar o ponteiro para a string criada. Desenvolva um programa para ler duas strings,
chamar a função para unir as strings e imprimir o resultado.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* unirStrings(const char *s1, const char *s2){
  char *str = calloc(1,sizeof(char));
  int i=0,j=0;

  while((s1[i]!='\n')&&(s1[i]!='\0')){
    if(i==0){
      str[0] = s1[0];
    }else{
      realloc(str,(1+i) * sizeof(char));
      str[i]= s1[i];
    }
    i++;
  }

  while((s2[j]!='\0')&&(s2[j]!='\n')){
    realloc(str,(1+i) * sizeof(char));
    str[i]=s2[j];
    i++;
    j++;
  }

  realloc(str,(1+i) * sizeof(char));
  str[i]='\0';

  return str;
}

void main(){
  int n;

  printf("=====================\n");
  printf("Digite o tamanho :\n");
  printf("=====================\n");

  scanf("%d",&n);
  getchar();

  char *str1 = calloc(n+1,sizeof(char));
  char *str2 = calloc(n+1,sizeof(char));

  printf("=====================\n");
  printf("Digite a String1 :\n");
  printf("=====================\n");

  
  fgets(str1,n+1,stdin);
  if(str1[n+1]=='\n'){
    str1[n+1] = '\0';
  }
  //scanf("%[^\n]",str1);

  printf("=====================\n");
  printf("Digite a String2 :\n");
  printf("=====================\n");
  
  
  fgets(str2,n+1,stdin);
  if(str2[n+1]=='\n'){
    str2[n+1] = '\0';
  }

  char *res = unirStrings(str1,str2);

  printf("A nova string unida é : [%s]",res);

}

