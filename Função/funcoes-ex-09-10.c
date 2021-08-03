/*
9. Escreva uma função para calcular o fatorial de um número natural.

10. Considere a função para calcular o fatorial de um número natural implementado na questão
anterior e escreva um programa que recebe dois números naturais (n e k) como parâmetros da
função main() e calcula e imprime:
a) O número de permutação P n : P n =n !
b) O número de arranjos A n,k : A n , k = n!/(n−k) !
c) O número de combinações C n,k : C n , k =  n! / k !∗(n−k)!
*/

#include <stdio.h>
#include <stdlib.h>

long long fat(int);

int main(int argc, char * argv[])
{
    if (argc != 3) {
        printf("Erro de sintaxe!\nDigite: %s <int> <int>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]), k = atoi(argv[2]);

    long long perm = fat(n);
    long long arranjos = fat(n) / fat(n - k);
    long long comb = fat(n) / (fat(k) * fat(n - k));

    printf("Permutacoes de %d: %Ld\n", n, perm);
    printf("Arranjos de %d em grupos de %d elementos: %Ld\n", n, k, arranjos);
    printf("Combinacoes de %d em grupos de %d elementos: %Ld\n", n, k, comb);
    return 0;
}

long long fat(int n)
{
    long long f = 1;
    for (int i = n; i >= 1; i--) {
        f *= i;
    }
    return f;
}