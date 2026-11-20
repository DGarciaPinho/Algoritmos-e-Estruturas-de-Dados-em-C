/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

10. Implemente a função:
void contarCaracteres(const char *str, int *vogais, int *consoantes, int *algarismos);
A função deverá percorrer a string e determinar a quantidade de:
 vogais;
 consoantes;
 algarismos.
Os resultados deverão ser devolvidos por meio dos parâmetros vogais, consoantes e algarismos. Letras
maiúsculas e minúsculas deverão ser consideradas. Caracteres que não sejam letras nem algarismos deverão ser
desconsiderados. Considere como vogais apenas as letras não acentuadas a, e, i, o e u, nas formas maiúscula e
minúscula. Desenvolva um programa para ler uma string, chamar a função e imprimir as três quantidades
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void contarCaracteres(const char *str, int *vogais, int *consoantes, int *algarismos){
  int i=0;

  while(str[i]!='\0' && str[i]!='\n'){
    
    if(str[i]=='\0'){
      break;
    }else if(str[i]==' '){
      i++;
      continue;
    }

    if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u')||(str[i]=='A')||(str[i]=='E')||(str[i]=='I')||(str[i]=='U')||(str[i]=='O')){
      *vogais = *vogais + 1;
    }else if((str[i]=='1')||(str[i]=='2')||(str[i]=='3')||(str[i]=='4')||(str[i]=='5')||(str[i]=='6')||(str[i]=='7')||(str[i]=='8')||(str[i]=='9')||(str[i]=='0')){
      *algarismos = *algarismos + 1; 
    }else{
      *consoantes = *consoantes + 1;
    }
    i++;
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

  int v=0,c=0,a=0;

  contarCaracteres(str1,&v,&c,&a);

  printf("=====================\n");
  printf("Numeros de Vogais : [%d]\n",v);
  printf("Numeros de Consoantes : [%d]\n",c);
  printf("Numeros de Algarismos : [%d]\n",a);
  printf("=====================\n");

}
