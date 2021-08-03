/*
27. Caçadores de Mitos 2 (1a fase da Olimpíada Brasileira de Informática 2009 – Programação Nível 2)
Jorge é um apresentador de televisão que comanda a versão brasileira do grande sucesso Caçadores
de Mitos, onde se estuda um mito para descobrir se é fato ou apenas um boato.
No próximo episódio, Jorge deverá apresentar o mito que diz que “os raios não caem duas vezes no
mesmo lugar”, referindo-se aos raios das tempestades de chuva.
Para isso, foi até a cidade de Eletrolândia, que é a cidade com maior ocorrência de raios no mundo.
O prefeito tem tanto orgulho desse título que mandou criar um sistema para registrar os raios. Jorge
conseguiu um relatório com as ocorrências de cada raio que caiu na cidade nos últimos anos.
O mapa de Eletrolândia é um retângulo. Para o sistema de registro a cidade é subdividida em
quadrados de um metro de lado, denominados quadrantes. Assim, se a cidade tem 300 metros de
largura e 1000 de comprimento, ela será subdividida em 300.000 quadrantes. O sistema de registro
armazena o quadrante em que o raio caiu. Cada quadrante é identificado pelas suas coordenadas X
e Y, conforme ilustra a figura abaixo, que exemplifica um mapa de uma cidade com oito metros de
comprimento por cinco metros de largura (quarenta quadrantes).
*/

#include <stdio.h>

int main()
{
    int mapa[501][501] = { 0 }, i, x, y, n, resp = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        mapa[x][y]++;
        if (mapa[x][y] > 1) {
            resp = 1;
        }
    }
    printf("%d\n", resp);
    return 0;
}