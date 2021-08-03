/*
2)Criar uma função em C que receba um número
decimal e converta-o para binário. Obs.: O
parâmetro passado na cham
*/

#include <stdio.h>

void dec2bin(long long *);

int main()
{
    long long num;
    printf("Informe um numero positivo na base decimal: ");
    scanf("%Ld", &num);
    dec2bin(&num);
    printf("Numero na base binaria: %Ld\n", num);
    return 0;
}

void dec2bin(long long * pnum)
{
    long long dec = *pnum, pot10 = 1;
    *pnum = 0;
    while (dec > 0) {
        *pnum += (dec % 2) * pot10;
        dec /= 2;
        pot10 *= 10;
    }
}