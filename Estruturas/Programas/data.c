#include <stdio.h>

struct data {
    int dia;
    char mes[10];
    int ano;
};

int main()
{
    struct data natal = { .ano = 2021, .mes = "Maio" };
    printf("dia = %d, mes = %s, ano = %d\n", natal.dia, natal.mes, natal.ano);
    return 0;
}