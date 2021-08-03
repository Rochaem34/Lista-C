/*
1. Escreva um programa que recebe o nome de dois arquivos do tipo texto via argumentos da
função main(). O programa deve gerar uma cópia o primeiro arquivo no segundo, entretanto,
todos os caracteres do segundo arquivo devem estar em letras maiúsculas. Use a função
toupper() do ctype.h para converter todos os caracteres para maiúsculo e gravá-los no
segundo arquivo.
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    if (argc != 3) {
        fprintf(stderr, "\nErro: sintaxe incorreta!\nDigite: %s <arq_original> <copia>\n", argv[0]);
        return 1;
    }
    FILE * in, * out;
    char ch;
    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "\nErro: arquivo nao encontrado (%s)!\n", argv[1]);
        return 1;
    }
    if ((out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel criar o arquivo %s!\n", argv[2]);
        fclose(in);
        return 2;
    }
    while ((ch = fgetc(in)) != EOF) {
        ch = toupper(ch);
        fputc(ch, out);
    } 
    fclose(in);
    fclose(out);
    return 0;
}