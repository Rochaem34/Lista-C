/*
3)Escreva um programa que receba um nome completo e apresente apenas o último
sobrenome e o primeiro nome separados por uma vírgula. Por exemplo:
Ciro Cirne Trindade
Trindade, Ciro
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[81];
    int i;
    printf("Informe seu nome completo: ");
    scanf(" %80[^\n]", nome);

    for (i = strlen(nome) - 1; i >= 0 && nome[i] == ' '; i--); // procura o 1o. caractere diferente de espaço em branco no final do nome
    
    nome[i + 1] = '\0'; // retira os espaços em brando do final do nome

    for (; i >= 0 && nome[i] != ' '; i--);

    if (i < 0) {
        puts("Erro: voce nao informou um nome completo!");
    }
    else {
        printf("%s, ", &nome[i + 1]);  // imprime o último sobrenome

        for (i = 0; nome[i] != ' '; i++) {
            putchar(nome[i]);
        }
        printf("\n");
    }
    return 0;
}