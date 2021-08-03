/*
17. Escreva um programa em C que declare uma matriz 10 x 10. Preencha com 1 a diagonal principal e
com 0 os demais elementos. Escreva ao final a matriz obtida.
*/

#include <stdio.h>

int main()
{
    /*
    int mat[10][10] = { [0][0] = 1, [1][1] = 1, [2][2] = 1, [3][3] = 1,
                        [4][4] = 1, [5][5] = 1, [6][6] = 1, [7][7] = 1,
                        [8][8] = 1, [9][9] = 1 };
    */
    int mat[10][10] = { 0 };                    
    int i, j;
    for (i = 0; i < 10; i++) {
        mat[i][i] = 1;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}