/*
 * AULA 06 - Movendo o "cursor" dentro do arquivo
 *
 * Todo arquivo aberto tem uma POSICAO atual (como o cursor de um editor).
 * Cada leitura/escrita avanca essa posicao.
 *
 *   int  fseek(FILE *arq, long deslocamento, int origem);  -> move o cursor
 *        origem: SEEK_SET (inicio), SEEK_CUR (posicao atual), SEEK_END (final)
 *   long ftell(FILE *arq);                                 -> diz a posicao atual (em bytes)
 *   void rewind(FILE *arq);                                -> volta para o inicio
 *   int  feof(FILE *arq);                                  -> != 0 se ja tentou ler alem do fim
 *
 * Com arquivos BINARIOS de structs, fseek permite ir direto ao registro N:
 *   fseek(arq, N * sizeof(Registro), SEEK_SET);   (acesso aleatorio!)
 *
 * Compilar: gcc 06_posicionamento.c -o 06_posicionamento
 */

#include <stdio.h>

typedef struct {
    int codigo;
    char produto[30];
    float preco;
} Item;

int main() {
    // ---------- Parte 1: fseek/ftell em arquivo texto ----------
    FILE *arq = fopen("alfabeto.txt", "w+"); // w+ = escrita e leitura
    if (arq == NULL) {
        perror("Erro");
        return 1;
    }
    fputs("ABCDEFGHIJKLMNOPQRSTUVWXYZ", arq);

    printf("Posicao apos escrever: %ld\n", ftell(arq));

    rewind(arq); // volta ao inicio para poder ler
    printf("Primeiro caractere: %c\n", fgetc(arq));

    fseek(arq, 10, SEEK_SET); // vai para o byte 10 (a partir do inicio)
    printf("Byte 10: %c\n", fgetc(arq)); // K

    fseek(arq, 3, SEEK_CUR); // anda mais 3 a partir de onde esta (estava no 11)
    printf("Byte 14: %c\n", fgetc(arq)); // O

    fseek(arq, -1, SEEK_END); // ultimo byte
    printf("Ultimo caractere: %c\n", fgetc(arq)); // Z

    // Truque classico: descobrir o tamanho do arquivo
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    printf("Tamanho do arquivo: %ld bytes\n\n", tamanho);
    fclose(arq);

    // ---------- Parte 2: acesso direto a registros em arquivo binario ----------
    Item estoque[5] = {
        {1, "Caneta", 2.50f},
        {2, "Caderno", 15.90f},
        {3, "Borracha", 1.20f},
        {4, "Mochila", 89.00f},
        {5, "Regua", 3.75f}
    };
    arq = fopen("estoque.bin", "wb");
    if (arq == NULL) return 1;
    fwrite(estoque, sizeof(Item), 5, arq);
    fclose(arq);

    arq = fopen("estoque.bin", "rb");
    if (arq == NULL) return 1;

    // Quantos registros existem? tamanho do arquivo / tamanho de um registro
    fseek(arq, 0, SEEK_END);
    long total = ftell(arq) / sizeof(Item);
    printf("O arquivo tem %ld registros.\n", total);

    // Lendo os registros de tras para frente usando fseek
    printf("Registros em ordem inversa:\n");
    Item it;
    for (long i = total - 1; i >= 0; i--) {
        fseek(arq, i * sizeof(Item), SEEK_SET);
        fread(&it, sizeof(Item), 1, arq);
        printf("  [%ld] %d - %-8s R$ %6.2f\n", i, it.codigo, it.produto, it.preco);
    }

    // Lendo SO o 4o registro (indice 3) sem ler os anteriores
    fseek(arq, 3 * sizeof(Item), SEEK_SET);
    fread(&it, sizeof(Item), 1, arq);
    printf("\nAcesso direto ao indice 3: %s\n", it.produto);

    fclose(arq);
    return 0;
}
