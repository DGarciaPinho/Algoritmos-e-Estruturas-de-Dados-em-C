/*
7. Implemente a função void classifica(int *valor). A função deverá substituir o
conteúdo da variável apontada por:
• 1, caso o valor original seja positivo;
• −1, caso seja negativo;
• 0, caso seja igual a zero.
O valor da variável, antes e após a alteração, deverá ser exibido pelo programa
principal.
*/
#include <stdio.h>

void classifica(int *valor){
  if(*valor>0){
    *valor = 1;
  }else if(*valor == 0){
    *valor = 0;
  }else{
    *valor = -1;
  }
}

void main(){
  int n;
  scanf("%d",&n);

  printf("%d",n);
}
