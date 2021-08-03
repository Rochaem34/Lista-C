/*
16. Criar um programa em C que leia os elementos de uma matriz inteira n x n e:
a. escreva os elementos da diagonal principal;
b. escreva todos os elementos, exceto os elementos da diagonal principal;
c. escreva os elementos da diagonal secundária.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    int mat[n][n], i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = rand() % (n * n);
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal principal: ");
    for (i = 0; i < n; i++) {
        printf("%d ", mat[i][i]);
    }
    printf("\n\nMatriz sem a diagonal principal:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("%d", mat[i][j]);
            }
            printf("\t");
        }
        printf("\n");
    }
    printf("\nDiagonal secudaria: ");
    for (i = 0, j = n - 1; i < n; i++, j--) {
        printf("%d ", mat[i][j]);
    }
    printf("\n");
    return 0;
}
