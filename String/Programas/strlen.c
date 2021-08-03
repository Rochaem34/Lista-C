#include <stdio.h>
#include <string.h>

int main() {
	char str[41];
	int comp;
	printf("Informe uma string: ");
	scanf(" %40[^\n]", str);
	comp = strlen(str);
	printf("A string tem %d caracteres\n", comp);
	return 0;
}
