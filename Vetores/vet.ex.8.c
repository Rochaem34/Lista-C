/*
12. Calcular o valor do polinômio p(x) = a 0 x 0 + a 1 x 1 + ... + a n x n em k pontos distintos. São dados os
valores de n (grau do polinômio), de a 0 , a 1 , ..., a n (coeficientes reais do polinômio), de k e dos
pontos x 1 , x 2 , ..., x k .
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, i, j;
    printf("Informe o grau do polinomio: ");
    scanf("%d", &n);
    printf("Informe o numero de pontos: ");
    scanf("%d", &k);

    double coef[n + 1], pontos[k], polin[k];

    printf("Informe os coeficientes do polinomio:\n");
    for (i = 0; i < n + 1; i++) {
        printf("a(%d) = ", i);
        scanf("%lf", &coef[i]);
    }

    printf("Informe os %d pontos:\n", k);
    for (i = 0; i < k; i++) {
        printf("x(%d) = ", i + 1);
        scanf("%lf", &pontos[i]);
    }

    printf("\nValor dos polinomios\n");
    for (i = 0; i < k; i++) {
        polin[i] = 0;
        for (j = 0; j < n + 1; j++) {
            polin[i] += coef[j] * pow(pontos[i], j);
        }
        printf("p(%d) = %.2lf\n", i, polin[i]);
    }

    return 0;
}