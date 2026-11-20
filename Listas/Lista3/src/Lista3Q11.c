/* 
11. Faça um programa que leia dois vetores de números inteiros e construa um terceiro
vetor contendo todos os valores presentes nos dois vetores. Caso um mesmo valor
apareça mais de uma vez, seja dentro de um mesmo vetor ou nos dois vetores, ele
deverá aparecer apenas uma vez no vetor resultante.
Exemplo:
Vetor A:
1 2 3 4
Vetor B:
3 4 5 6
Vetor resultante:
1 2 3 4 5 6
*/
#include <stdio.h>
#include <stdlib.h>

// verifica se um valor ja existe dentro de um vetor (evita repeticoes)
int existeEm(int *v, int tam, int valor){
    for(int i = 0; i < tam; ++i){
        if(v[i] == valor){
            return 1;
        }
    }
    return 0;
}

int main(){
    int na, nb;

    printf("Digite o numero de valores do vetor A : \n");
    scanf("%d", &na);
    int *a = calloc(na, sizeof(int));
    for(int i = 0; i < na; ++i){
        printf("Escreva o numero[%d] do vetor A \n", i+1);
        scanf("%d", &a[i]);
    }

    printf("Digite o numero de valores do vetor B : \n");
    scanf("%d", &nb);
    int *b = calloc(nb, sizeof(int));
    for(int i = 0; i < nb; ++i){
        printf("Escreva o numero[%d] do vetor B \n", i+1);
        scanf("%d", &b[i]);
    }

    // resultado pode ter no maximo na + nb elementos
    int *resultado = calloc(na + nb, sizeof(int));
    int r = 0;

    // adiciona os valores de A, ignorando repeticoes dentro do proprio A
    for(int i = 0; i < na; ++i){
        if(!existeEm(resultado, r, a[i])){
            resultado[r] = a[i];
            r++;
        }
    }

    // adiciona os valores de B, ignorando os que ja estao no resultado
    for(int i = 0; i < nb; ++i){
        if(!existeEm(resultado, r, b[i])){
            resultado[r] = b[i];
            r++;
        }
    }

    printf("Vetor resultante:\n");
    for(int i = 0; i < r; ++i){
        printf("%d ", resultado[i]);
    }
    printf("\n");

    free(a);
    free(b);
    free(resultado);
    return 0;
}
