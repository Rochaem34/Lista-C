/*
21. Escreva um programa em C que gere uma matriz 5 x 6 de inteiros. Leia também um valor inteiro x.
O programa deverá fazer uma busca desse valor na matriz e, ao final escrever sua localização
(linha e coluna) ou uma mensagem de “não encontrado”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mat[5][6], val, i, j, i_val, j_val;
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            mat[i][j] = rand() % (5 * 6 * 10);
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("Informe o valor procurado: ");
    scanf("%d", &val);
    i_val = j_val = -1;
    for (i = 0; i < 5 && i_val == -1; i++) {
        for (j = 0; j < 6; j++) {
            if (mat[i][j] == val) {
                i_val = i;
                j_val = j;
                break;
            }
        }
    }
    if (i_val != -1) {
        printf("\n%d localizado na linha %d, coluna %d da matriz\n", 
            val, i_val, j_val);
    }
    else {
        printf("\n%d nao encontrado\n", val);
    }
    return 0;
}