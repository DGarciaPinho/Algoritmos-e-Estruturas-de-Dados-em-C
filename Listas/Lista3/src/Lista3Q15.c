/* 15. Faça um programa que leia um vetor de números inteiros e um valor inteiro N. Em
seguida, o vetor deverá ser rotacionado N posições para a direita, sem a utilização de
um vetor auxiliar. Os elementos que ultrapassarem o final do vetor deverão reaparecer
no início.
Exemplo:
Vetor original:
1 2 3 4 5 6
N = 2
Vetor resultante:
5 6 1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

// troca dois elementos de posicao (parecido com o seu "push", so que troca os dois)
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// inverte o vetor (ou um pedaco dele) entre as posicoes ini e fim
void inverte(int *v, int ini, int fim){
    while(ini < fim){
        swap(&v[ini], &v[fim]);
        ini++;
        fim--;
    }
}

// rotaciona n posicoes para a direita usando o metodo das 3 inversoes
void rotaciona(int *v, int tam, int n){
    n = n % tam; // caso N seja maior que o tamanho do vetor
    if(n == 0) return;

    inverte(v, 0, tam - 1);          // inverte o vetor inteiro
    inverte(v, 0, n - 1);             // inverte os primeiros n elementos
    inverte(v, n, tam - 1);           // inverte o restante
}

int main(){
    int tam, n;

    printf("Digite o numero de valores : \n");
    scanf("%d", &tam);

    int *ptr = calloc(tam, sizeof(int));
    for(int i = 0; i < tam; ++i){
        printf("Escreva o numero[%d] \n", i+1);
        scanf("%d", &ptr[i]);
    }

    printf("Digite o valor de N (quantas posicoes rotacionar) : \n");
    scanf("%d", &n);

    rotaciona(ptr, tam, n);

    for(int i = 0; i < tam; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
