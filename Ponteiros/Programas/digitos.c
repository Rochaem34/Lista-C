#include <stdio.h>

void digitos(int, int *, int *);

int main() 
{
    int n, num_digitos, primeiro_digito;
    printf("Informe um número inteiro: ");
    scanf("%d", &n);
    digitos(n, &num_digitos, &primeiro_digito);
    printf("%d tem %d digito(s) e o primeiro dígito é %d\n",
           n, num_digitos, primeiro_digito);
    return 0;
}

void digitos(int n, int * num, int * primeiro) 
{
    *num = 1;
    while (n >= 10) {
        (*num)++;
        n /= 10;
    }
    *primeiro = n;
}