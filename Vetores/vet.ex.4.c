/*
Proposta: Criar um programa que leia os elementos de um vetor de inteiros com 10 posições. Em seguida,
troque o 1o elemento pelo último, o 2o pelo penúltimo, o 3o pelo antepenúltimo, e assim
sucessivamente. Mostre o vetor depois das trocas.
*/

#include <stdio.h>

int main()
{
    int vet[10], i, j, aux;
    printf("Informe os 10 elementos do vetor: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }

    for (i = 0, j = 9; i < j; i++, j--) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }

    printf("\nVetor apos as trocas: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    return 0;
}
