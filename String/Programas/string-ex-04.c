/*
4. Escreva um programa que receba uma string do teclado e informe se ela é palíndromo ou
não. Uma string é palíndromo quando pode ser lida tanto de trás para frente quanto de frente
para trás e possui exatamente a mesma sequência de caracteres. Por exemplo: “ASA”,
1“SUBI NO ONIBUS”. Desconsidere os espaços.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[81], inverso[81];
    int i, j;

    printf("Informe uma string: ");
    scanf(" %80[^\n]", str);

    // procura um espaço na string
    for (i = 0; str[i] != ' ' && str[i] != '\0'; i++);

    // retira os espaços em branco da string
    if (str[i] == ' ') {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[j] != ' ') {
                str[i++] = str[j];
            }
        }
        str[i] = '\0';
    }

    // gera o inverso da string
    for (i--, j = 0; i >= 0; i--, j++) {
        inverso[j] = str[i];
    }
    inverso[j] = '\0';

    if (strcasecmp(str, inverso) == 0) {
        printf("%s e' um palindromo\n", str);
    }
    else {
        printf("%s NAO e' um palindromo\n", str);
    }
    return 0;
}