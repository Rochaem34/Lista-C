#include <stdio.h>

int main()
{
    //char naipes[][8] = { "Copas", "Ouro", "Paus", "Espadas" };
    char * naipes[] = { "Copas", "Ouro", "Paus", "Espadas" };
    for (int i = 0; i < 4; i++) {
        puts(naipes[i]);
    }
    //scanf("%7s", naipes[0]);
    naipes[0] = "Outro";
    puts(naipes[0]);
    return 0;
}