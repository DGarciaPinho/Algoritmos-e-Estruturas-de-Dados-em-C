#include <stdio.h>
#include <stdlib.h>

static void liberar_linhas(int **matriz, int linhasAlocadas)
{
    int i;

    for (i = 0; i < linhasAlocadas; i++) {
        free(matriz[i]);
    }
}

int main(void)
{
    int linhas, colunas, i, j;
    int *ponteiroSimples;
    int **ponteiroParaPonteiro;

    printf("Digite a quantidade de linhas e colunas: ");
    if (scanf("%d %d", &linhas, &colunas) != 2 || linhas <= 0 || colunas <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    /* Forma 1: todos os elementos ficam em um unico bloco contiguo. */
    ponteiroSimples = malloc((size_t) linhas * colunas * sizeof *ponteiroSimples);
    if (ponteiroSimples == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }

    printf("Preencha a matriz criada com ponteiro simples:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (scanf("%d", &ponteiroSimples[i * colunas + j]) != 1) {
                free(ponteiroSimples);
                printf("Entrada invalida.\n");
                return 1;
            }
        }
    }

    printf("Matriz com ponteiro simples:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d%c", ponteiroSimples[i * colunas + j],
                   j == colunas - 1 ? '\n' : ' ');
        }
    }
    free(ponteiroSimples);

    /* Forma 2: um arranjo de ponteiros, com uma alocacao para cada linha. */
    {
        int *arranjoDePonteiros[linhas];

        for (i = 0; i < linhas; i++) {
            arranjoDePonteiros[i] = malloc((size_t) colunas *
                                           sizeof *arranjoDePonteiros[i]);
            if (arranjoDePonteiros[i] == NULL) {
                liberar_linhas(arranjoDePonteiros, i);
                printf("Falha na alocacao.\n");
                return 1;
            }
        }

        printf("Preencha a matriz criada com arranjo de ponteiros:\n");
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                if (scanf("%d", &arranjoDePonteiros[i][j]) != 1) {
                    liberar_linhas(arranjoDePonteiros, linhas);
                    printf("Entrada invalida.\n");
                    return 1;
                }
            }
        }

        printf("Matriz com arranjo de ponteiros:\n");
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                printf("%d%c", arranjoDePonteiros[i][j],
                       j == colunas - 1 ? '\n' : ' ');
            }
        }
        liberar_linhas(arranjoDePonteiros, linhas);
    }

    /* Forma 3: o proprio arranjo de enderecos das linhas tambem e dinamico. */
    ponteiroParaPonteiro = malloc((size_t) linhas * sizeof *ponteiroParaPonteiro);
    if (ponteiroParaPonteiro == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        ponteiroParaPonteiro[i] = malloc((size_t) colunas *
                                         sizeof *ponteiroParaPonteiro[i]);
        if (ponteiroParaPonteiro[i] == NULL) {
            liberar_linhas(ponteiroParaPonteiro, i);
            free(ponteiroParaPonteiro);
            printf("Falha na alocacao.\n");
            return 1;
        }
    }

    printf("Preencha a matriz criada com ponteiro para ponteiro:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (scanf("%d", &ponteiroParaPonteiro[i][j]) != 1) {
                liberar_linhas(ponteiroParaPonteiro, linhas);
                free(ponteiroParaPonteiro);
                printf("Entrada invalida.\n");
                return 1;
            }
        }
    }

    printf("Matriz com ponteiro para ponteiro:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d%c", ponteiroParaPonteiro[i][j],
                   j == colunas - 1 ? '\n' : ' ');
        }
    }

    liberar_linhas(ponteiroParaPonteiro, linhas);
    free(ponteiroParaPonteiro);
    return 0;
}
