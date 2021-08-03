/* my_string.h
 * Definições dos protótipos das minhas funções de manipulação
 * de strings.
 */

#ifndef _MY_STRING_H
#define _MY_STRING_H
#include <stdbool.h>

/* converte para maiúsculo todos os caracteres da string
apontada por str e devolve o ponteiro para a string convertida str */
char * strupper(char * str); 

/* converte para minúsculo todos os caracteres da string
apontada por str e devolve o ponteiro para a string convertida str */
char * strlower(char * str);

/*  retira os espaços em branco antes e depois da string
apontada por str e devolve o ponteiro para a string str sem os espaços */
char * trim(char * str); 

/* substitui todas as ocorrências do cararectere oldchar por newchar 
na string apontada por str e devolve o ponteiro para string str após 
as substituições */
char * replace(char * str, char oldchar, char newchar);

/* devolve verdadeiro se a string apontada por str terminar com a 
string apontada por tail; ou falso, caso contrário */
bool endswith(const char * str, const char * tail); 

#endif