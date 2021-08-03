#include <stdio.h>

struct ponto {
    int x;
    int y;
};

struct circulo {
    struct ponto centro;
    int raio;
};

struct cilindro {
    struct circulo base;
    int altura;
};

int main()
{
    struct circulo c = { { 2, 4 }, 5 };
    struct ponto p = { 0, 2 };
    struct cilindro cil = { { {1, 1 }, 4 }, 10 };
    printf("Circulo -> centro: (%d, %d) - raio: %d\n", c.centro.x, c.centro.y, c.raio);
    printf("Ponto -> (%d, %d)\n", p.x, p.y);
    printf("Cilindro -> base: (%d, %d), %d - altura: %d\n",
           cil.base.centro.x, cil.base.centro.y, cil.base.raio, cil.altura);
    return 0;
}