#include <stdio.h>

int main()
{
    int dia, mes, ano;
    char * meses[] = { "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", 
                       "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };
    scanf("%2d%2d%4d", &dia, &mes, &ano);
    printf("%02d/%s/%d\n", dia, meses[mes - 1], ano);
    return 0;
}