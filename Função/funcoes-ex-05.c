/*
5. Faça uma função que recebe por parâmetro o raio de uma esfera (um int ) e calcula e devolve
o seu volume ( 4pR 3 /3).
*/

#include <stdio.h>
#include <math.h>

double volume(int);

int main()
{
    int raio;
    printf("Informe o raio da esfera: ");
    scanf("%d", &raio);
    printf("Volume da esfera: %.4lf\n", volume(raio));
    return 0;
}

double volume(int r)
{
    return (4 * M_PI * pow(r, 3)) / 3;
}