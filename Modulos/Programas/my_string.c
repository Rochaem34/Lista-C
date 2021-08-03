/* my_string.c
 * Implementação das minhas funções de manipulação de strings.
 */

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char * strupper(char * str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
} 

char * strlower(char * str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
} 

char * trim(char * str)
{
    int i, j;
    // retira os espaços do final da string
    for (i = strlen(str) - 1; i >= 0 && str[i] == ' '; i--);
    str[i + 1] = '\0';

    // retira os espaços do início da string
    for (i = 0; str[i] == ' ' && str[i] != '\0'; i++);
    if (i > 0) {
        for (j = 0; str[j + i] != '\0'; j++) {
            str[j] = str[j + i];
        }
        str[j] = '\0';
    }
    return str;
}

bool endswith(const char * str, const char * tail)
{
    int tam_str = strlen(str), tam_tail = strlen(tail);
    if (tam_str >= tam_tail) {
        int i, j;
        for (i = tam_str - 1, j = tam_tail - 1; j >= 0; i--, j--) {
            if (str[i] != tail[j]) {
                return false;
            }
        }
        return true;
    }
    return false;
}