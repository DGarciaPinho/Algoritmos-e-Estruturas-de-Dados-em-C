/*3. Leia 15 números inteiros e reorganize o vetor de forma que todos os valores iguais a
zero sejam deslocados para o final, mantendo a ordem relativa dos demais elementos.
Exemplo: 3 0 7 0 2 5 0 → 3 7 2 5 0 0 0*/ 

#include <stdio.h>

int main(){
    int v[15], m[15];
    int left = 0; // próxima posição livre em m para valores não-zero

    for(int i = 0; i < 15; ++i){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < 15; ++i){
        if(v[i] != 0){
            m[left] = v[i];
            left++;
        }
    }

    // preenche o restante com zeros
    for(int i = left; i < 15; ++i){
        m[i] = 0;
    }

    for(int i = 0; i < 15; i++){
        printf("indice %d | Valor : %d \n", i, m[i]);
    }

    return 0;
}
