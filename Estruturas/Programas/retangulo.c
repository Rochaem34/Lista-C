/*
Considere a estrutura ponto e implemente uma função que indique se um dado ponto p
está localizado dentro ou fora de um retângulo r. O retângulo é definido por 2 pontos, seus
vértices superior esquerdo e inferior direito. Defina um tipo retangulo e implemente uma
função que devolve true caso o ponto esteja localizado dentro do retângulo, ou false caso
contrário. Essa função deve obedecer ao protótipo:
bool dentro_ret(retangulo r, ponto p);
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} ponto;

typedef struct {
    ponto vid; // vértice inferior direito
    ponto vse; // vértice superior esquerdo
} retangulo;

bool dentro_ret(retangulo, ponto);

int main()
{
    ponto p;
    retangulo r;
    printf("Informe as coordenadas do ponto: ");
    scanf("%d %d", &p.x, &p.y);
    printf("\nCoordenadas do vertice superior esquerdo do retangulo: ");
    scanf("%d %d", &r.vse.x, &r.vse.y);
    printf("Coordenadas do vertice inferior direito do retangulo: ");
    scanf("%d %d", &r.vid.x, &r.vid.y);

    if (dentro_ret(r, p)) {
        puts("O ponto esta' dentro do retangulo");
    }
    else {
        puts("O ponto esta' fora do retangulo");
    }
    return 0;
}

bool dentro_ret(retangulo r, ponto p)
{
    return (p.x >= r.vse.x && p.x <= r.vid.x) 
           && (p.y <= r.vse.y && p.y >= r.vid.y);
}