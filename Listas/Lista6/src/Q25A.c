/*
25. (Compactação de texto) Um mecanismo simples de compactação pode representar uma sequência de
caracteres iguais por meio do caractere seguido da quantidade de vezes que ele aparece consecutivamente. Por
exemplo, o texto:
“aaabbccccdaa”
pode ser compactado como:
“a3b2c4d1a2”
Desenvolva um programa em C que leia uma string e produza sua representação compactada. Para cada
sequência de caracteres iguais e consecutivos, o programa deverá armazenar no resultado:
1. o caractere da sequência;
2. a quantidade de ocorrências consecutivas desse caractere.
A contagem deverá considerar a diferença entre letras maiúsculas e minúsculas. Portanto, ‘A’ e ‘a’ representam
caracteres diferentes. A string de entrada será formada apenas por letras e terá no máximo 100 caracteres. A
string compactada deverá ser armazenada em outro arranjo antes de ser impressa. Considere que esse arranjo
possui capacidade suficiente para armazenar o resultado.
Ao final, o programa também deverá informar se a representação compactada possui menos caracteres do que a
string original. Exemplo:
Entrada: aaaaaabbbbcc
Saida: a6b4c2
Houve reducao: sim
*/

