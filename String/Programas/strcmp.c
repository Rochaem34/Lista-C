#include <stdio.h>
#include <string.h>

int main() {
	char tentativa[21];
	char resposta[] = "Cabral";
	printf("Quem descobriu o Brasil? ");
	scanf(" %20[^\n]", tentativa);	
	while (strcasecmp(tentativa, resposta) != 0) {
		puts("Nao, esta' errado. Tente novamente");
		scanf(" %20[^\n]", tentativa);
	}
	puts("Esta' certo!");
	return 0;
}
