/*Desenvolva uma calculadora simples. O programa deverá receber dois números e um
operador (+, -, * ou /), realizar a operação escolhida e apresentar o resultado. Na
divisão, verifique se o segundo número é diferente de zero.*/

#include <stdio.h>

void main(){
  char a = 'c',ope;
  int n1,n2;

  while(a=='c'){
    printf("========== \n");
    printf("Operação \n");
    printf("+ Soma \n");
    printf("- Subtração \n");
    printf("* multiplicação \n");
    printf("/ Divisão \n");
    printf("========== \n");

    scanf("%c",&ope);
    printf("Escolha os dois numeros \n");
    scanf("%d %d",&n1,&n2);

    if(ope=='+'){
      printf("Resultado da soma %d \n",n1 +n2);
    }else if(ope=='-'){
      printf("Resultado da subtração %d \n",n1-n2);
    }else if(ope=='/'){
      printf("Resultado da divisão %d \n",n1/n2);
    }else if(ope=='*'){
      printf("Resultado da multiplicação %d \n",n1*n2);
    }else{
      printf("Escolha de operação invalida \n");
    }

    printf("Quer continuar? \n");
    printf("c = continuar \n");
    printf("s = sair\n");
    scanf(" %c",&a);
  }
}
