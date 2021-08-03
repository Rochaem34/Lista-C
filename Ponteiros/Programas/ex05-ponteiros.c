#include <stdio.h>
#include <math.h>

void funcao_raio(float, float *, float *, float *);

int main()
{
    float raio, diametro, perimetro, area;

    printf("Digite o raio de uma circunferencia: ");
    scanf("%f", &raio);

    funcao_raio(raio, &diametro, &perimetro, &area);

    printf("Essa circunferencia tem %f de diametro, %f de perimetro e %f de area\n", 
           diametro, perimetro, area);

    return 0;
}
void funcao_raio(float r, float * pdiametro , float * pperimetro, float * parea)
{
    *pdiametro = 2 * r;
    *pperimetro = 2 * M_PI * r;
    *parea =  M_PI * pow(r , 2);
}