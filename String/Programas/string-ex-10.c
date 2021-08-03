/*
10. Escreva um programa que dados um inteiro n e um caractere ch, solicite que o usuário
informe n palavras que começam com a letra ch. Se o usuário informar alguma palavra que
não comece com a letra ch, o programa deve exibir uma mensagem informando que a
palavra não começa com a letra ch. No final o programa deve exibir as n palavras digitadas
pelo usuário que começam com a letra ch.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    char ch;
    printf("Informe o numero de palavras: ");
    scanf("%d", &n);
    printf("Informe um caractere: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    char palavras[n][41];

    printf("Informe %d palavras que comecam com a letra %c:\n", n, ch);
    for (int i = 0; i < n; i++) {
        printf("%da. palavra: ", i + 1);
        scanf(" %40[^\n]", palavras[i]);
        if (toupper(palavras[i][0]) != ch) {
            printf("%s nao comeca com a letra %c!\n", palavras[i], ch);
            i--;
        }
    }

    printf("\nPalavras aceitas:\n");
    for (int i = 0; i < n; i++) {
        puts(palavras[i]);
    }
    return 0;
}