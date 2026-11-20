/*
11. Implemente a função void estatisticas(int a, int b, int c, int *maior, int
*menor, float *media). A função deverá determinar o maior valor, o menor valor
e a média aritmética dos três números recebidos. Os três resultados deverão ser
retornados por meio dos parâmetros ponteiros.
*/ 

#include <stdio.h>

void estatisticas(int a, int b, int c, int *maior, int *menor, float *media){
  *media = (a + b + c)/3;
  if((a>b)&&(a>c)){
    *maior = a;
  }else if((b>a)&&(b>c)){
    *maior = b;
  }else{
    *maior = c;
  }

  if((a<b)&&(a<c)){
    *menor = a;
  }else if((b<a)&&(b<c)){
    *menor = b;
  }else{
    *menor = c;
  }
}

void main(){
  int v1,v2,v3;
  printf("Digite v1,v2,v3 :\n");
  scanf("%d %d %d",&v1,&v2,&v3);

  int mr = v1, mg = v1;
  float md = 0;

  estatisticas(v1,v2,v3,&mg,&mr,&md);

  printf("Media : %f, Maior : %d, Menor : %d",md,mg,mr);
}
