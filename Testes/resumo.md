# Resumo — AEDS1 (Algoritmos e Estruturas de Dados I)

> Baseado nos slides das Aulas 1-4 (Profª. Marta Noronha) e nas Listas 1-5 resolvidas neste repositório.

---

## 1. Fundamentos (Aula 1-2 / Lista 1)

**Etapas de desenvolvimento de um programa:** Análise → Algoritmo (narrativa, fluxograma ou pseudocódigo) → Codificação.

**Algoritmo:** procedimento computacional bem definido que recebe entrada(s) e produz saída(s).

**Estruturas de controle de fluxo em C:**
- `if` / `else` — executa bloco se condição verdadeira.
- `switch` — seleciona um bloco entre vários, por valor de expressão.
- `for` — repete com inicialização/condição/atualização definidas na própria linha.
- `while` — testa a condição **antes** de cada iteração (pode não executar nenhuma vez).
- `do-while` — testa a condição **depois**, garante ao menos 1 execução.

**Padrão de programas da Lista 1:** ler entrada com `scanf`, processar com fórmula/condicional, exibir com `printf`. Ex.: área/perímetro de retângulo, conversão C→F, média ponderada, par/ímpar, maioridade, desconto condicional, calculadora com `switch`.

⚠️ Pegadinha clássica: comparar floats com `==` é arriscado (erro de ponto flutuante); e cuidado com divisão inteira (`5/2 == 2`, precisa de `5.0/2` ou cast).

---

## 2. Vetores e Matrizes (Aula 3 / Lista 2)

**Por que vetores?** Uma variável escalar (`int nota;`) é sobrescrita a cada `scanf`. Um vetor guarda **vários valores sob um mesmo nome**, indexados (`notas[0]`, `notas[1]`, ...). Todos os elementos têm o mesmo tipo. Tamanho fixo definido na declaração: `int vetor[5];`.

**Matrizes** = vetores de duas dimensões (`int m[6][6];`), acessadas por `m[linha][coluna]`.

### Algoritmos importantes da Lista 2

- **Separar por sinal**: percorrer uma vez, jogar em dois vetores conforme `v[i] < 0`.
- **Palíndromo**: comparar `v[i]` com `v[n-1-i]` para `i` até `n/2`.
- **Mover zeros para o fim mantendo ordem**: índice auxiliar que só avança quando grava um não-zero; depois preencher o resto com zero.
- **Ponto de equilíbrio**: pré-calcular soma total; percorrer acumulando soma da esquerda e comparar com `total - somaEsquerda - v[i]`.
- **Kadane — maior soma de subvetor contíguo** (`Lista2Q5(KADANE).c`) — **cai muito em prova**:
  ```c
  int somaAtual = v[0], inicioAtual = 0;
  int somaMax = v[0], inicioMax = 0, fimMax = 0;
  for (i = 1; i < N; i++) {
      if (somaAtual + v[i] >= v[i]) somaAtual += v[i];      // continua o trecho
      else { somaAtual = v[i]; inicioAtual = i; }           // recomeça em i
      if (somaAtual > somaMax) {
          somaMax = somaAtual; inicioMax = inicioAtual; fimMax = i;
      }
  }
  ```
  Ideia: em cada posição decide "vale a pena carregar a soma anterior, ou começo de novo aqui?". O(n), programação dinâmica.
- **Número ausente em 1..N**: soma esperada `N*(N+1)/2` menos soma do vetor.
- **Matriz — borda vs. interior**: elemento é borda se `i==0 || i==lin-1 || j==0 || j==col-1`.
- **Troca de linhas/colunas**: `swap` elemento a elemento entre as duas linhas/colunas.
- **Multiplicação de matrizes A(m×n)·B(n×p) = C(m×p)**: triplo loop, `C[i][j] += A[i][k]*B[k][j]`.
- **Quadrado mágico**: soma de cada linha, cada coluna e as duas diagonais deve ser igual.
- **Percurso em espiral** (`Lista2Q12.c`) — usa 4 limites que vão "encolhendo":
  ```c
  int linhaIni=0, linhaFim=3, colIni=0, colFim=3;
  while (linhaIni <= linhaFim && colIni <= colFim) {
      for (j = colIni; j <= colFim; j++) ...   linhaIni++;   // →
      for (i = linhaIni; i <= linhaFim; i++) ... colFim--;   // ↓
      if (linhaIni <= linhaFim) { for (j = colFim; j >= colIni; j--) ...  linhaFim--; } // ←
      if (colIni <= colFim)     { for (i = linhaFim; i >= linhaIni; i--) ... colIni++; } // ↑
  }
  ```
  Os `if` extras evitam repetir/errar quando sobra só uma linha ou coluna. ⚠️ `Lista2Q12.c` no repo está com bug (usa `i`/`j` sem declarar fora do primeiro `for`) — revisar antes de copiar como gabarito.

