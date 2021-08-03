/*
23. Criar um programa em C que carregue uma matriz 12 x 4 com os valores das vendas de uma loja,
em que cada linha represente um mês do ano, e cada coluna, uma semana do mês. Calcule e
imprima:
a) O total vendido em cada mês;
b) O total vendido em cada semana durante todo o ano;
c) O total vendido no ano.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double vendas[12][4], total_mes, total_semana, total_ano;
    int i, j;
    srand(time(NULL));

    printf("Vendas no ano\n");
    printf("-------------------------------------------\n");
    printf("Mes  Semana 1  Semana 2  Semana 3  Semana 4\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < 12; i++) {
        printf("%02d ", i + 1);
        for (j = 0; j < 4; j++) {
            vendas[i][j] = (rand() % 10000000) / 100.0;
            printf("%10.2lf", vendas[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");

    printf("\nTotal vendido em cada mes:\n");
    for (i = 0; i < 12; i++) {
        total_mes = 0;
        for (j = 0; j < 4; j++) {
            total_mes += vendas[i][j];
        }
        printf("Mes %02d: R$ %.2lf\n", i + 1, total_mes);
    }

    printf("\nTotal vendido em cada semana:\n");
    total_ano = 0;
    for (j = 0; j < 4; j++) {
        total_semana = 0;
        for (i = 0; i < 12; i++) {
            total_semana += vendas[i][j];
        }
        printf("Semana %d: R$ %.2lf\n", j + 1, total_semana);
        total_ano += total_semana;
    }
    printf("\nTotal de vendas no ano: R$ %.2lf\n", total_ano);
    return 0;
}