/*
2)Escreva um programa que dadas duas strings, exiba-as em ordem alfabética.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[51], str2[51];
    printf("Informe 2 strings:\n");
    scanf(" %50[^\n] %50[^\n]", str1, str2);
    printf("\nStrings em ordem alfabetica:\n");
    if (strcasecmp(str1, str2) < 0) {
        printf("%s\n%s\n", str1, str2);
    }
    else {
        printf("%s\n%s\n", str2, str1);
    }
    return 0;
}