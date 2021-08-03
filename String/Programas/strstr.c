#include <stdio.h>
#include <string.h>

int main() {
	char str1[21], str2[21];
	printf("Digite duas palavras: ");
	scanf(" %20[^\n] %20[^\n]", str1, str2);
	if (strstr(str1, str2) != NULL) {
		printf("%s ocorre em %s\n", str2, str1);
	}
	else {
		printf("%s NAO ocorre em %s\n", str2, str1);
	}
	return 0;
}
