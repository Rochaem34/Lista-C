#include <stdio.h>

int main()
{
    int n;
    char str1[11], str2[11];

    scanf("%d", &n);
    while (n > 10) {
        printf("n: ");
        scanf("%d", &n);
    }
    scanf(" %10[^\n]", str1);
    scanf(" %10[^\n]", str2);
    printf("n = %d, str1 = %s, str2 = %s\n", n, str1, str2);
    return 0;
}