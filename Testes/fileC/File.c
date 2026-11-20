#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// EXEMPLO 1 

void exemplo1(){

  FILE *arquivo; // FILE *exemplo; cria o "arquivo" do tipo FILE no buffer 

  arquivo = fopen("arquivo.txt","w"); // A função abre o arquivo    fopen("NomeDoArquivo","ModoDeAbertura");
  // MODOS DE ACESSO 
  // r : Somente Leitura
  // r+: Leitura e Escrita
  // w : Apaga o conteudo antigo do arquivo e no começo da abertura edita o arquivo
  // w+: Apaga o conteudo antigo do arquivo e permite a leitura e edição
  // a : Não apaga o conteudo antigo do arquivo , escreve no final
  // a+: Não apaga o conteudo antigo do arquivo, permite ler e editar no final
  
  printf("Arquivo Criado");

  fclose(arquivo); // Função que fecha o arquivo
}

void exemplo2(){}
