/*
7. Escreva um programa para ler 6 nomes em um vetor de strings A. Depois formar um vetor
de strings B de tal forma que os elementos (nomes) estejam em ordem inversa a do vetor A.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[6][31], b[6][31];
    int i;

    printf("Informe 6 nomes:\n");
    for (i = 0; i < 6; i++) {
        scanf(" %30[^\n]", a[i]);
    }

    for (i = 0; i < 6; i++) {
        strcpy(b[i], a[5 - i]);
    }

    printf("\nNomes em ordem inversa:\n");
    for (i = 0; i < 6; i++) {
        puts(b[i]);
    }
    return 0;
}