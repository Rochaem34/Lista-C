/*
20. Escreva uma função que recebe um inteiro m e devolve true (verdadeiro) se m é primo ou
false (falso), caso contrário.

21. Escreva um programa que receba um número inteiro não-negativo n e imprima os n primeiros
números primos. Utilize os parâmetros da main() para receber o valor de n e a função da
questão anterior.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool primo(int);

int main(int argc, char * argv[])
{
    if (argc != 2) {
        printf("Erro de sintaxe!\nDigite: %s <int>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int primos = 0, i = 1;
    printf("%d primeiros numeros primos: ", n);
    while (primos < n) {
        if (primo(i)) {
            printf("%d ", i);
            primos++;
        }
        i++;
    }
    printf("\n");
    return 0;
}

bool primo(int n)
{
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}