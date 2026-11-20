// 7. Leia uma matriz 6 × 6 de números inteiros e calcule separadamente:
// a) a soma dos elementos localizados na borda da matriz;
// b) a soma dos elementos localizados no interior da matriz.

#include <stdio.h>

void main(){
    int matriz[6][6],somab=0,somai=0;

    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
           // printf("Digite o Valor [%d][%d] \n ",i+1,j+1);
            scanf("%d",&matriz[i][j]);
          }
      }

      for(int i=0;i<6;++i){
          for(int j=0;j<6;++j){
              if(j==0 || j==5 || i==0 || i==5){
                  somab = somab + matriz[i][j];
                }else{
                    somai = somai + matriz[i][j];
                  }
            }
        }
  //Demonstrando a Matriz 
  /*
  for(int i=0;i<6;++i){
    for(int j=0;j<6;++j){
      printf("%d",matriz[i][j]);
    }
    printf("\n ");
   }
  */

    printf("Soma dos elementos da borda: %d\n", somab);
    printf("Soma dos elementos do interior: %d",somai);
  }

