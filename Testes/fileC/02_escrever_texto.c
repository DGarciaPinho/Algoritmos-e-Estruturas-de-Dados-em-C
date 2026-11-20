/*
 * AULA 02 - Escrevendo em arquivos de texto
 *
 * Funcoes de escrita (todas em <stdio.h>):
 *   int fputc(int c, FILE *arq);                   -> escreve UM caractere
 *   int fputs(const char *s, FILE *arq);           -> escreve uma string (NAO coloca '\n')
 *   int fprintf(FILE *arq, const char *fmt, ...);  -> igual ao printf, mas no arquivo
 *
 * Curiosidade: printf("...") e o mesmo que fprintf(stdout, "...").
 *   stdout, stdin e stderr sao FILE* que ja vem abertos no programa.
 *
 * Compilar: gcc 02_escrever_texto.c -o 02_escrever_texto
 * Depois de rodar, abra o arquivo 'saida.txt' para ver o resultado.
 */

#include <stdio.h>

int main() {
    FILE *arq = fopen("saida.txt", "w");
    if (arq == NULL) {
        perror("Erro ao abrir saida.txt");
        return 1;
    }

    // fputc: um caractere por vez
    fputc('O', arq);
    fputc('i', arq);
    fputc('\n', arq);

    // fputs: uma string inteira (precisa colocar o \n manualmente)
    fputs("Linha escrita com fputs\n", arq);

    // fprintf: escrita formatada, igual ao printf
    int idade = 19;
    float nota = 8.75f;
    char nome[] = "Diogo";
    fprintf(arq, "Nome: %s | Idade: %d | Nota: %.2f\n", nome, idade, nota);

    // Escrevendo uma tabela de multiplicacao com laco
    fprintf(arq, "\nTabuada do 7:\n");
    for (int i = 1; i <= 10; i++) {
        fprintf(arq, "7 x %2d = %2d\n", i, 7 * i);
    }

    // fprintf tambem funciona com stdout (tela) e stderr (saida de erro)
    fprintf(stdout, "Arquivo 'saida.txt' gerado com sucesso!\n");

    fclose(arq);
    return 0;
}
