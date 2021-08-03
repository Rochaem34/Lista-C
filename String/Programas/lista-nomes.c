/* Vetor de strings */

#include <stdio.h>
#include <ctype.h>

int main()
{
    char nomes[20][81];
    char primeiro;
    int i = 0, j;
    printf("Informe uma lista de ate' 20 nomes (Enter p/ encerrar):\n");
    do {
        fgets(nomes[i], 81, stdin);
        if (nomes[i][0] == '\n') {
            break;
        }
        i++;
    } while (i < 20);

    printf("\nNomes que comecam com as letras de A a J:\n");
    for (j = 0; j < i; j++) {
        primeiro = toupper(nomes[j][0]); // primeiro caractere me maiúsculo
        if (primeiro >= 'A' && primeiro <= 'J') {
            printf("%s", nomes[j]);
        }        
    }
    return 0;
}