---

## 3. Modularização e Funções (Aula 4)

**Modularização** = dividir um problema grande em módulos menores e independentes (dividir para conquistar). Vantagens: reduz complexidade, evita repetição, facilita manutenção, permite reuso.

**Função em C:**
```c
tipoRetorno nomeFuncao(parametros) {
    // instruções
    return valor; // se tipoRetorno != void
}
```
- Função **`void`** não retorna valor — usada como "procedimento".
- Passagem por valor (padrão): a função recebe **cópia**, não altera a variável original.
- Passagem por referência (via ponteiro): a função recebe o **endereço** e pode alterar o original — base de toda a Lista 4.

---

## 4. Manipulação de vetores in-place (Lista 3)

Fio condutor: resolver tudo **sem vetor auxiliar**, só manipulando índices do próprio vetor.

| Questão | Técnica |
|---|---|
| Inverter vetor | dois índices `ini`/`fim`, `swap` e caminham um para o outro até se cruzarem |
| Remover elemento numa posição | deslocar todos os elementos à direita uma posição para a esquerda, a partir da posição removida |
| Remover todas ocorrências de um valor | índice de escrita `w`: para cada elemento diferente do valor, copia para `v[w++]` |
| Inserir em posição | deslocar elementos da direita para a esquerda para "abrir espaço", depois inserir |
| Rotação 1 posição à direita | guardar último elemento, deslocar todos +1, colocar o guardado no início |
| **Rotação N posições** (`Lista3Q15.c`) — **método das 3 inversões**, O(n), sem vetor extra: |
| | ```inverte(v,0,tam-1); inverte(v,0,n-1); inverte(v,n,tam-1);``` — inverte tudo, depois inverte cada um dos dois blocos separadamente |
| Trocar metades do vetor | mesma ideia das 3 inversões (inverte metade1, inverte metade2, inverte tudo) ou rotação de tam/2 |
| Remover duplicatas (vetor qualquer) | para cada elemento, verificar se já apareceu antes; se sim, remover (deslocar) |
| Remover duplicatas (vetor **ordenado**) | mais simples: comparar só com o vizinho anterior, já que iguais ficam juntos |
| Ordenar sem função pronta | Bubble/Selection/Insertion sort implementados manualmente |
| Intercalar dois vetores | alternar elemento de A e de B no vetor resultado |
| União / Interseção de conjuntos | união: todos elementos sem repetir (checar antes de inserir); interseção: só os que aparecem nos dois |
| Compactar removendo sentinela -1 | igual à remoção de ocorrências: índice de escrita avança só quando valor ≠ -1 |

**Padrão geral de "remover sem buraco":** manter um índice de escrita separado do índice de leitura, e só copiar quando o elemento deve ficar.

---

## 5. Ponteiros e Aritmética de Ponteiros (Lista 4)

### Conceitos base
```c
int x = 10;
int *p = &x;     // p guarda o ENDEREÇO de x
int **q = &p;    // q guarda o endereço de p (ponteiro para ponteiro)
```
- `x` → valor de x.
- `&x` → endereço de x (mesmo valor que `p`).
- `p` → valor de p, isto é, o endereço de x.
- `*p` → valor apontado por p = valor de x.
- `&p` → endereço de p (mesmo valor que `q`).
- `q` → valor de q = endereço de p.
- `*q` → valor apontado por q = valor de p = endereço de x.
- `**q` → desreferencia duas vezes = valor de x.

*(Esse tipo de questão de "o que cada expressão representa" cai literalmente em prova — Lista4 Q8.)*

### Passagem por referência (retornar valores por parâmetro)
```c
void incrementar(int *valor) { *valor += 1; }
void troca(int *a, int *b) { int t=*a; *a=*b; *b=t; }
void divisao(int a, int b, int *q, int *r) { *q = a/b; *r = a%b; }
void ordenar2(int *a, int *b) { if (*a > *b) troca(a,b); }
```
Regra de ouro: **para a função alterar a variável do chamador, ela precisa receber um ponteiro (endereço) e usar `*` para acessar/alterar o conteúdo.**

