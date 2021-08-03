#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Erro de sintaxe!\nDigite: %s <nome-do-arquivo>\n", argv[0]);
        return 1;
    }
    FILE * arq;
    char linha[121];
    if ((arq = fopen(argv[1], "a+")) == NULL) {
        fprintf(stderr, "Erro de abertura do arquivo %s!\n", argv[1]);
        return 2;
    }
    // lendo do arquivo e escrevendo no vídeo
    while (fgets(linha, 121, arq) != NULL) {
        fputs(linha, stdout);
    }

    // lendo do teclado e escrevendo no arquivo
    while (1) {
        fgets(linha, 121, stdin);
        if (linha[0] == '\n') {
            break;
        }
        fputs(linha, arq);
    }

    rewind(arq); // volta o indicador de posição para o início do arquivo
    // lendo do arquivo e escrevendo no vídeo
    while (fgets(linha, 121, arq) != NULL) {
        fputs(linha, stdout);
    }

    fclose(arq);
    return 0;
} 
/* Comentario feito pelo meu editor de texto */
