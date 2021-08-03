/*
9. Escreva uma função de protótipo void somabit(int b1, int b2, int * vaium, int
* soma); que recebe três bits (inteiros entre 0 e 1) b1, b2, e *vaium e devolve um bit *soma
representando a soma dos três bits e um novo bit “vai-um” em *vaium.

10. Escreva um programa que leia dois números binários e calcula um número binário que é a soma
dos dois números dados. Utilize a função do exercício anterior.
*/

#include <stdio.h>

void somabit(int, int, int *, int *);

int main()
{
    int bin1, bin2, b1, b2, vai1 = 0, soma, resultado = 0, pot10 = 1;
    printf("Informe 2 numeros binarios: ");
    scanf("%d %d", &bin1, &bin2);
    while (bin1 > 0 || bin2 > 0 || vai1 > 0) {
        b1 = bin1 % 10;
        b2 = bin2 % 10;
        somabit(b1, b2, &vai1, &soma);
        resultado += soma * pot10;
        bin1 /= 10;
        bin2 /= 10;
        pot10 *= 10;
    }
    printf("Resultado da soma: %d\n", resultado);
    return 0;
    
}

void somabit(int b1, int b2, int * vaium, int * soma)
{
    *soma = b1 + b2 + *vaium;
    *vaium = *soma / 2;
    *soma %= 2;
}