`ordenar3`/`ordenar4` (Q12, Q18): ordenar variáveis soltas **sem vetor**, só com comparações e `troca` entre ponteiros (~bubble sort manual sobre `*a,*b,*c,*d`).

### Percorrer vetor só com aritmética de ponteiros (sem `v[i]`)
```c
int somaVetor(int *vetor, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(vetor + i);   // equivalente a vetor[i], mas via aritmética
        // ou: soma += *vetor++;
    }
    return soma;
}
```
- `*(vetor + i)` ≡ `vetor[i]`.
- Percorrer com `p++`/`p--` avança o ponteiro para o próximo `int` (soma `sizeof(int)` bytes automaticamente).
- Inverter vetor com 2 ponteiros sem índice (Q20):
  ```c
  void inverter(int *inicio, int *fim) {
      while (inicio < fim) {
          int t = *inicio; *inicio = *fim; *fim = t;
          inicio++; fim--;
      }
  }
  ```

### Funções que retornam ponteiro
```c
int *maiorElemento(int *vetor, int tamanho) {
    int *maior = vetor;
    for (int i = 1; i < tamanho; i++)
        if (vetor[i] > *maior) maior = &vetor[i];
    return maior;
}
// posição = maior - vetor;   <-- diferença entre ponteiros dá o índice!
```
```c
int *buscar(int *vetor, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++)
        if (vetor[i] == valor) return &vetor[i];
    return NULL;   // não encontrado
}
```

### Ponteiro para ponteiro (`int **`)
Usado quando a função precisa **fazer um ponteiro externo apontar para outra coisa**:
```c
void apontaMaior(int **p, int *a, int *b) {
    if (*a >= *b) *p = a; else *p = b;   // muda para ONDE p aponta
}
// uso: apontaMaior(&ptr, &n, &m);  depois  *ptr = 0;
```
Mesmo raciocínio em `localizarExtremos`/`minMax`: recebem `int **menor, int **maior` e fazem `*menor = &vetor[posMin]`, `*maior = &vetor[posMax]`.

### Matriz como bloco contíguo de memória
```c
int somaMatriz(int *p, int quantidade) {   // p = &matriz[0][0]
    int soma = 0;
    for (int i = 0; i < quantidade; i++) soma += *(p + i);
    return soma;
}
// chamada: somaMatriz(&matriz[0][0], 9);
```
⚠️ Isso só funciona porque uma matriz estática `int m[3][3]` é contígua na memória. Não confundir com matriz alocada dinamicamente (linhas podem não ser contíguas — ver seção 6).

⚠️ `Lista4/Q24.c` no repositório usa `int **p` (errado para esse exercício — deveria ser `int *p` percorrendo com aritmética simples); revisar antes de estudar por ele.

---

## 6. Alocação Dinâmica de Memória (Lista 5)

### `malloc`, `calloc`, `realloc`, `free`
```c
int *v = malloc(n * sizeof(int));          // aloca, lixo de memória
int *v2 = calloc(n, sizeof(int));          // aloca e zera
v = realloc(v, novoTamanho * sizeof(int)); // redimensiona (pode mudar de endereço!)
free(v);                                    // libera — sempre que malloc/calloc/realloc foi usado
```

**Pegadinha teórica (Q1 da Lista 5):**
```c
int *ptr = malloc(sizeof(int));  *ptr = 10;
for (i=0;i<5;i++) *ptr = *ptr + 1;   // ALTERA O CONTEÚDO -> ptr aponta pro mesmo lugar, valor vira 15
// vs.
for (i=0;i<5;i++) ptr = ptr + 1;     // ANDA COM O PONTEIRO -> ptr aponta 5 int's à frente (endereço mudou!)
```
`*ptr = *ptr + 1` modifica o **valor guardado**; `ptr = ptr + 1` modifica o **endereço para onde o ponteiro aponta** (anda `sizeof(int)` bytes). Fazer `free(ptr)` depois de mover o ponteiro é **erro grave** (undefined behavior — você não está mais no início do bloco alocado).

