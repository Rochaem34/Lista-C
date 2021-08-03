#include <stdio.h>
#include <string.h>

int main() 
{
	char palavra[21], copia[21];
	printf("Digite uma palavra: ");
	scanf(" %20[^\n]", palavra);
	strcpy(copia, palavra);
	printf("Copia da palavra: %s\n", copia);
	return 0;
}
