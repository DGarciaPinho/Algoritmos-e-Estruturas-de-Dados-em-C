/*
 * AULA 09 - Lendo e escrevendo arquivos CSV
 *
 * CSV (Comma-Separated Values) e um formato de texto onde cada linha e um
 * registro e os campos sao separados por virgula (ou ponto-e-virgula).
 * Pode ser aberto no Excel / LibreOffice / Google Sheets.
 *
 * Duas formas de separar os campos de uma linha:
 *   - fscanf/sscanf com %[^;]   -> "le tudo que NAO for ';'"
 *   - strtok(linha, ";")        -> quebra a string em pedacos
 *
 * Compilar: gcc 09_csv.c -o 09_csv
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    char cidade[50];
    int idade;
    float salario;
} Pessoa;

void criarCSV() {
    FILE *arq = fopen("pessoas.csv", "w");
    if (arq == NULL) return;
    fprintf(arq, "nome;cidade;idade;salario\n"); // cabecalho
    fprintf(arq, "Ana Souza;Belo Horizonte;28;4500.00\n");
    fprintf(arq, "Bruno Lima;Contagem;35;6200.50\n");
    fprintf(arq, "Carla Dias;Betim;22;3100.00\n");
    fprintf(arq, "Daniel Rocha;Belo Horizonte;41;8900.75\n");
    fclose(arq);
}

int main() {
    criarCSV();

    FILE *arq = fopen("pessoas.csv", "r");
    if (arq == NULL) {
        perror("Erro ao abrir pessoas.csv");
        return 1;
    }

    Pessoa pessoas[MAX];
    int qtd = 0;
    char linha[256];

    // Pula a linha de cabecalho
    fgets(linha, sizeof(linha), arq);

    // ---------- Lendo com sscanf + %[^;] ----------
    // sscanf funciona como fscanf, mas le de uma STRING em vez de um arquivo
    while (qtd < MAX && fgets(linha, sizeof(linha), arq) != NULL) {
        Pessoa p;
        int campos = sscanf(linha, "%49[^;];%49[^;];%d;%f",
                            p.nome, p.cidade, &p.idade, &p.salario);
        if (campos == 4) {
            pessoas[qtd++] = p;
        } else {
            printf("Linha invalida ignorada: %s", linha);
        }
    }
    fclose(arq);

    printf("%-15s %-16s %5s %10s\n", "NOME", "CIDADE", "IDADE", "SALARIO");
    for (int i = 0; i < qtd; i++) {
        printf("%-15s %-16s %5d %10.2f\n",
               pessoas[i].nome, pessoas[i].cidade, pessoas[i].idade, pessoas[i].salario);
    }

    // ---------- Mesma ideia, usando strtok ----------
    printf("\nSeparando a 1a linha de dados com strtok:\n");
    char exemplo[] = "Ana Souza;Belo Horizonte;28;4500.00";
    char *campo = strtok(exemplo, ";");
    int i = 0;
    while (campo != NULL) {
        printf("  campo %d: %s\n", i++, campo);
        campo = strtok(NULL, ";"); // NULL = continua de onde parou
    }

    // ---------- Gerando um novo CSV filtrado ----------
    FILE *saida = fopen("bh.csv", "w");
    if (saida == NULL) {
        perror("Erro ao criar bh.csv");
        return 1;
    }
    fprintf(saida, "nome;salario_com_aumento\n");
    for (int j = 0; j < qtd; j++) {
        if (strcmp(pessoas[j].cidade, "Belo Horizonte") == 0) {
            fprintf(saida, "%s;%.2f\n", pessoas[j].nome, pessoas[j].salario * 1.10f);
        }
    }
    fclose(saida);
    printf("\nArquivo 'bh.csv' gerado com quem mora em BH (salario +10%%).\n");

    return 0;
}
