#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc != 3) {
        printf("Erro de sintaxe!\nPara executar digite: %s <arq_origem> <arq_destino>\n", argv[0]);
        return 1;
    }
    FILE * in, * out;
    int b;
    if ((in = fopen(argv[1], "rb")) == NULL) {
        printf("Erro: arquivo nao encontrado (%s)!\n", argv[1]);
        return 2;
    }
    if ((out = fopen(argv[2], "wb")) == NULL) {
        printf("Erro: nao foi possivel criar o arquivo %s!\n", argv[2]);
        fclose(in);
        return 3;
    }
    
    while (1) {
        b = fgetc(in);
        if (feof(in)) {
            break;
        }
        fputc(b, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}