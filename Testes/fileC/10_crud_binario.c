/*
 * AULA 10 - Projeto final: cadastro de contatos (CRUD) em arquivo binario
 *
 * CRUD = Create, Read, Update, Delete
 * Junta tudo que foi visto:
 *   - "ab"  para adicionar registros no final
 *   - "rb"  para listar e buscar
 *   - "r+b" + fseek para ALTERAR um registro no meio do arquivo sem reescrever tudo
 *   - exclusao logica (marca o registro como inativo) e exclusao fisica
 *     (reescreve o arquivo sem os inativos, usando um arquivo temporario + rename)
 *
 * Compilar: gcc 10_crud_binario.c -o 10_crud_binario
 */

#include <stdio.h>
#include <string.h>

#define ARQUIVO "contatos.bin"

typedef struct {
    int id;
    char nome[50];
    char telefone[20];
    int ativo; // 1 = ativo, 0 = excluido (exclusao logica)
} Contato;

// Le uma linha do teclado e remove o '\n'
void lerTexto(const char *msg, char *dest, int tam) {
    printf("%s", msg);
    if (fgets(dest, tam, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\n")] = '\0';
}

int lerInt(const char *msg) {
    char buf[32];
    int valor;
    lerTexto(msg, buf, sizeof(buf));
    if (sscanf(buf, "%d", &valor) != 1) return -1;
    return valor;
}

// Gera o proximo id: maior id do arquivo + 1
int proximoId() {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) return 1; // arquivo ainda nao existe
    Contato c;
    int maior = 0;
    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        if (c.id > maior) maior = c.id;
    }
    fclose(arq);
    return maior + 1;
}

// CREATE
void adicionar() {
    Contato c;
    c.id = proximoId();
    c.ativo = 1;
    lerTexto("Nome: ", c.nome, sizeof(c.nome));
    lerTexto("Telefone: ", c.telefone, sizeof(c.telefone));

    FILE *arq = fopen(ARQUIVO, "ab");
    if (arq == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fwrite(&c, sizeof(Contato), 1, arq);
    fclose(arq);
    printf("Contato adicionado com id %d.\n", c.id);
}

// READ (todos)
void listar() {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    Contato c;
    int qtd = 0;
    printf("\n%-4s %-30s %-15s\n", "ID", "NOME", "TELEFONE");
    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        if (c.ativo) {
            printf("%-4d %-30s %-15s\n", c.id, c.nome, c.telefone);
            qtd++;
        }
    }
    fclose(arq);
    printf("Total: %d contato(s)\n", qtd);
}

// Procura o contato pelo id. Retorna a POSICAO (indice do registro) ou -1.
// Se encontrar, copia o contato para *saida.
long buscarPosicao(FILE *arq, int id, Contato *saida) {
    rewind(arq);
    Contato c;
    long pos = 0;
    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        if (c.ativo && c.id == id) {
            *saida = c;
            return pos;
        }
        pos++;
    }
    return -1;
}

// UPDATE
void editar() {
    int id = lerInt("Id do contato a editar: ");
    FILE *arq = fopen(ARQUIVO, "r+b"); // leitura E escrita, sem apagar
    if (arq == NULL) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    Contato c;
    long pos = buscarPosicao(arq, id, &c);
    if (pos == -1) {
        printf("Contato nao encontrado.\n");
        fclose(arq);
        return;
    }
    printf("Atual: %s - %s\n", c.nome, c.telefone);
    lerTexto("Novo nome: ", c.nome, sizeof(c.nome));
    lerTexto("Novo telefone: ", c.telefone, sizeof(c.telefone));

    // Volta exatamente para o inicio do registro encontrado e sobrescreve
    fseek(arq, pos * sizeof(Contato), SEEK_SET);
    fwrite(&c, sizeof(Contato), 1, arq);
    fclose(arq);
    printf("Contato atualizado.\n");
}

// DELETE (logico): so marca ativo = 0
void excluir() {
    int id = lerInt("Id do contato a excluir: ");
    FILE *arq = fopen(ARQUIVO, "r+b");
    if (arq == NULL) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    Contato c;
    long pos = buscarPosicao(arq, id, &c);
    if (pos == -1) {
        printf("Contato nao encontrado.\n");
    } else {
        c.ativo = 0;
        fseek(arq, pos * sizeof(Contato), SEEK_SET);
        fwrite(&c, sizeof(Contato), 1, arq);
        printf("Contato %d excluido (logicamente).\n", id);
    }
    fclose(arq);
}

// Remove de verdade os registros inativos, reescrevendo o arquivo
void compactar() {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    FILE *tmp = fopen("contatos.tmp", "wb");
    if (tmp == NULL) {
        perror("Erro ao criar temporario");
        fclose(arq);
        return;
    }
    Contato c;
    int removidos = 0;
    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        if (c.ativo) fwrite(&c, sizeof(Contato), 1, tmp);
        else removidos++;
    }
    fclose(arq);
    fclose(tmp);

    remove(ARQUIVO);                 // apaga o antigo
    rename("contatos.tmp", ARQUIVO); // renomeia o temporario
    printf("Compactacao concluida: %d registro(s) removido(s) fisicamente.\n", removidos);
}

int main() {
    int opcao;
    do {
        printf("\n===== AGENDA =====\n");
        printf("1 - Adicionar\n");
        printf("2 - Listar\n");
        printf("3 - Editar\n");
        printf("4 - Excluir\n");
        printf("5 - Compactar arquivo\n");
        printf("0 - Sair\n");
        opcao = lerInt("Opcao: ");

        switch (opcao) {
            case 1: adicionar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: excluir(); break;
            case 5: compactar(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
