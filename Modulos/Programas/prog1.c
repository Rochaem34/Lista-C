#include <stdio.h>
#include "my_io.h"

int main() 
{
    int n;
    printf("Tamanho da string (min. 5): ");
    while (!read_int(&n) || n < 5) {
        printf("Voce nao digitou um inteiro maior ou igual a 5!\nTamanho da string (min. 5): ");
    }
    char str[n + 1];
    printf("Informe uma string (max. %d): ", n);
    read_line(str, n);
    printf("String informada: %s\n", str);
    return 0;
}