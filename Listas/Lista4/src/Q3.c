/* 
3. Declare duas variáveis inteiras e dois ponteiros, cada um associado a uma das var-
iáveis. Leia os valores das duas variáveis e exiba qual delas possui o maior valor,
realizando a comparação por meio dos ponteiros.
*/ 

#include <stdio.h>

void main(){
  int a,b;
  int *ptr = &a;
  int *ptr2 = &b;

  printf("Defina o valor de a e b : \n ");
  scanf("%d %d", &a,&b);

  if(*ptr > *ptr2){
    printf("A é maior");
  }else if(*ptr2 > *ptr){
    printf("B é maior");
  }else{
    printf("Iguais");
  }
}
