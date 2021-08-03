/*
22. Implemente um programa em C que exibe um triângulo de Pascal de ordem n, para 1 < n  20.
Considere uma matriz quadrada de ordem n, o triângulo de Pascal segue a seguinte regra de
formação:
a) todos os elementos da primeira coluna da matriz são iguais a 1;
b) todos os elementos da diagonal principal da matriz também são iguais a 1;
c) para os demais elementos são obtidos pela soma do elemento da mesma coluna na linha de
cima com o seu vizinho esquerdo;
d) os elementos acima da diagonal principal não são exibidos.
Abaixo é mostrado um triângulo de Pascal de ordem 5:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Informe a ordem do triangulo de Pascal: ");
    scanf("%d", &n);
    while (n <= 1 || n > 20) {
        printf("Erro: a ordem do triangulo de Pascal deve ser um valor em 2 e 20!\n");
        printf("Informe a ordem do triangulo de Pascal: ");
        scanf("%d", &n);
    }
    int pascal[n][n], i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
    }
    printf("\nTriangulo de Pascal de ordem %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d\t", pascal[i][j]);
        }
        printf("\n");
    }
    return 0;
}