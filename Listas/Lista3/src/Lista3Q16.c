/*
6. Faça um programa que receba um vetor de números inteiros que já esteja ordenado
em ordem crescente. O programa deverá eliminar as ocorrências repetidas de cada
valor, mantendo somente uma ocorrência de cada número. A operação deverá ser
realizada utilizando apenas o vetor original.
Exemplo:
Vetor original:
1 1 1 3 3 5 7 7 9
Vetor resultante:
1 3 5 7 9
*/

#include <stdio.h>
#include <stdlib.h>

void arrasto(int *b, int l, int lens){
   
    for(int i = l; i < lens - 1; ++i){
        b[i] = b[i+1];
    }
}

int main(){
    int n, m = 0;
    printf("Digite o numero de valores: \n");
    scanf("%d", &n);

    int *ptr = calloc(n, sizeof(int));
    for(int i = 0; i < n; ++i){
        printf("Escreva o numero[%d]\n", i+1);
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < n - m; ++i){
        int j = i + 1;
        while(j < n - m && ptr[i] == ptr[j]){
            arrasto(ptr, j, n - m);
            m++;
           
        }
    }

    n = n - m;
    for(int i = 0; i < n; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
