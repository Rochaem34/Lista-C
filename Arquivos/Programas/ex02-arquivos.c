/*
2. Escreva um programa para criptografar e descriptografar um arquivo do tipo texto usando a
cifra de César (https://pt.wikipedia.org/wiki/Cifra_de_César). O programa deve receber
como argumentos da função da main() o nome do arquivo a ser criptografado ou
descriptografado, -c (criptografar) ou -d (descriptografar) e a chave (rotação).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	if (argc != 4) {
		fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <arquivo> <-c|-d> <chave>\n", 
		        argv[0]);
		return 1;
	}
	FILE * in, * out;
	int chave;
	char ch;
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Erro: não foi possível abrir o arquivo %s!\n", argv[1]);
		return 2;
	}
	if ((out = fopen("saida.txt", "w")) == NULL) {
		fprintf(stderr, "Erro: não foi possível criar o arquivo saida.txt!\n");
		fclose(in);
		return 3;
	}
	chave = atoi(argv[3]);
	if (strcmp(argv[2], "-c") == 0) { // criptografar
		while ((ch = fgetc(in)) != EOF) {
			ch += chave;
			fputc(ch, out);
		}
	}
	else if (strcmp(argv[2], "-d") == 0) { // descriptografar
		while ((ch = fgetc(in)) != EOF) {
			ch -= chave;
			fputc(ch, out);
		}
	}
	else {
		fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <arquivo> <-c|-d> <chave>\n", 
		        argv[0]);
		return 1;
	}
	fclose(in);
	fclose(out);
	return 0;
}
