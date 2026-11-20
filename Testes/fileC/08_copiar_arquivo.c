/*
 * AULA 08 - Copiando arquivos e usando argumentos da linha de comando
 *
 * main pode receber argumentos do terminal:
 *   int main(int argc, char *argv[])
 *     argc -> quantidade de argumentos (contando o nome do programa)
 *     argv -> vetor de strings com os argumentos
 *
 * Exemplo:  ./08_copiar_arquivo origem.txt destino.txt
 *   argc = 3, argv[0] = "./08_copiar_arquivo", argv[1] = "origem.txt", argv[2] = "destino.txt"
 *
 * A copia e feita em modo BINARIO ("rb"/"wb") com um buffer, assim funciona
 * para QUALQUER tipo de arquivo (texto, imagem, executavel...).
 *
 * Compilar: gcc 08_copiar_arquivo.c -o 08_copiar_arquivo
 * Usar:     ./08_copiar_arquivo 03_ler_texto.c copia.c
 */

#include <stdio.h>

#define TAM_BUFFER 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return 1;
    }

    FILE *origem = fopen(argv[1], "rb");
    if (origem == NULL) {
        perror(argv[1]);
        return 1;
    }

    FILE *destino = fopen(argv[2], "wb");
    if (destino == NULL) {
        perror(argv[2]);
        fclose(origem);
        return 1;
    }

    unsigned char buffer[TAM_BUFFER];
    size_t lidos;
    long totalBytes = 0;

    // Le blocos de ate 4096 bytes e escreve a mesma quantidade no destino
    while ((lidos = fread(buffer, 1, TAM_BUFFER, origem)) > 0) {
        if (fwrite(buffer, 1, lidos, destino) != lidos) {
            fprintf(stderr, "Erro ao escrever em %s\n", argv[2]);
            fclose(origem);
            fclose(destino);
            return 1;
        }
        totalBytes += lidos;
    }

    // ferror diz se aconteceu algum erro durante a leitura
    if (ferror(origem)) {
        fprintf(stderr, "Erro ao ler %s\n", argv[1]);
    } else {
        printf("Copia concluida: %ld bytes copiados de '%s' para '%s'.\n",
               totalBytes, argv[1], argv[2]);
    }

    fclose(origem);
    fclose(destino);
    return 0;
}
