/*
6. Escreva um programa que receba uma string de 0s e 1s, interprete essa string como um
número binário e informe o valor desse número na base decimal.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char binario[21];
    int decimal = 0, pot2 = 1;

    printf("Informe um numero binario: ");
    scanf(" %20[0-1]", binario);

    for (int i = strlen(binario) - 1; i >= 0; i--) {
        decimal += (binario[i] - '0') * pot2;
        pot2 *= 2;
    }

    printf("\n%s convertido para decimal: %d\n", binario, decimal);
    return 0;
}