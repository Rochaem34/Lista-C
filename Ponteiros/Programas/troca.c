#include <stdio.h>

void troca(int *, int *);

int main() 
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    troca(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

void troca(int * pa, int * pb) 
{
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}