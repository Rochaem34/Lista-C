/*
19. Implemente um programa que dadas duas matrizes n x m de números reais e escreva uma terceira
com os maiores elementos entre as duas primeiras.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j;
    printf("Informe o numero de linhas e colunas das 2 matrizes: ");
    scanf("%d %d", &n, &m);
    double mat1[n][m], mat2[n][m], mat3[n][m];

    printf("1a matriz\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat1[i][j] = rand() % (n * m * 100) / 100.0;
            printf("%.2lf\t", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\n2a matriz\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat2[i][j] = rand() % (n * m * 100) / 100.0;
            printf("%.2lf\t", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\n3a matriz\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat3[i][j] = (mat1[i][j] > mat2[i][j] ? mat1[i][j] : mat2[i][j]);
            printf("%.2lf\t", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}