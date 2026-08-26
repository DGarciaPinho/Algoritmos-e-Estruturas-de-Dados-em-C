/*
8. Considere as seguintes declarações:
i n t x = 10 ;
i n t * p = &x ;
i n t * * q = &p ;
Sem alterar as declarações acima apresentadas, analise cada uma das expressões
abaixo e descreva o que ela representa em relação às variáveis e aos ponteiros
declarados. Para cada expressão, indique se o resultado corresponde a um valor
ou a um endereço. Caso seja um endereço, informe a qual variável ou ponteiro esse
endereço está associado. Caso seja um valor, informe de qual variável esse valor é
obtido.
a) x
b) &x
c) p
d) *p
e) &p
f) q
g) *q
h) **q
*/ 


#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    int **q = &p;

    printf("x    = %d\n", x);
    printf("&x   = %p\n", (void*)&x);
    printf("p    = %p\n", (void*)p);
    printf("*p   = %d\n", *p);
    printf("&p   = %p\n", (void*)&p);
    printf("q    = %p\n", (void*)q);
    printf("*q   = %p\n", (void*)*q);
    printf("**q  = %d\n", **q);

    return 0;
}
