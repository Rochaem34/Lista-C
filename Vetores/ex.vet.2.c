/*
Proposta: Escreva um programa que dada uma sequência de "n" números inteiros, 
imprimi-los em ordem inversa.
*/

#include <stdio.h>

int main(){
	
	int n;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);
	int seq[n], i;
	
	printf("\nInforme a sequencia dos numeros(de acordo com o tamanho do vetor): \n");
	for(i = 0; i < n; i++){
		scanf("%d", &seq[i]);
	}
	
	printf("\nSequecia dos numeros na ordem inversa: \n");
	for(i = n - 1; i >= 0; i--){
		printf("%d ", seq[i]);
	}
	printf("\n");
	return 0;
}
