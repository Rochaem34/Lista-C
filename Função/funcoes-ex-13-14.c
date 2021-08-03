/*
13. A função floor , definida no arquivo math.h, arredonda seu argumento (um número do tipo
double ) para o maior inteiro que não seja maior que esse argumento, na prática, isso significa
devolver a parte inteira do argumento. Entretanto, o valor de retorno da função floor é um
double . Crie uma função de protótipo int arredondar_para_int(double n); que
arredonda seu parâmetro n para o inteiro mais próximo. Dica: some 0.5 a n e utilize a função
floor . Escreva um programa que leia vários números e use a função
arredondar_para_int para arredondar cada um desses números para o inteiro mais
próximo.

14. Escreva uma função de protótipo double arredondar(double n, int c); que
arredonda o valor de n para um número com precisão de c casas decimais. Por exemplo,
arredondar(5.78351, 1) devolve 5.8 , arredondar(5.78351, 2) devolve 5.78 ,
arredondar(5.78351, 3) devolve 5.784. Dica: utilize a função arredondar_para_int 
passando seu argumento multiplicado por 10^c , e depois divida o valor de retorno 
da função por 10^c .
*/

#include <stdio.h>
#include <math.h>

int arredondar_para_int(double);
double arredondar(double, int);

int main()
{
    double num;
    int precisao;
    printf("Digite um numero real: ");
    scanf("%lf", &num);
    printf("%lf arredondado para o inteiro mais proximo: %d\n",
           num, arredondar_para_int(num));
    printf("\nDigite a precisao do arrendondamento: ");
    scanf("%d", &precisao);
    printf("%lf arredondado com precisao %d: %lf\n",
           num, precisao, arredondar(num, precisao));
    return 0;
}

int arredondar_para_int(double n)
{
    return (int) floor(n + 0.5);
}

double arredondar(double n, int c)
{
    return arredondar_para_int(n * pow(10, c)) / pow(10, c);
}