### `realloc` — fluxo típico (Q5)
1. Aloca 5 posições, preenche, imprime endereços.
2. `realloc` para 10 posições — os primeiros 5 valores são preservados; o bloco pode ter sido movido inteiro para outro endereço.
3. Preenche as 5 novas, imprime tudo de novo.

### Três formas de representar matriz dinâmica (Q6)
1. **Ponteiro simples** (bloco contíguo, indexar manualmente):
   ```c
   int *m = malloc(lin*col*sizeof(int));
   m[i*col + j] = valor;   // simula m[i][j]
   ```
2. **Arranjo de ponteiros** (vetor de ponteiros, cada um aponta para uma linha alocada separadamente):
   ```c
   int *m[LIN];
   for (i=0;i<LIN;i++) m[i] = malloc(col*sizeof(int));
   ```
3. **Ponteiro para ponteiro** (tudo dinâmico, inclusive o vetor de linhas):
   ```c
   int **m = malloc(lin*sizeof(int*));
   for (i=0;i<lin;i++) m[i] = malloc(col*sizeof(int));
   // m[i][j] ou *(*(m+i)+j)
   ```
   ⚠️ Aqui as linhas **não são necessariamente contíguas** na memória (cada `malloc` interno pode cair em endereço diferente) — diferente da matriz estática da seção 5.

### Matriz tridimensional (Q8)
Mesma lógica em mais um nível:
```c
int ***m = malloc(prof * sizeof(int**));
for (k=0;k<prof;k++) {
    m[k] = malloc(lin * sizeof(int*));
    for (i=0;i<lin;i++)
        m[k][i] = malloc(col * sizeof(int));
}
```
Sempre libere na ordem inversa da alocação (colunas → linhas → profundidade → matriz) para não perder ponteiros e vazar memória.

⚠️ `Lista5/Q8.c` no repo tem bugs (variável `prtz`/`prt1` trocada e `scanf` com endereço de ponteiro em vez de elemento) — não usar como gabarito, só como lembrete da ideia geral.

---

## 7. Extra: Hash Table (`Estruturas/HashTable`)

Conteúdo além das 5 listas — útil se cair na prova ou for usado em exercícios de revisão (o exemplo do repo resolve LeetCode 219 "Contains Duplicate II").

- **Chave → Função Hash → Tabela Hash.**
- Tamanho da tabela (T) deve ser **primo**, idealmente ≈ 2× a quantidade de dados.
- **Fator de carga** `FC = n/T`: quanto mais perto de 0 mais espaço desperdiçado; quanto mais perto de 1, pior a busca (mais colisões). Manter espaços vazios é importante para eficiência.
- **Função de espalhamento simples:** `chave % tamanho` (cuidado com `% ` de número negativo em C — pode dar resultado negativo, por isso `if (h < 0) h += capacity;`).
- **Tratamento de colisão usado no exemplo:** *open addressing* com *linear probing* — se a posição já está ocupada, tenta `(idx+1) % capacity` até achar vaga (`insert`) ou até achar a chave/slot vazio (`contains`, `removeKey`).

---

## Checklist rápido antes da prova

- [ ] Sei diferenciar `if/while/do-while/for` e quando usar cada um.
- [ ] Sei declarar vetor/matriz e percorrer com `for` aninhado.
- [ ] Sei implementar Kadane de cabeça (soma máxima de subvetor).
- [ ] Sei fazer percurso em espiral com os 4 limites.
- [ ] Sei remover/inserir/rotacionar elementos de vetor **sem vetor auxiliar** (técnica do índice de escrita e/ou das 3 inversões).
- [ ] Sei explicar `x, &x, p, *p, &p, q, *q, **q` de cabeça.
- [ ] Sei escrever função que devolve 2+ valores via ponteiro (`int *a, int *b`, etc.).
- [ ] Sei percorrer vetor só com aritmética de ponteiros (sem `[]`).
- [ ] Sei usar `int **` para fazer um ponteiro externo apontar pra outra variável (`apontaMaior`, `minMax`).
- [ ] Sei diferença entre `*ptr = *ptr + 1` (muda valor) e `ptr = ptr + 1` (muda endereço) e por que isso importa pro `free`.
- [ ] Sei as 3 formas de montar matriz dinâmica (ponteiro simples / vetor de ponteiros / ponteiro-para-ponteiro) e qual delas garante memória contígua.
- [ ] Sei por que o tamanho da tabela hash deve ser primo e o que é fator de carga.
