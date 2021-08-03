/*
Considere a estrutura struct circulo definida anteriormente e escreva um
programa que dados dois círculos, verifique se eles se sobrepõem. Dois
círculos se sobrepõem se a distância entre os centros destes círculos é menor
que a soma de seus raios.
*/
#include <stdio.h>
#include <math.h>

struct ponto {
    int x;
    int y;
};

struct circulo {
    struct ponto centro;
    int raio;
};

int main (){
    struct circulo a, b;
    double distancia;
    
    printf("Insira as coordenadas do centro e o raio do 1o. circulo: ");
    scanf("%d %d %d", &a.centro.x, &a.centro.y, &a.raio);
    printf("Insira as coordenadas do centro e o raio do 2o. circulo: ");
    scanf("%d %d %d", &b.centro.x, &b.centro.y, &b.raio);

    distancia = sqrt(pow((a.centro.x - b.centro.x), 2) + pow((a.centro.y - b.centro.y), 2));

    if (distancia < (a.raio + b.raio)){
        printf("Os circulos se sobrepoem\n");
    }
    else {
        printf("Os circulos NAO se sobrepoem\n");
    }
    return 0;
}