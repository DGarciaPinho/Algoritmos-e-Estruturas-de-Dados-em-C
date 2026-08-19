/*
6. Faça um programa que leia um vetor contendo uma quantidade par de elementos. Em
seguida, modifique o próprio vetor de modo que a primeira metade passe a ocupar o
lugar da segunda metade e a segunda metade passe a ocupar o lugar da primeira. A
ordem dos elementos dentro de cada metade deverá ser preservada e não deverá ser
utilizado um vetor auxiliar.
Exemplo:
Vetor original:
1 2 3 4 5 6
Vetor resultante:
4 5 6 1 2 3
*/ 

#include <stdio.h>
#include <stdlib.h>

//EMPURRAR A EM B  
void push(int *a,int *b){
  *b = *a;
}

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main(){
  int x;
}
