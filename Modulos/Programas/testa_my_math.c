/* testa_my_math.c */

#include <stdio.h>
#include "my_io.h"
#include "my_math.h"

int main()
{
    double num;
    int precisao, n;
    printf("Digite um numero natural menor 25: ");
    while (!read_int(&n) || n < 0 || n >= 25) {
        printf("Digite um numero natural menor 25: ");
    }
    printf("%d! = %Ld\n", n, fatorial(n));
    printf("Digite um numero real: ");
    while  (!read_double(&num)) {
        printf("Digite um numero real: ");
    }
    printf("%lf arredondado para o inteiro mais proximo: %d\n",
           num, arredondar_para_int(num));
    printf("\nDigite a precisao do arrendondamento (1-10): ");
    while (!read_int(&precisao) || precisao < 1 || precisao > 10) {
        printf("\nDigite a precisao do arrendondamento (1-10): ");
    }
    printf("%lf arredondado com precisao %d: %lf\n",
           num, precisao, arredondar(num, precisao));
    return 0;
}