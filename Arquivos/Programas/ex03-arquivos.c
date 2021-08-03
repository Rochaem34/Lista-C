/*
3. Escreva um programa que recebe dois valores via argumentos da função main(). O primeiro
é uma string e o segundo o nome de um arquivo do tipo texto. O programa deve percorrer o
arquivo imprimindo no vídeo todas as linhas que contêm a string (comportamento
semelhante ao comando grep do Linux). Use a função strstr() para procurar a palavra em
uma linha.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if (argc != 3) {
        fprintf(stderr, "\nErro: sintaxe incorreta!\nDigite: %s <texto> <nome-arquivo>\n", argv[0]);
        return 1;
    }
    FILE * arq;
    char linha[121];
    if ((arq = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "\nErro: arquivo nao encontrado (%s)!\n", argv[2]);
        return 1;
    }
    while (fgets(linha, 121, arq) != NULL) {
        if (strstr(linha, argv[1]) != NULL) {
            printf("%s", linha);
        }
    }
    fclose(arq);
    return 0;
}