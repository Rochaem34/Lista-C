/*
8. Escreva um programa para ler 4 nomes em cada um dos vetores de strings A e B. Construir
um vetor de strings C, que será formada por um elemento do vetor A e por um elemento do
vetor B, intercaladamente.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[4][31], b[4][31], c[8][31];
    int i, j;
    
    printf("Informe os 4 nomes do vetor A:\n");
    for (i = 0; i < 4; i++) {
        scanf(" %30[^\n]", a[i]);
    }

    printf("\nInforme os 4 nomes do vetor B:\n");
    for (i = 0; i < 4; i++) {
        scanf(" %30[^\n]", b[i]);
    }

    for (i = 0, j = 0; j < 4; i += 2, j++) {
        strcpy(c[i], a[j]);
        strcpy(c[i+1], b[j]);
    }

    printf("\nValores de A e B intercalados:\n");
    for (i = 0; i < 8; i++) {
        puts(c[i]);
    }
    return 0;
}