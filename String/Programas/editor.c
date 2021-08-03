/* Vetor de strings */

#include <stdio.h>

int main()
{
    char linhas[30][121];
    int i = 0, j;
    do {
        fgets(linhas[i], 121, stdin);
        if (linhas[i][0] == '\n') {
            break;
        }
        i++;
    } while (i < 30);

    for (j = 0; j < i; j++) {
        printf("%02d %s", j + 1, linhas[j]);
    }
    return 0;
}