/*
5. Escreva um programa que receba uma string str, um inteiro p e um caractere ch, e insere o
caractere ch na posição p da string str. Se p for maior que o tamanho da string str, exiba uma
mensagem. Por exemplo, str = “programacao”, p = 3 e ch = 's', a string str passaria a ser
“prosgramacao”.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[81], ch;
    int p, tam;

    printf("Informe uma string: ");
    scanf(" %80[^\n]", str);
    printf("Informe um caractere: ");
    scanf(" %c", &ch);
    printf("Posicao da insercao do caractere %c: ", ch);
    scanf("%d", &p);
    tam = strlen(str);
    if (p <= tam) {
        for (int i = tam; i >= p; i--) {
            str[i + 1] = str[i];
        }
        str[p] = ch;
        printf("\nString apos a insercao de %c na posicao %d: %s\n", ch, p, str);
    }
    else {
        printf("Erro: posicao da insercao invalida!\n");
    }
    return 0;
}