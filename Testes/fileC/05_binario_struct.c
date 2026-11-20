/*
 * AULA 05 - Arquivos binarios com fwrite e fread
 *
 * Arquivo TEXTO: os dados sao gravados como caracteres legiveis (ex.: o numero 1234 vira "1234").
 * Arquivo BINARIO: os dados sao gravados exatamente como estao na memoria (bytes).
 *   Vantagens: mais rapido, tamanho fixo por registro, grava structs inteiras de uma vez.
 *   Desvantagem: nao da pra abrir e ler no editor de texto.
 *
 *   size_t fwrite(const void *ptr, size_t tamanho, size_t qtd, FILE *arq);
 *   size_t fread (void *ptr,       size_t tamanho, size_t qtd, FILE *arq);
 *
 *   ptr     -> endereco dos dados (de onde ler / onde guardar)
 *   tamanho -> tamanho de CADA elemento (use sizeof)
 *   qtd     -> quantos elementos
 *   retorno -> quantos elementos foram realmente escritos/lidos
 *
 * Compilar: gcc 05_binario_struct.c -o 05_binario_struct
 */

#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    float media;
} Aluno;

int main() {
    Aluno turma[3] = {
        {1001, "Ana", 9.5f},
        {1002, "Bruno", 7.0f},
        {1003, "Carla", 8.3f}
    };

    // ---------- Gravando ----------
    FILE *arq = fopen("alunos.bin", "wb");
    if (arq == NULL) {
        perror("Erro ao criar alunos.bin");
        return 1;
    }
    // Grava o vetor inteiro de uma vez: 3 elementos de sizeof(Aluno) bytes cada
    size_t gravados = fwrite(turma, sizeof(Aluno), 3, arq);
    printf("Registros gravados: %zu (cada um tem %zu bytes)\n", gravados, sizeof(Aluno));
    fclose(arq);

    // ---------- Lendo um por um ----------
    arq = fopen("alunos.bin", "rb");
    if (arq == NULL) {
        perror("Erro ao abrir alunos.bin");
        return 1;
    }
    Aluno a;
    printf("\nLendo um registro por vez:\n");
    // fread retorna 1 enquanto conseguir ler 1 registro
    while (fread(&a, sizeof(Aluno), 1, arq) == 1) {
        printf("  %d - %-6s - %.1f\n", a.matricula, a.nome, a.media);
    }
    fclose(arq);

    // ---------- Lendo tudo de uma vez para um vetor ----------
    Aluno lidos[10];
    arq = fopen("alunos.bin", "rb");
    if (arq == NULL) {
        perror("Erro ao abrir alunos.bin");
        return 1;
    }
    size_t qtd = fread(lidos, sizeof(Aluno), 10, arq); // pede 10, mas so existem 3
    fclose(arq);
    printf("\nLendo tudo de uma vez: %zu registros lidos\n", qtd);
    for (size_t i = 0; i < qtd; i++) {
        printf("  %d - %-6s - %.1f\n", lidos[i].matricula, lidos[i].nome, lidos[i].media);
    }

    // ---------- Gravando/lendo um unico int ----------
    int numero = 123456;
    arq = fopen("numero.bin", "wb");
    if (arq == NULL) return 1;
    fwrite(&numero, sizeof(int), 1, arq); // note o & : fwrite precisa do ENDERECO
    fclose(arq);

    int recuperado = 0;
    arq = fopen("numero.bin", "rb");
    if (arq == NULL) return 1;
    fread(&recuperado, sizeof(int), 1, arq);
    fclose(arq);
    printf("\nNumero gravado: %d | Numero lido: %d\n", numero, recuperado);
    printf("Tente abrir 'numero.bin' num editor de texto: vai aparecer \"lixo\", pois sao bytes crus.\n");

    return 0;
}
