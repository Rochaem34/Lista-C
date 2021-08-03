/*
2. Criar um programa que dados 3 números inteiros, utilize uma função do tipo void que
imprima o maior desses números.
*/

#include <stdio.h>

void maior3(int, int, int);

int main()
{
    int n1, n2, n3;
    printf("Informe 3 numeros inteiros: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    maior3(n1, n2, n3);
    return 0;
}

void maior3(int a, int b, int c)
{
    int maior;
    if (a > b && a > c) {
        maior = a;
    }
    else {
        if (b > c) {
            maior = b;
        }
        else {
            maior = c;
        }
    }
    printf("Maior: %d\n", maior);
}