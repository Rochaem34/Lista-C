/*
10. Tentando descobrir se um dado era viciado, um dono de cassino o lançou n vezes. Dados os n
resultados dos lançamentos, determinar o número de ocorrências de cada face.
*/

#include <stdio.h>

int main()
{
    int dado[6] = { 0 }, i, n, val;
    printf("Informe o numero de lancamentos do dado: ");
    scanf("%d", &n);
    printf("Informe o resultado de cada lancamento do dado:\n");
    for (i = 1; i <= n; i++) {
        printf("Valor do %do. lancamento: ", i);
        scanf("%d", &val);
        while (val < 1 || val > 6) {
            printf("Erro: valor invalido! Deve ser um valor entre 1 e 6\n");
            printf("Valor do %do. lancamento: ", i);
            scanf("%d", &val);
        }
        dado[val - 1]++;
    }
    printf("\nNumero de ocorrencias de cada face do dado:\n");
    for (i = 0; i < 6; i++) {
        printf("Face %d: %d vez(es)\n", i + 1, dado[i]);
    }
    return 0;
}