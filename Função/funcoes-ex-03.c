#include <stdio.h>

void aleatorio(int, int);

int main()
{
    int n, m;
    printf("Informe o tamanho da matriz: ");
    scanf("%d %d", &n, &m);
    aleatorio(n, m);
    printf("\n");
    printf("Matriz de %dx%d", n, m);
    return 0;
}

void aleatorio(int l, int c)
{
	int i, j;
	
	srand(0);
	
    for(i = 1; i <= l; i++) {
        for (j = 1; j <= c; j++) {
            printf("%d ", rand() % l*c*10);
        }
        printf("\n");
    }
}
