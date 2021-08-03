/*
Proposta: Desenvolva um programa que dada uma sequência de 8 números inteiros 
depois imprima todos os números pares digitados.

*/

#include <stdio.h>

int main(){
	
	int vet[8], i;
	printf("Informe todos os numeros inteiros (maximo 8 digitos): ");
	for(i = 0; i < 8; i++){
		scanf("%d", &vet[i]);
	}
	printf("\nOs numeros pares sao: ");
	for(i = 0; i < 8; i++){
		if(vet [i] % 2 == 0){
			printf("%d ", vet[i]);
		}
	}
	return 0;
}
