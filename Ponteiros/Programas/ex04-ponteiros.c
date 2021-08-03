#include <stdio.h>

void conversor_tempo(int , int *, int *, int *);

int main()
{
    int temp, horas, minutos, segundos;
    printf("Informe um tempo em Segundos: ");
    scanf("%d", &temp);
    conversor_tempo(temp, &horas, &minutos, &segundos);
    printf("O tempo informado em formato horas, minutos e segundos: %02d:%02d:%02d\n", 
           horas, minutos, segundos);
    return 0;
}

void conversor_tempo(int temp, int * ph, int * pmin, int * pseg)
{
    *ph = temp / 3600;
    *pmin = (temp % 3600) / 60;
    *pseg = (temp % 3600) % 60;
}