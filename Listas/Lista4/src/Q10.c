/*
10. Implemente a função void divisao(int dividendo, int divisor, int *quociente,
int *resto). A função deverá calcular simultaneamente o quociente e o resto de uma
divisão inteira e retornar os dois resultados por meio dos parâmetros ponteiros. Con-
sidere que o divisor deve ser diferente de zero.
*/
#include <stdio.h>

void divisao(int dividendo, int divisor, int *quociente,int *resto){
  *resto = dividendo % divisor;
  *quociente = dividendo / divisor;
}

void main(){
  int n1,n2;
  printf("Digite o valor do dividendo e do divisor : \n");
  scanf("%d %d",&n1,&n2);

  int r,q;
  divisao(n1,n2,&q,&r);

  printf("Quociente : %d, Resto : %d",q,r);
}
