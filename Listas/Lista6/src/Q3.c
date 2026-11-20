/*
3. A função fgets pode armazenar na string o caractere de quebra de linha ('\n') produzido quando o usuário
pressiona a tecla Enter. Desenvolva um programa em C para observar e tratar esse comportamento, realizando
as operações a seguir:
(a) Declare um arranjo de caracteres com 100 posições.
(b) Leia uma frase, que pode conter espaços em branco, utilizando a função fgets. A quantidade máxima de
caracteres lidos deverá respeitar a capacidade do arranjo.
(c) Imprima a frase utilizando a função printf. Observe que, caso tenha sido armazenado pela função fgets, o
caractere '\n' estará incluído na string e provocará uma quebra de linha antes dos demais elementos
impressos pelo programa. Para facilitar a observação, imprima algum texto ou delimitador imediatamente
depois da frase.
(d) Percorra a string, localize o caractere '\n' e substitua-o pelo caractere nulo '\0'.
(e) Imprima novamente a frase utilizando a função printf e constate que o caractere '\n' não está mais incluído
na string. Para facilitar a observação, imprima algum texto ou delimitador imediatamente depois da frase.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  // (A)
  char *ptr = malloc(100 * sizeof(char));

  // (B)
  fgets(ptr,100, stdin);

  // (C)
  printf("Antes : [%s]\n",ptr);

  // (D) Substitui o primeiro '\n' encontrado por '\0'
  for (int i = 0; ptr[i] != '\0'; i++) {
    if (ptr[i] == '\n'){
      ptr[i] = '\0';
      break; 
    }
  }

  // (E) Mostra a frase depois da alteração
  printf("Depois: [%s]\n", ptr);


  return 0;
}
