/*
1)Criar uma função em C que receba como
parâmetro o valor de um ângulo em radianos e
converta-o para graus. Obs.: O parâmetro
passado na chamada à função deve ser
alterado para graus.
Dica: graus = radianos*180/ π .
*/    

#include<stdio.h>
#include<math.h>
 
void rad2graus(double *);
 
int main()
{ 
    double angulo;
 
    printf ("\nDigite o valor em radianos: ");
    scanf ("%lf", &angulo);
    rad2graus(&angulo);
    printf("Angulo em graus: %lf\n", angulo);
    return 0;
}

void rad2graus(double * pang)
{
    *pang = *pang * 180 / M_PI;
}