/*
11. Dada uma sequência de n números inteiros, determinar qual é a maior subsequência crescente
nesta sequência. Por exemplo, seja n = 8, a sequência 5, 7, -1, 0 , 3, 6, 6, 4, então a maior
sequência crescente é -1, 0, 3, 6.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Informe o tamanho da sequencia: ");
    scanf("%d", &n);
    int seq[n], i, pos_maior, pos_atual, tam_maior, tam_atual;

    printf("Informe a sequencia de %d valores: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    pos_atual = pos_maior = 0;
    tam_atual = tam_maior = 1;
    for (i = 1; i < n; i++) {
        if (seq[i] > seq[i - 1]) {
            tam_atual++;
            if (tam_atual > tam_maior) {
                tam_maior = tam_atual;
                pos_maior = pos_atual;
            }
        }
        else {
            pos_atual = i;
            tam_atual = 1;
        }
    }
    printf("\nMaior sequencia crescente: ");
    for (i = pos_maior; i < pos_maior + tam_maior; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
    return 0;
}