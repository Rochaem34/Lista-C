/*
Desafio:Problema Criptografia (1024) do URI Online Judge
(https://www.urionlinejudge.com.br/judge/pt/problems/view/1024)
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, k;
	char str[1001], ch;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf(" %[^\n]", str);
		/* desloca 3 caracteres para frente as letras maiúsculas e minúsculas */ 
		for (j = 0; str[j] != '\0'; j++) {
			if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')) {
				str[j] += 3;
			}
		}
		/* inverte a string */
		for (j--, k = 0; j > k; j--, k++) {
			ch = str[j];
			str[j] = str[k];
			str[k] = ch; 
		}
		/* desloca um caractere para trás os caracteres da metade da string em diante */
		for (j = strlen(str) / 2; str[j] != '\0'; j++) {
			str[j]--;
		}
		puts(str);
	}
	return 0;
}