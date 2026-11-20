/*
 * AULA 03 - Lendo arquivos de texto
 *
 * Funcoes de leitura:
 *   int   fgetc(FILE *arq);                          -> le UM caractere (retorna EOF no fim)
 *   char *fgets(char *buf, int tam, FILE *arq);      -> le uma LINHA (ate tam-1 chars, inclui o '\n')
 *                                                       retorna NULL no fim do arquivo
 *   int   fscanf(FILE *arq, const char *fmt, ...);   -> igual ao scanf, mas do arquivo
 *                                                       retorna quantos itens leu (ou EOF)
 *
 * EOF ("End Of File") e uma constante (normalmente -1) que indica o fim do arquivo.
 * Por isso o retorno de fgetc e int e NAO char!
 *
 * Este programa primeiro CRIA um arquivo de exemplo e depois o le de 3 formas.
 *
 * Compilar: gcc 03_ler_texto.c -o 03_ler_texto
 */

#include <stdio.h>
#include <string.h>

void criarArquivoExemplo() {
    FILE *arq = fopen("alunos.txt", "w");
    if (arq == NULL) return;
    fprintf(arq, "Ana 20 9.5\n");
    fprintf(arq, "Bruno 22 7.0\n");
    fprintf(arq, "Carla 19 8.3\n");
    fclose(arq);
}

int main() {
    criarArquivoExemplo();
    FILE *arq;

    // ---------- FORMA 1: caractere por caractere com fgetc ----------
    printf("=== Lendo com fgetc ===\n");
    arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        perror("Erro");
        return 1;
    }
    int c;          // int, para conseguir representar o EOF
    int linhas = 0;
    while ((c = fgetc(arq)) != EOF) {
        putchar(c);
        if (c == '\n') linhas++;
    }
    printf("Total de linhas: %d\n\n", linhas);
    fclose(arq);

    // ---------- FORMA 2: linha por linha com fgets ----------
    printf("=== Lendo com fgets ===\n");
    arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        perror("Erro");
        return 1;
    }
    char linha[100];
    int n = 1;
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        // fgets guarda o '\n' no final; esse truque remove ele:
        linha[strcspn(linha, "\n")] = '\0';
        printf("Linha %d: [%s]\n", n++, linha);
    }
    printf("\n");
    fclose(arq);

    // ---------- FORMA 3: leitura formatada com fscanf ----------
    printf("=== Lendo com fscanf ===\n");
    arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        perror("Erro");
        return 1;
    }
    char nome[50];
    int idade;
    float nota;
    // Continua enquanto fscanf conseguir ler os 3 campos
    while (fscanf(arq, "%49s %d %f", nome, &idade, &nota) == 3) {
        printf("Nome: %-6s Idade: %d  Nota: %.1f\n", nome, idade, nota);
    }
    fclose(arq);

    return 0;
}
