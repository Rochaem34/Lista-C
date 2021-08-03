/* testa_my_string.c */

#include "my_string.h"
#include <stdio.h>

int  main()
{
    char str[] = "          Fatec Carapicuiba       ";
    printf("\"%s\"\n", strupper(str));
    printf("\"%s\"\n", strlower(str));
    printf("\"%s\"\n", trim(str));
    printf("%s\n", endswith(str, "uiba") ? "Sim": "Nao");
    return 0;
}