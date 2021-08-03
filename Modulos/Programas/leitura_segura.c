#include <stdio.h>
/*
#include <stdbool.h>

bool read_int(int *);
void read_line(char *, int);
*/

#include "my_io.h"

int main()
{
    int n;
    char str1[11], str2[11];

/*
    scanf("%d", &n);
    while (n > 10) {
        printf("n: ");
        scanf("%d", &n);
    }
*/
    while (!read_int(&n) || n > 10) {
        printf("n: ");
    }
    /*
    scanf(" %10[^\n]", str1);
    scanf(" %10[^\n]", str2);
    */
    read_line(str1, 10);
    read_line(str2, 10);
    printf("n = %d, str1 = %s, str2 = %s\n", n, str1, str2);
    return 0;
}