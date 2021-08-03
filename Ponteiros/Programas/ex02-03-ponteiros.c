/*
2. Escreva uma função que receba como parâmetro uma distância em metros e devolva, também
através de seus parâmetros, essa distância em polegadas, jardas e milhas.
Metro Polegadas Jardas Milhas
 1,0    39,37   1,0936 0,00062

 3. Escreva um programa que dada uma sequência de distâncias em metro, informe essas distâncias
em polegadas, jardas e milhas. O programa deve terminar quando for informada uma distância
zero. Utilize a função do exercício anterior.
*/

#include <stdio.h>

void conversor_distancias(double, double *, double *, double *);

int main()
{
    double metros, polegadas, jardas, milhas;
    
    printf("Digite a distancia em metros: ");
    scanf("%lf", &metros);
    while (metros != 0) {

        conversor_distancias(metros, &polegadas, &jardas, &milhas);

        printf("A distancia informada em outras medidas e':\n%lf polegadas\n%lf jardas\n%lf milhas\n", 
            polegadas, jardas, milhas);

        printf("\nDigite a distancia em metros (0 p/ encerrar): ");
        scanf("%lf", &metros);
    }
    return 0;
}

void conversor_distancias(double pm, double * pp, double * pj, double * pmi)
{
    *pp = pm * 39.37; // 39.37 polegadas equivale a 1 metro
    *pj = pm * 1.0936; // 1.0936 jardas equivale a 1 metro
    *pmi = pm * 0.00062; // 0.00062 milhas equivale a 1 metro
}