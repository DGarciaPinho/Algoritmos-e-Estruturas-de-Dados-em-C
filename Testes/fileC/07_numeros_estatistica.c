/*
 * AULA 07 - Exercicio pratico: ler numeros de um arquivo e processar
 *
 * 1) Gera 'numeros.txt' com N numeros aleatorios (um por linha)
 * 2) Le o arquivo, calcula soma, media, maior e menor
 * 3) Grava os pares em 'pares.txt' e os impares em 'impares.txt'
 * 4) Grava um relatorio em 'relatorio.txt'
 *
 * Mostra como trabalhar com VARIOS arquivos abertos ao mesmo tempo.
 *
 * Compilar: gcc 07_numeros_estatistica.c -o 07_numeros_estatistica
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main() {
    srand(time(NULL));

    // ---------- 1) Gerando o arquivo ----------
    FILE *arq = fopen("numeros.txt", "w");
    if (arq == NULL) {
        perror("Erro ao criar numeros.txt");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        fprintf(arq, "%d\n", rand() % 100 + 1); // numeros de 1 a 100
    }
    fclose(arq);

    // ---------- 2 e 3) Lendo e separando ----------
    FILE *entrada = fopen("numeros.txt", "r");
    FILE *pares   = fopen("pares.txt", "w");
    FILE *impares = fopen("impares.txt", "w");
    if (entrada == NULL || pares == NULL || impares == NULL) {
        perror("Erro ao abrir arquivos");
        // fecha os que conseguiram abrir
        if (entrada) fclose(entrada);
        if (pares) fclose(pares);
        if (impares) fclose(impares);
        return 1;
    }

    int num, qtd = 0, soma = 0, maior = 0, menor = 0;
    int qtdPares = 0, qtdImpares = 0;

    while (fscanf(entrada, "%d", &num) == 1) {
        if (qtd == 0) {
            maior = menor = num;
        } else {
            if (num > maior) maior = num;
            if (num < menor) menor = num;
        }
        soma += num;
        qtd++;

        if (num % 2 == 0) {
            fprintf(pares, "%d\n", num);
            qtdPares++;
        } else {
            fprintf(impares, "%d\n", num);
            qtdImpares++;
        }
    }
    fclose(entrada);
    fclose(pares);
    fclose(impares);

    if (qtd == 0) {
        printf("Arquivo vazio!\n");
        return 0;
    }

    // ---------- 4) Relatorio ----------
    FILE *rel = fopen("relatorio.txt", "w");
    if (rel == NULL) {
        perror("Erro ao criar relatorio.txt");
        return 1;
    }
    fprintf(rel, "===== RELATORIO =====\n");
    fprintf(rel, "Quantidade : %d\n", qtd);
    fprintf(rel, "Soma       : %d\n", soma);
    fprintf(rel, "Media      : %.2f\n", (float)soma / qtd);
    fprintf(rel, "Maior      : %d\n", maior);
    fprintf(rel, "Menor      : %d\n", menor);
    fprintf(rel, "Pares      : %d (ver pares.txt)\n", qtdPares);
    fprintf(rel, "Impares    : %d (ver impares.txt)\n", qtdImpares);
    fclose(rel);

    // Mostra o relatorio na tela lendo o proprio arquivo
    rel = fopen("relatorio.txt", "r");
    if (rel == NULL) return 1;
    char linha[100];
    while (fgets(linha, sizeof(linha), rel)) {
        printf("%s", linha);
    }
    fclose(rel);

    return 0;
}
