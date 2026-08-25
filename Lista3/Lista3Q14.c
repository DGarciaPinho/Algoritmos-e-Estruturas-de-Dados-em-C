/* 
14. Considere que um vetor utiliza o valor −1 para representar posições que não contêm
dados válidos. Faça um programa que leia esse vetor e crie um novo vetor contendo
somente os valores válidos, desconsiderando todas as posições que possuem o valor
−1. Os elementos válidos deverão aparecer no novo vetor na mesma ordem em que
estavam originalmente.
Exemplo:
Vetor original:
8 -1 3 -1 -1 7 5
Vetor compactado:
8 3 7 5
*/

#include <stdio.h>
#include <stdlib.h>

// verifica se um valor e valido (diferente de -1)
int valido(int x){
    return x != -1;
}

// copia o valor de uma posicao para outra (igual ao seu "push")
void push(int *a, int *b){
    *b = *a;
}

int main(){
    int n, j = 0;

    printf("Digite o numero de valores : \n");
    scanf("%d", &n);

    int *ptr = calloc(n, sizeof(int));
    for(int i = 0; i < n; ++i){
        printf("Escreva o numero[%d] (-1 para posicao invalida) \n", i+1);
        scanf("%d", &ptr[i]);
    }

    // percorre o vetor original e vai compactando os validos no inicio
    for(int i = 0; i < n; ++i){
        if(valido(ptr[i])){
            push(&ptr[i], &ptr[j]);
            j++;
        }
    }

    printf("Vetor compactado:\n");
    for(int i = 0; i < j; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
