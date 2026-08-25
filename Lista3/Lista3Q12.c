/*12. Faça um programa que leia um vetor de números inteiros e crie um segundo vetor
contendo os mesmos elementos, porém armazenados na ordem inversa. O vetor
original não deverá ser alterado durante o processo. Ao final, apresente tanto o vetor
original quanto o novo vetor.
Exemplo:
Vetor original:
4 8 2 9 1
Novo vetor:
1 9 2 8 4
*/

#include <stdio.h>
#include <stdlib.h>

// copia o valor de uma posicao para outra (mesmo "push" de antes)
void push(int *a, int *b){
    *b = *a;
}

int main(){
    int n;

    printf("Digite o numero de valores : \n");
    scanf("%d", &n);

    int *ptr = calloc(n, sizeof(int));
    for(int i = 0; i < n; ++i){
        printf("Escreva o numero[%d] \n", i+1);
        scanf("%d", &ptr[i]);
    }

    int *inverso = calloc(n, sizeof(int));

    // para cada posicao i do original, o valor vai para a posicao (n-1-i) do novo
    for(int i = 0; i < n; ++i){
        push(&ptr[i], &inverso[n - 1 - i]);
    }

    printf("Vetor original:\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    printf("Novo vetor:\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", inverso[i]);
    }
    printf("\n");

    free(ptr);
    free(inverso);
    return 0;
}


