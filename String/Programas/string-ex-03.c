/*
3. Escreva um programa que receba uma linha de texto, conte as vogais e apresente o
histograma da frequência de cada uma delas. Considere que a linha de texto não contém
acentuação. Por exemplo:
Linha de texto: “Os ultimos Jogos Olimpicos foram no Brasil”
Histograma:
a: ** (2)
e: (0)
i: **** (4)
o: ******** (8)
u: * (1)
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto[121], vogais[] = "aeiou", letra;
    int i, j, cont[5] = { 0 };

    printf("Informe o texto: ");
    scanf(" %120[^\n]", texto);

    for (i = 0; texto[i] != '\0'; i++) {
        letra = tolower(texto[i]);
        for (j = 0; j < 5; j++) {
            if (letra == vogais[j]) {
                cont[j]++;
                break;
            }
        }
    }

    printf("\nHistrograma de frequencia das vogais\n");
    for (i = 0; i < 5; i++) {
        printf("%c: ", vogais[i]);
        for (j = 1; j <= cont[i]; j++) {
            putchar('*');
        }
        printf(" (%d)\n", cont[i]);
    }
    return 0;
}