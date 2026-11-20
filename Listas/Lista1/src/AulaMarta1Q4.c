/*. Desenvolva um programa que receba três notas e seus respectivos pesos. Calcule e
apresente a média ponderada do aluno.*/ 

#include <stdio.h>

void main(){
  float notas[3],pesos[3],notap[3],notaf;
  
  for(int i=0;i<3;i++)
  {
    printf("Nota %d e Peso %f ",i+1,i+1);
    scanf("%f",&notas[i]);
    scanf("%f",&pesos[i]);
    notap[i]=(nota[i]/10)*peso[i];
    notaf = notaf + notap[i];
  }

  printf("%f",notaf);

}
