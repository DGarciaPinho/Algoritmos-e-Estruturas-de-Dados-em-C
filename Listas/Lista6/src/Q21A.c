/*
Em todas as questões, além da função solicitada, deverá ser desenvolvido um programa principal para ler os dados
necessários, chamar a função e apresentar o resultado obtido. Não poderão ser utilizadas as funções prontas de
<string.h>, a não ser que seja solicitado.

21. Implemente a função:
int separarPalavras(const char *frase, char palavras[][30]);
A função deverá separar as palavras existentes na string frase e armazená-las, individualmente, nas linhas da
matriz palavras. Cada palavra armazenada deverá ser finalizada com o caractere nulo '\0'. Considere uma palavra
como uma sequência de um ou mais caracteres diferentes de espaço. A frase poderá apresentar espaços no
início, no final e entre as palavras, inclusive vários espaços consecutivos. A frase original não pode ser
modificada.
A função deverá retornar a quantidade de palavras encontradas. Considere que:
• a frase possui no máximo 99 caracteres;
• a frase contém no máximo 20 palavras;
• cada palavra possui no máximo 29 caracteres;
• somente o caractere ' ' deverá ser considerado como separador.
Por exemplo, para a frase " Estruturas de dados em C ", a matriz deverá armazenar:
palavras[0]: "Estruturas"
palavras[1]: "de"
palavras[2]: "dados"
palavras[3]: "em"
palavras[4]: "C"
Nesse caso, a função deverá retornar 5. Sua solução deverá utilizar função strtok de <string.h>. Desenvolva um
programa para:
1. ler uma frase;
2. chamar a função separarPalavras;
3. imprimir a quantidade de palavras encontradas;
4. imprimir cada palavra em uma linha diferente.
*/

