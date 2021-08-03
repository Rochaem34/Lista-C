/*
26. Criar um programa em C que deixe entrar com valores para uma matriz de ordem n e verifique se
ela é ou não uma matriz identidade. Matriz identidade é aquela em que todos os elementos da
diagonal principal são iguais a 1 e os demais elementos são iguais a 0.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, j;
    bool id = true;

    printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    int mat[n][n];

    printf("\nInforme os elementos da matriz %dx%d\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n && id; i++) {
        for (j = 0; j < n && id; j++) {            
            if (i == j) { // diagonal principal
                if (mat[i][j] != 1) {
                    id = false;
                }
            }
            else {
                if (mat[i][j] != 0) {
                    id = false;
                }
            }
        }
    }

    if (id) {
        //printf("\nA matriz e' uma matriz identidade\n");
        puts("\nA matriz e' uma matriz identidade");
    }
    else {
        printf("\nA matriz NAO e' uma matriz identidade\n");
    }

    return 0;
}