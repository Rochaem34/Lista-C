/*
13. Dados dois números naturais m e n e duas sequências ordenadas com m e n números
inteiros, obter uma única sequência ordenada contendo todos os elementos das sequências
sem repetição.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int m, n;
    printf("Informe o tamanho da 1a. sequencia: ");
    scanf("%d", &m);
    printf("Informe o tamanho da 2a. sequencia: ");
    scanf("%d", &n);
    int seq1[m], seq2[n], seq3[m + n], i, j, k = -1;
    
    printf("Informe os %d elementos da 1a. sequencia: ", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &seq1[i]);
    }
    printf("Informe os %d elementos da 2a. sequencia: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &seq2[i]);
    }
    i = j = 0;    
    while (i < m && j < n) {
        if (seq1[i] < seq2[j]) {
            if (k == -1 || seq3[k] != seq1[i]) {
                seq3[++k] = seq1[i];
            }
            i++;
        }
        else {
            if (k == -1 || seq3[k] != seq2[j]) {
                seq3[++k] = seq2[j];
            }
            j++;
        }
    }
    while (i < m) {
        if (seq1[i] != seq3[k]) {
            seq3[++k] = seq1[i];
        }
        i++;
    }
    while (j < n) {
        if (seq2[j] != seq3[k]) {
            seq3[++k] = seq2[j];
        }
        j++;
    }
    printf("\nSequencia ordenada sem repeticao de elementos das 2 sequencias:\n");
    for (i = 0; i <= k; i++) {
        printf("%d ", seq3[i]);
    }
    printf("\n");
    return 0;
}