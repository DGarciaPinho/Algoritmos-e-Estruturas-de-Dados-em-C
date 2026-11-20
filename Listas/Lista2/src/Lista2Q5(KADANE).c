/* 5. Leia um vetor com 20 números inteiros, que podem ser positivos ou negativos, e
determine qual trecho de elementos consecutivos possui a maior soma. Apresente:
a) a maior soma encontrada;
b) a posição inicial do trecho;
c) a posição final do trecho.
No exemplo, -2 3 5 -1 4 -10 7, o trecho de maior soma é 3 5 -1 4.
*/ 

// BASEADO NO ALGORITMO DE KADANE 

// O Algoritmo de Kadane

//O Algoritmo de Kadane é uma técnica de programação dinâmica usada para resolver o 
//problema da soma máxima de subvetor contíguo: dado um vetor de números 
//(que podem ser positivos ou negativos), encontrar o trecho de elementos consecutivos 
//cuja soma seja a maior possível.

//A ideia central é percorrer o vetor uma única vez, mantendo o controle da soma do
//trecho que está sendo construído até a posição atual. Em cada elemento, o algoritmo
//toma uma decisão simples: vale mais a pena continuar somando ao trecho anterior, 
//ou é melhor abandoná-lo e começar um novo trecho a partir daqui?

//Essa decisão é tomada comparando a soma acumulada até o momento com o valor do 
//elemento atual isoladamente. Se a soma acumulada já é negativa (ou seja, ela
//está "puxando para baixo" o resultado), não faz sentido carregá-la adiante — é melhor
//recomeçar o trecho no elemento atual. Caso contrário, o trecho continua crescendo.
 
//Enquanto isso acontece, o algoritmo guarda separadamente a melhor soma já encontrada
//e as posições de início e fim desse melhor trecho, atualizando-as sempre que a soma
//atual supera o recorde anterior.
 
//O grande mérito do algoritmo é a eficiência: ele resolve o problema em
//complexidade O(n), examinando cada elemento apenas uma vez. Isso o torna muito
//superior à abordagem ingênua de testar todos os pares possíveis de início e fim
//(que teria complexidade O(n²)).

//Por sua simplicidade e desempenho, o Algoritmo de Kadane é amplamente usado como
//exemplo didático de programação dinâmica e também aparece em aplicações práticas,
//como análise de séries temporais (por exemplo, encontrar o período de maior lucro
//acumulado em uma sequência de variações de preço).

#include <stdio.h>

#define N 20

int main() {
    int v[N];
    int i;

    // Leitura do vetor
   // printf("Digite os %d numeros inteiros:\n", N);
    for (i = 0; i < N; i++) {
        //printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Algoritmo de Kadane
    int somaAtual = v[0];
    int inicioAtual = 0;

    int somaMax = v[0];
    int inicioMax = 0;
    int fimMax = 0;

    for (i = 1; i < N; i++) {
        // Decide se continua o trecho ou comeca um novo em i
        if (somaAtual + v[i] >= v[i]) {
            somaAtual = somaAtual + v[i];
        } else {
            somaAtual = v[i];
            inicioAtual = i;
        }

        // Atualiza o melhor trecho, se necessario
        if (somaAtual > somaMax) {
            somaMax = somaAtual;
            inicioMax = inicioAtual;
            fimMax = i;
        }
    }

    // Resultados  
    printf("Maior soma encontrada: %d\n", somaMax);
    printf("Posição inicial: %d\n", inicioMax);
    printf("Posição final: %d\n", fimMax);

  /* SERVE APENAS PARA MOSTRAR O TRECHO 
    printf("Trecho: ");
    for (i = inicioMax; i <= fimMax; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
*/
    return 0;
}
