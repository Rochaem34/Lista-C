/*
1)Escreva um programa que dada uma string, escreva-a de trás para frente.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[61];
    printf("Informe uma string: ");
    scanf(" %60[^\n]", str);
    printf("\nString invertida: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
    return 0;
}