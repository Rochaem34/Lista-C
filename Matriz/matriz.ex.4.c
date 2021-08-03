/*
20. Desenvolva um programa em C para entrar com os valores para uma matriz A n x m . Gerar e imprimir
A t . A matriz transposta é gerada trocando linha por coluna.
*/

#include <stdio.h>

int main()
{
    int n, m, i, j;
    printf("Informe o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &n, &m);
    int a[n][m], at[m][n];
    printf("\nInforme os elementos da matriz %dx%d\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            at[j][i] = a[i][j];
        }
    }
    printf("\nMatriz transposta %dx%d\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", at[i][j]);
        }
        printf("\n");
    }
    return 0;
}