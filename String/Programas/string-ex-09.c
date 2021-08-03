/*
9. Escreva um programa em C que dadas n strings, determine quantas dessas strings contém
uma string qualquer dada pelo usuário.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, cont = 0;

    printf("Informe o numero de strings do vetor: ");
    scanf("%d", &n);

    char vetor[n][31], str[31];

    printf("\nInforme %d strings:\n", n);
    for (i = 0; i < n; i++) {
        printf("%do. ", i + 1);
        scanf(" %30[^\n]", vetor[i]);
    }

    printf("\nInforme uma string: ");
    scanf(" %30[^\n]", str);

    for (i = 0; i < n; i++) {
        if (strstr(vetor[i], str) != NULL) {
            cont++;
        }
    }

    printf("\nNumero de strings do vetor que contem %s: %d\n", str, cont);
    return 0;
}