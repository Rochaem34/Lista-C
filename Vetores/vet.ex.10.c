/*
14. Dadas duas sequências com n números inteiros entre 0 e 9, interpretadas como dois números
inteiros de n algarismos, calcular a sequência de números que representa a soma dos dois inteiros.
*/

#include <stdio.h>

int main()
{
    int n, i;
    printf("Numero de algarismos dos numeros: ");
    scanf("%d", &n);
    int num1[n], num2[n], result[n + 1];
    int vai1 = 0;
    
    printf("Informe o 1o. numero: ");
    for (i = 0; i < n; i++) {
        scanf("%1d", &num1[i]);
    }

    printf("Informe o 2o. numero: ");
    for (i = 0; i < n; i++) {
        scanf("%1d", &num2[i]);
    }

    for (i = n; i > 0; i--) {
        result[i] = num1[i - 1] + num2[i - 1] + vai1;
        vai1 = result[i] / 10;
        result[i] %= 10;
    }
    result[i] = vai1;
    printf("\nResultado da soma: ");
    if (result[0] > 0) {
        printf("%d", result[0]);
    }
    for (i = 1; i < n + 1; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}