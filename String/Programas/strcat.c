#include <stdio.h>
#include <string.h>

int main() {
	char flor[41];
	char sufixo[] = " cheira como sapato velho";
	printf("Qual sua flor favorita? ");
	scanf(" %40[^\n]", flor);
	strncat(flor, sufixo);
	puts(flor);
	return 0;
}
