# Algoritmos e Estruturas de Dados em C

Repositório com as resoluções, em C, das listas de exercícios da disciplina de Algoritmos e Estruturas de Dados (AEDs 1). Os enunciados originais estão disponíveis em PDF na pasta [`PDF/`](PDF), junto com os slides das aulas.

## Estrutura do repositório

```
Estruturas/ Tipos de Estruturas de Dados em C 
Lista1/   Exercícios introdutórios (aulas da Marta)
Lista2/   Vetores e matrizes
Lista3/   Manipulação de vetores in-place
<<<<<<< HEAD
Lista4/   Manipulação de ponteiros in-place
=======
Lista4/   Ponteiros e aritmética de ponteiros
Lista5/   Alocação dinâmica de memória
>>>>>>> 0796214 (Atualizando o readme)
PDF/      Enunciados e slides das aulas
```

## Lista 1 — Fundamentos da linguagem C

Exercícios de aquecimento das aulas da Marta, focados na base da linguagem: entrada e saída, estruturas condicionais (`if/else`) e operadores aritméticos. Exemplos: cálculo de médias ponderadas, verificação de par/ímpar, aplicação de descontos e reajustes salariais, e uma calculadora simples com os quatro operadores.

Arquivos nomeados como `AulaMarta1Qn.c` ou 'Qx.c'.

## Lista 2 — Vetores e matrizes

Primeiro contato com estruturas de dados propriamente ditas: vetores e matrizes bidimensionais. As questões já exigem mais raciocínio algorítmico, incluindo:

- Separação de vetores por sinal e verificação de palíndromo;
- Deslocamento de zeros e ponto de equilíbrio em um vetor;
- **Maior soma de subvetor contíguo (Kadane)** — [`Lista2Q5(KADANE).c`](Lista2/Lista2Q5(KADANE).c);
- Número ausente em uma sequência;
- Soma de borda/interior de matriz, troca de linhas/colunas, multiplicação de matrizes;
- Verificação de quadrado mágico e **percurso em espiral de matriz**.

Arquivos nomeados como `Lista2Qn.c`. A pasta [`versões/`](Lista2/versões) guarda variações de algumas soluções e [`erradas/`](Lista2/erradas) contém tentativas incorretas mantidas para referência.

## Lista 3 — Manipulação de vetores in-place 

Esta é a lista com as **questões mais interessantes** do repositório. O fio condutor é resolver problemas clássicos de manipulação de vetores **sem usar um vetor auxiliar**, o que obriga a pensar em algoritmos in-place e manipulação cuidadosa de índices — muito mais próximo do tipo de raciocínio cobrado em entrevistas técnicas e no dia a dia de estruturas de dados. Entre os destaques:

- Inversão de vetor in-place;
- Remoção de elemento por posição e remoção de todas as ocorrências de um valor;
- Inserção em posição arbitrária;
- **Rotação in-place** (uma posição e depois generalizada para N posições);
- Troca de metades do vetor sem vetor auxiliar;
- Remoção de duplicatas (vetor qualquer e vetor já ordenado);
- Ordenação sem funções prontas da linguagem;
- Intercalação de dois vetores, união e interseção de conjuntos;
- Compactação de vetor removendo posições inválidas (sentinela `-1`).

Arquivos nomeados como `Lista3Qn.c` (a variante `Lista3Q2F.c` é uma versão alternativa da questão 2). O enunciado completo com os 16 exercícios está em [`Lista3.txt`](Lista3/Lista3.txt).

<<<<<<< HEAD
## Lista 4 — Manipulação de ponteiros in-place
=======
## Lista 4 — Ponteiros e aritmética de ponteiros

25 exercícios dedicados a ponteiros em C, com dificuldade crescente. O tema central é usar ponteiros para **retornar valores por parâmetro** e para **percorrer vetores e matrizes sem indexação por colchetes**, apenas com aritmética de ponteiros. Principais tópicos:

- Fundamentos: declarar ponteiros, ler/alterar o valor de uma variável pelo ponteiro, imprimir endereço vs. conteúdo, comparação de valores via ponteiros (Q1–Q4);
- Passagem por referência: funções `incrementar`, `troca`, `classifica` (sinal), `ordenar2` e `ordenar3` só com comparações e trocas (Q5–Q7, Q9, Q12);
- Retorno de múltiplos resultados por parâmetro: `divisao` (quociente e resto), `estatisticas` (maior, menor e média) (Q10, Q11);
- Análise de expressões com ponteiro, ponteiro para ponteiro e desreferência (`x`, `&x`, `p`, `*p`, `&p`, `q`, `*q`, `**q`) — Q8;
- Percurso de vetor estático **só com aritmética de ponteiros**: soma, contagem de positivos/negativos/zeros, valor absoluto, extremos, contagem de pares/ímpares (Q13–Q17);
- Ordenação de 4 variáveis in-place sem vetor auxiliar (Q18);
- Funções que **retornam ponteiro**: `maiorElemento` e `buscar` (primeira ocorrência ou `NULL`), com a posição calculada pela **diferença entre ponteiros** (Q19, Q21);
- Inversão de vetor com dois ponteiros (início/fim) sem índices (Q20);
- Ponteiro para ponteiro: `apontaMaior` (`int **p`), `localizarExtremos` e `minMax` fazendo ponteiros externos apontarem para o menor/maior elemento (Q22, Q23, Q25);
- Soma de matriz 3×3 percorrida como bloco contíguo de memória com um único `int *` (Q24).

Arquivos nomeados como `Qn.c` (`Q19R.c` e `Q20R.c` são as versões revisadas dessas questões). O enunciado completo está em [`lista4.txt`](Lista4/lista4.txt) e os binários compilados ficam em [`executaveis/`](Lista4/executaveis).

## Lista 5 — Alocação dinâmica de memória

Lista sobre alocação dinâmica com `malloc`, `calloc` e `realloc`, culminando em matrizes multidimensionais alocadas em tempo de execução:

- Questão teórica comparando `*ptr = *ptr + 1` (altera o conteúdo) com `ptr = ptr + 1` (anda com o ponteiro) e o efeito de cada um sobre o `free` (Q1);
- Alocar um vetor de inteiros, preencher, imprimir e liberar (Q2);
- Vetor de `double` com tamanho informado pelo usuário, notas de alunos e média da turma (Q3);
- `calloc` de 30 inteiros preenchidos com 1–10 nas primeiras posições e 10–1 nas últimas (Q4);
- Ciclo completo com `realloc`: alocar 5 inteiros, imprimir endereços, realocar para 10, preencher e imprimir os endereços das 10 posições (Q5);
- Três formas de representar matrizes dinamicamente: ponteiro simples, arranjo de ponteiros e ponteiro para ponteiro (Q6);
- Matriz 2D com linhas e colunas alocadas dinamicamente, preenchida e impressa por procedimentos separados usando aritmética de ponteiros (Q7);
- Matriz **tridimensional** (`int ***`) com profundidade, linhas e colunas informadas pelo usuário (Q8).

Arquivos nomeados como `Qn.c`. O enunciado está em [`Lista5_AEDS1_Alocacao_Dinamica.txt`](Lista5/Lista5_AEDS1_Alocacao_Dinamica.txt), os binários em [`executaveis/`](Lista5/executaveis) e capturas de execução em [`saidas/`](Lista5/saidas).
>>>>>>> 0796214 (Atualizando o readme)

## Compilando e executando

Cada questão é um arquivo `.c` independente. Para compilar e rodar, por exemplo, a questão 5 da Lista 3:

```bash
gcc Lista3/Lista3Q5.c -o Lista3Q5
./Lista3Q5
```
