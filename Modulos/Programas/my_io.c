#include <stdio.h>
#include <stdbool.h>

#include "my_io.h"

void read_line (char line[], int max_length)
{
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (i < max_length) {
            line[i++] = ch;
        }
    }
    line[i] = '\0';
}

bool read_int (int * var)
{
    int result;
    char line[MAX_LENGTH + 1];
    read_line(line, MAX_LENGTH);
    result = sscanf(line, "%d", var);
    return (result == 1);
}

bool read_float (float * var)
{
    int result;
    char line[MAX_LENGTH + 1];
    read_line(line, MAX_LENGTH);
    result = sscanf(line, "%f", var);
    return (result == 1);
}

bool read_double (double * var)
{
    int result;
    char line[MAX_LENGTH + 1];
    read_line(line, MAX_LENGTH);
    result = sscanf(line, "%lf", var);
    return (result == 1);
}