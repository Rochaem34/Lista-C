#include <stdio.h>
int main() 
{
    int x = 10;// x é um inteiro
    int * px; // px é um ponteiro p/ inteiro
    px = &x; // px recebe o endereço de x
    printf("Endereço de x: %p\n", &x);
    printf("Valor de px: %p\n", px);
    printf("Valor de x: %d\n", x);
    printf("Valor do endereço armazenado em px: %d\n", *px);
    /* alterando dados */
    *px = 30;
    printf("Valor de x: %d\n", x);
    printf("Valor de px: %p\n", px);
    return 0;
}