/*
Proposta: Desenvolva um programa para armazenar n n�meros inteiros em um vetor
e depois imprimir uma mensagem informando se os n�meros est�o em ordem crescente ou n�o.
*/

#include <stdio.h>

int main(){
	
	int n, vet[n], i;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);
	
	printf("Informe a sequencia do vetor: \n");
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
	for(i = 1; i < n; i++){
		if(vet[i] < vet[i - 1]){
		break;
		}
	}
	if(i < n){
		printf("\nO numero NAO  esta' em ordem crescente.");
	}
	else{
		printf("\nO numero ESTA em ordem crescente.");
	}
	return 0;
}
