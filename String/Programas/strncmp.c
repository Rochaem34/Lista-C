#include <stdio.h>
#include <string.h>

int main() {
	char tentativa[21];
	printf("Digite uma palavra comecando com para: ");
	scanf(" %20[^\n]", tentativa);
	while (strncasecmp(tentativa, "para", 4) != 0) {
		puts("Nao, esta' errado. Tente novamente");
		scanf(" %20[^\n]", tentativa);
	}
	printf("Palavra aceita: %s\n", tentativa);
	return 0;
}
