/*
Proposta: Criar um programa em C que receba a temperatura média de cada mês do ano, em graus
centígrados, e armazene essas temperaturas em um vetor. Imprimir as temperaturas de todos os
meses, maior e a menor temperatura do ano e em que mês aconteceram. Suponha que não há meses
com temperaturas iguais
*/

#include <stdio.h>

int main(){
	
    float temp[5];
    int i, maior_temp, menor_temp;
    
    printf("Informe a temperatura media em cada mes do ano\n");
    for (i = 0; i < 5; i++) {
        printf("Mes %02d: ", i + 1);
        scanf("%f", &temp[i]);
    }
    
    printf("\nTemperaturas medias em cada mes do ano\n");
    maior_temp = menor_temp = 0;
    
    for (i = 0; i < 5; i++) {
        printf("Mes %02d: %.1f C\n", i + 1, temp[i]);
        if (temp[i] > temp[maior_temp]) {
            maior_temp = i;
        }
        else if (temp[i] < temp[menor_temp]) {
            menor_temp = i;
        }
    }
    
    printf("Mes com maior temperatura: %02d (%.1f C)\n", 
           maior_temp + 1, temp[maior_temp]);
    printf("Mes com menor temperatura: %02d (%.1f C)\n", 
           menor_temp + 1, temp[menor_temp]);
    return 0;
}
