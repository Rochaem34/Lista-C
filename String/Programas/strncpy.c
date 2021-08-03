#include <stdio.h>
#include <string.h>

int main() {
	char palavra[21], copia[21];
	int n;
	printf("Digite uma palavra: ");
	scanf(" %20[^\n]", palavra);
	printf("Quantas letras quer copiar? ");
	scanf("%d", &n);
	strncpy(copia, palavra, n);
	copia[n] = '\0';
	printf("Copia da palavra: %s\n", copia);
	return 0;
}
