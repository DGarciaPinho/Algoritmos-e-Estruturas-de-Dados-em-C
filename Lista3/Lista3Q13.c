/* 
13. Faça um programa que leia dois vetores de números inteiros e produza dois novos ve-
tores. Um deles deverá representar a união dos vetores originais, contendo todos os
valores existentes em pelo menos um dos dois vetores, sem repetições. O outro dev-
erá representar a interseção, contendo somente os valores que aparecem em ambos
os vetores.
Exemplo:
Vetor A:
1 3 5 7
Vetor B:
3 6 7 9
Uniao:
1 3 5 7 6 9
Intersecao:
3 7
*/ 
#include <stdio.h>
#include <stdlib.h>

// verifica se um valor ja existe dentro de um vetor (evita repeticoes na uniao)
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

    // uniao pode ter no maximo na + nb elementos
    int *uniao = calloc(na + nb, sizeof(int));
    int u = 0;

    // primeiro joga todo o vetor A na uniao (A nao tem repeticoes internas assumidas)
    for(int i = 0; i < na; ++i){
        uniao[u] = a[i];
        u++;
    }

    // depois joga os elementos de B que ainda nao estao na uniao
    for(int i = 0; i < nb; ++i){
        if(!existeEm(uniao, u, b[i])){
            uniao[u] = b[i];
            u++;
        }
    }

    // intersecao pode ter no maximo o menor dos dois tamanhos
    int menor = (na < nb) ? na : nb;
    int *intersecao = calloc(menor, sizeof(int));
    int inter = 0;

    // percorre A e verifica quais elementos tambem estao em B
    for(int i = 0; i < na; ++i){
        if(existeEm(b, nb, a[i]) && !existeEm(intersecao, inter, a[i])){
            intersecao[inter] = a[i];
