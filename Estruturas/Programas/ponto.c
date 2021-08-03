#include <stdio.h>

typedef struct {
    int x;
    int y;
} ponto;

void imprime_ponto(int, int);
void imprime_ponto2(ponto);
void recebe_ponto(ponto *);
ponto recebe_ponto2(void);

int main()
{
    ponto p;
    /*
    printf("Informe as coordenadas do ponto: ");
    scanf("%d %d", &p.x, &p.y);
    */
    //recebe_ponto(&p);
    p = recebe_ponto2();
    //imprime_ponto(p.x, p.y);
    imprime_ponto2(p);
    return 0;
}

ponto recebe_ponto2()
{
    ponto pto;
    printf("Informe as coordenadas do ponto: ");
    scanf("%d %d", &pto.x, &pto.y);
    return pto;
}

void recebe_ponto(ponto * ppto)
{
    printf("Informe as coordenadas do ponto: ");
    //scanf("%d %d", &(*ppto).x, &(*ppto).y);
    scanf("%d %d", &ppto->x, &ppto->y);
}

void imprime_ponto2(ponto pto)
{
    printf("Coordenadas do ponto: (%d, %d)\n", pto.x, pto.y);
}

void imprime_ponto(int x, int y)
{
    printf("Coordenadas do ponto: (%d, %d)\n", x, y);
}