/*
8. Escreva uma função de protótipo int num_ocorrencias(const char * frase, const
char * palavra); que devolve o número de vezes que a palavra ocorre na frase. Exemplo:
para a palavra “ANA” e a frase: “ANA E MARIANA GOSTAM DE BANANA”. Temos que a
palavra ocorre 4 vezes na frase. Use a notação de ponteiros para percorrer as strings.
*/

#include <stdio.h>
#include <string.h>

int num_ocorrencias(const char *, const char *);

int main()
{
    char frase[121], palavra[21];
    printf("Informe uma frase: ");
    scanf("%120[^\n]", frase);
    printf("Informe uma palavra: ");
    scanf(" %20[^\n]", palavra);
    int n = num_ocorrencias(frase, palavra);
    if (n > 0) {
        printf("A palavra ocorre na frase %d vez(es)\n", n);
    }
    else {
        puts("A palavra nao ocorre na frase");
    }
    return 0;
}

int num_ocorrencias(const char * frase, const char * palavra)
{
    int cont = 0;
    while (*(frase) != '\0' && (frase = strstr(frase, palavra)) != NULL) {
        cont++;
        frase++;
    }
    return cont;
}