/*
11. Escreva um programa que dada uma matriz m x n de inteiros, crie um vetor de tamanho m de
inteiros que contém em cada posição o somatório dos elementos de uma linha da matriz, ou seja,
o 1o elemento do vetor deve conter o somatório dos elementos da 1a linha da matriz, o 2oelemento do vetor deve conter o somatório da 2a linha da matriz, e assim por diante. Utilize a
notação de ponteiros para fazer referência aos elementos da matriz e do vetor.
*/

#include <stdio.h>

int main(){
    int m, n, i, j;
    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d", &n);
    int matriz[m][n];
    int vetor[m];
    //memset(vetor, 0, sizeof(int) * m);

    printf("Informe os valores da matriz:\n\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("Matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%d", (*(matriz + i) + j)); // scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < m; i++){
        *(vetor + i) = 0;
        for (j = 0; j < n; j++){
            *(vetor + i) += *(*(matriz + i) + j);
        }
    }
    printf("Matriz:\n\n");

    for(i = 0; i < m; i++){
        printf("\n");
        for(j = 0; j < n; j++){
            printf("%d\t", *(*(matriz + i) + j));
        }
        printf("\n");
    }
    printf("\n\n");
    for(i = 0; i < m; i++){
        printf("Soma dos elementos da %da linha: %d\n", i + 1, *(vetor + i));
    }
    return 0;
}