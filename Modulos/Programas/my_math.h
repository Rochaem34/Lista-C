/* my_math.h */

#ifndef _MY_MATH_H
#define _MY_MATH_H

/* função que devolve o fatorial do seu parâmetro */
long long fatorial(int);

/* função arredonda o seu parâmetro para para o inteiro mais próximo */
int arredondar_para_int(double);

/* arredonda o primeiro parâmetro com a precisão dada pelo segundo parâmetro */
double arredondar(double, int);

#endif