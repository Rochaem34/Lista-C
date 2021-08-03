/*
25. Criar um programa em C que deixe entrar com valores para uma matriz de ordem n e verificar se
ela é ou não uma matriz triangular superior. Matriz triangular superior é uma matriz onde todos os
elementos de posições acima da diagonal principal são diferentes de 0 e todos os elementos
demais elementos são iguais a 0.

Matriz triangular superior de ordem 5
0 1 3 4 5
0 0 6 7 8
0 0 0 1 -1
0 0 0 0 4
0 0 0 0 0
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, j;
    bool ts = true;

    printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    int mat[n][n];

    printf("\nInforme os elementos da matriz %dx%d\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n && ts; i++) {
        for (j = 0; j < n && ts; j++) {
            // acima da diagonal principal
            if (j > i) {
                if (mat[i][j] == 0) {
                    ts = false;
                }
            }
            else {
                if (mat[i][j] != 0) {
                    ts = false;
                }
            }
        }
    }

    if (ts) {
        printf("\nA matriz e' triangular superior\n");
    }
    else {
        printf("\nA matriz NAO e' triangular superior\n");
    }

    return 0;
}