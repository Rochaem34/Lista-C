/* my_math.c */

#include <math.h>

long long fatorial(int n)
{
    long long f = 1;
    for (int i = n; i >= 1; i--) {
        f *= i;
    }
    return f;
}

int arredondar_para_int(double n)
{
    return (int) floor(n + 0.5);
}

double arredondar(double n, int c)
{
    return arredondar_para_int(n * pow(10, c)) / pow(10, c);
}