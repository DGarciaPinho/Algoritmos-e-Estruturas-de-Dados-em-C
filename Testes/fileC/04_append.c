/*
 * AULA 04 - Modo "a" (append) x modo "w"
 *
 * "w" -> APAGA o conteudo anterior e comeca do zero.
 * "a" -> MANTEM o conteudo e acrescenta no final.
 *
 * Exemplo pratico: um "diario" (log). Cada vez que voce roda o programa,
 * uma nova entrada e adicionada no final de 'diario.txt'.
 * Rode o programa varias vezes e veja o arquivo crescer!
 *
 * Compilar: gcc 04_append.c -o 04_append
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char mensagem[200];

    printf("Digite uma mensagem para o diario: ");
    if (fgets(mensagem, sizeof(mensagem), stdin) == NULL) return 1; // fgets tambem le do teclado (stdin)!
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // Pegando data/hora atual para registrar junto
    time_t agora = time(NULL);
    char dataHora[30];
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", localtime(&agora));

    // Abrindo em modo append
    FILE *arq = fopen("diario.txt", "a");
    if (arq == NULL) {
        perror("Erro ao abrir diario.txt");
        return 1;
    }
    fprintf(arq, "[%s] %s\n", dataHora, mensagem);
    fclose(arq);

    // Lendo o diario inteiro para mostrar na tela
    arq = fopen("diario.txt", "r");
    if (arq == NULL) {
        perror("Erro ao ler diario.txt");
        return 1;
    }
    printf("\n===== Conteudo do diario =====\n");
    char linha[300];
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        printf("%s", linha);
    }
    fclose(arq);

    return 0;
}
