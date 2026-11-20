/*
6. Desenvolva um programa em C para gravar e recuperar um vetor de números inteiros em um arquivo de texto.
Organize a solução nas etapas a seguir, utilizando funções para as operações indicadas.
(a) Leitura do vetor: solicite ao usuário a quantidade de elementos, que deverá ser maior que zero. Aloque
dinamicamente um vetor com o tamanho informado e leia os números inteiros que serão armazenados nele.
(b) Gravação do vetor: implemente uma função que receba o nome do arquivo, o vetor e sua quantidade de
elementos. A função deverá gravar os dados no arquivo numeros.txt, substituindo seu conteúdo caso ele já
exista. A primeira linha deverá conter a quantidade de elementos, e a segunda, os números separados por
espaço.
Por exemplo, para o vetor {12, -5, 8, 0, 23}, o arquivo deverá conter:
5
12 -5 8 0 23
(c) Recuperação do vetor: implemente uma função que receba o nome do arquivo e recupere os dados
gravados. A função deverá ler a quantidade de elementos, alocar dinamicamente um novo vetor e preenchê-
lo com os números do arquivo. Retorne o ponteiro para o vetor alocado e informe a quantidade de
elementos por meio de um parâmetro passado por referência.
(d) Apresentação e processamento: após recuperar os dados de numeros.txt, apresente os elementos do novo
vetor e determine o menor valor, o maior valor, a soma e a média aritmética. Utilize exclusivamente o vetor
recuperado para realizar esses cálculos.
(e) Gravação dos números pares: implemente uma função que receba o nome do arquivo, o vetor recuperado e
sua quantidade de elementos. A função deverá gravar em pares.txt apenas os números pares, preservando
sua ordem. Utilize o mesmo formato de numeros.txt: quantidade de números pares na primeira linha e valores separados por espaço na segunda. Caso não existam números pares, grave 0 na primeira linha e
deixe a segunda vazia.
(f) Organização e liberação dos recursos: na função main, execute as etapas na ordem apresentada, sem utilizar
menu de opções. Cada função deverá verificar o sucesso das aberturas de arquivos e das alocações de
memória que realizar, sinalizando eventuais falhas por meio de seu retorno. A função main deverá verificar
esses retornos antes de prosseguir. Feche cada arquivo na função que o abriu e libere toda a memória
alocada dinamicamente quando ela não for mais necessária.
*/


