# Algoritmos e Estruturas de Dados em C

Repositório com as resoluções, em C, das listas de exercícios da disciplina de Algoritmos e Estruturas de Dados (AEDs 1). Os enunciados originais estão disponíveis em PDF na pasta [`PDF/`](PDF), junto com os slides das aulas.

## Estrutura do repositório

```
Lista1/   Exercícios introdutórios (aulas da Marta)
Lista2/   Vetores e matrizes
Lista3/   Manipulação de vetores in-place
PDF/      Enunciados e slides das aulas
```

## Lista 1 — Fundamentos da linguagem C

Exercícios de aquecimento das aulas da Marta, focados na base da linguagem: entrada e saída, estruturas condicionais (`if/else`) e operadores aritméticos. Exemplos: cálculo de médias ponderadas, verificação de par/ímpar, aplicação de descontos e reajustes salariais, e uma calculadora simples com os quatro operadores.

Arquivos nomeados como `AulaMarta1Qn.c`.

## Lista 2 — Vetores e matrizes

Primeiro contato com estruturas de dados propriamente ditas: vetores e matrizes bidimensionais. As questões já exigem mais raciocínio algorítmico, incluindo:

- Separação de vetores por sinal e verificação de palíndromo;
- Deslocamento de zeros e ponto de equilíbrio em um vetor;
- **Maior soma de subvetor contíguo (Kadane)** — [`Lista2Q5(KADANE).c`](Lista2/Lista2Q5(KADANE).c);
- Número ausente em uma sequência;
- Soma de borda/interior de matriz, troca de linhas/colunas, multiplicação de matrizes;
- Verificação de quadrado mágico e **percurso em espiral de matriz**.

Arquivos nomeados como `Lista2Qn.c`. A pasta [`versões/`](Lista2/versões) guarda variações de algumas soluções e [`erradas/`](Lista2/erradas) contém tentativas incorretas mantidas para referência.

## Lista 3 — Manipulação de vetores in-place ⭐

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

## Compilando e executando

Cada questão é um arquivo `.c` independente. Para compilar e rodar, por exemplo, a questão 5 da Lista 3:

```bash
gcc Lista3/Lista3Q5.c -o Lista3Q5
./Lista3Q5
```
