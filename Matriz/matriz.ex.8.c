/*
24. A empresa Evite Desperdício tem registrado numa tabela os consumos mensais de energia elétrica
dos anos 2018-2020. Cada linha representa um ano e cada coluna um mês. Considerando esses
dados, fazer um programa em C que imprima:
a) o consumo médio em cada um dos meses destes 3 anos;
b) o mês/ano em que a empresa gastou mais energia nestes 3 anos. Considere que não há
empate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int consumo[3][12];
    int i, j, ano, mes;
    float consumo_medio;
    srand(time(NULL));
    printf("Informe o consumo em cadas mes de cada ano\n");
    for (i = 0; i < 3; i++) {
        printf("\nConsumo do ano %d\n", 2018 + i);
        for (j = 0; j < 12; j++) {
            consumo[i][j] = rand() % 200 + 1; // valor entre 1 e 200
            printf("Mes %02d: %d\n", j + 1, consumo[i][j]);
        }
    }
    printf("\nConsumo medio\n");
    for (j = 0; j < 12; j++) {
        consumo_medio = 0;
        for (i = 0; i < 3; i++) {
            consumo_medio += consumo[i][j];
        }
        consumo_medio /= 3;
        printf("Mes %02d: %.2f\n", j + 1, consumo_medio);

    }
    ano = mes = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 12; j++) {
            if (consumo[i][j] > consumo[ano][mes]) {
                ano = i;
                mes = j;
            }
        }
    }
    printf("\nMes/Ano de maior consuno: %02d/%d\n", 
           mes + 1, 2018 + ano);
    return 0;
}
