/*
 * AULA 01 - Abrindo e fechando arquivos
 *
 * Em C, arquivos sao manipulados por um ponteiro do tipo FILE* (definido em <stdio.h>).
 *
 *   FILE *fopen(const char *nome, const char *modo);  -> abre o arquivo
 *   int   fclose(FILE *arq);                          -> fecha o arquivo
 *
 * Principais modos do fopen:
 *   "r"  -> leitura. O arquivo PRECISA existir (senao retorna NULL).
 *   "w"  -> escrita. Cria o arquivo; se ja existir, APAGA todo o conteudo.
 *   "a"  -> append (acrescentar). Cria se nao existir; escreve sempre no final.
 *   "r+" -> leitura e escrita. O arquivo precisa existir.
 *   "w+" -> leitura e escrita. Cria/apaga o arquivo.
 *   "a+" -> leitura e escrita no final.
 *   Acrescente "b" para modo binario: "rb", "wb", "ab", "r+b"...
 *
 * REGRA DE OURO: sempre verifique se o fopen retornou NULL!
 *
 * Compilar: gcc 01_abrir_fechar.c -o 01_abrir_fechar
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;

    // 1) Abrindo para escrita: o arquivo e criado se nao existir
    arq = fopen("teste.txt", "w");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    printf("Arquivo 'teste.txt' criado/aberto com sucesso.\n");
    fclose(arq); // sempre feche! Isso garante que os dados sejam gravados no disco

    // 2) Tentando abrir um arquivo que NAO existe em modo leitura
    arq = fopen("nao_existe.txt", "r");
    if (arq == NULL) {
        // perror imprime sua mensagem + o motivo do erro dado pelo sistema
        perror("Erro ao abrir 'nao_existe.txt'");
    } else {
        fclose(arq);
    }

    // 3) Removendo o arquivo criado (funcao remove de <stdio.h>)
    if (remove("teste.txt") == 0) {
        printf("Arquivo 'teste.txt' removido.\n");
    }

    return 0;
}
