/*13. Considere um vetor estático de inteiros contendo 10 posições. Leia os elementos do
vetor e implemente uma função que calcule a soma de todos os seus elementos uti-
lizando apenas aritmética de ponteiros. O cabeçalho deverá ser int somaVetor(int
*vetor, int tamanho). Dentro da função, não utilize indexação por colchetes, como
em vetor[i], para acessar os elementos do vetor.
*/

#include <stdio.h>

int somaVetor(int *vetor, int tamanho){
  int soma=0;
  for(int i=0;i<tamanho;++i){
    soma = soma + *vetor;
    vetor++;
  }
  return soma;
}

void main(){
  int n;
  printf("Digite o numero de elementos : \n");
  scanf("%d",&n);

  int arr[n];

  for(int i=0;i<n;++i){
    printf("Digite o elemento %d",i+1);
    scanf("%d",&arr[i]);
  }

  int somaf = somaVetor(arr,n);

  printf("A soma é igual a %d",somaf);
}
