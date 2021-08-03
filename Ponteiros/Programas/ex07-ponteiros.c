/*
7. Escreva uma função de protótipo char * strupper(char * str); que converte todos os
caracteres de str para maiúsculo e devolve a string convertida. Use a notação de ponteiros para
percorrer a string str. Faça um programa que receba uma string do teclado e imprime essa string
com todas as letras em maiúsculo (use a função strupper).
*/

#include <stdio.h>
#include <ctype.h>

char * strupper(char *);

int main()
{
    char str[41];
    printf("Informe uma string: ");
    scanf("%40[^\n]", str);
    printf("Maiuscula: %s\n", strupper(str));
    printf("Maiuscula: %s\n", str);
    return 0;
}

char * strupper(char * s)
{
    for (int i = 0; *(s + i) != '\0'; i++) {
        *(s + i) = toupper(*(s + i));
    }
    return s;
}