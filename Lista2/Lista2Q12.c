/* 
 12. Leia uma matriz 4 × 4 e apresente seus elementos seguindo um percurso em espiral,
começando pelo canto superior esquerdo. Por exemplo, para uma matriz 4 × 4, o
percurso deverá seguir aproximadamente a ordem:
→ → → ↓ ↓ ↓ ← ← ← ↑ ↑ → → ↓ ←
Todos os elementos da matriz deverão ser apresentados exatamente uma vez
*/ 

#include <stdio.h>

void main(){
  int matriz[4][4];

  // Loop para ler a matriz 
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      printf("Elemento [%d][%d]: \n ",i+1,j+1);
      scanf(" %d",&matriz[i][j]);
      printf("\n ");
      }
  }
  // Limites do percurso em espiral
    int linhaIni = 0, linhaFim = 3;
    int colIni = 0, colFim = 3;

    printf("\nPercurso em espiral:\n");

    while (linhaIni <= linhaFim && colIni <= colFim) {

        // 1. Percorre para a direita (linha superior)
        for (j = colIni; j <= colFim; j++)
            printf("%d ", matriz[linhaIni][j]);
        linhaIni++;

        // 2. Percorre para baixo (coluna direita)
        for (i = linhaIni; i <= linhaFim; i++)
            printf("%d ", matriz[i][colFim]);
        colFim--;

        // 3. Percorre para a esquerda (linha inferior)
        if (linhaIni <= linhaFim) {
            for (j = colFim; j >= colIni; j--)
                printf("%d ", matriz[linhaFim][j]);
            linhaFim--;
        }

        // 4. Percorre para cima (coluna esquerda)
        if (colIni <= colFim) {
            for (i = linhaFim; i >= linhaIni; i--)
                printf("%d ", matriz[i][colIni]);
            colIni++;
        }
    }

    printf("\n");

}
