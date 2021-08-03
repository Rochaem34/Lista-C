/*
15. Botas Trocadas 1 (1a fase da Olimpíada Brasileira de Informática 2017 – Programação Nível 2) A 
divisão de Suprimentos de Botas e Calçados do Exército comprou um grande número de pares de 
botas de vários tamanhos para seus soldados. No entanto, por uma falha de empacotamento da 
fábrica contratada, nem todas as caixas entregues continham um par de botas correto, com duas 
botas do mesmo tamanho, uma para cada pé. O sargento mandou que os recrutas retirassem todas 
as botas de todas as caixas para reembalá-las, desta vez corretamente.
Quando o sargento descobriu que você sabia programar, ele solicitou com a gentileza habitual que
você escrevesse um programa que, dada a lista contendo a descrição de cada bota entregue,
determina quantos pares corretos de botas poderão ser formados no total.

Entrada
A primeira linha da entrada contém um inteiro N indicando o número de botas individuais
entregues. Cada uma das N linhas seguintes descreve uma bota, contendo um número inteiro M e
uma letra L, separados por um espaço em branco. M indica o número do tamanho da bota e L
indica o pé da bota: L = ‘D’ indica que a bota é para o pé direito, L = ‘E’ indica que a bota é para o
pé esquerdo.

Saída
Seu programa deve imprimir uma linha contendo um único número inteiro indicando o número
total de pares corretos de botas que podem ser formados.

Restrições
• 2 ≤ N ≤ 10 4
• N é par
• 30 ≤ M ≤ 60
• L ∈ { { D, E}
*/

#include <stdio.h>

int main()
{
    int e[31] = { 0 }, d[31] = { 0 };
    int n, m, i, pares;
    char l;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %c", &m, &l);
        if (l == 'E') {
            e[m - 30]++;
        }
        else {
            d[m - 30]++;
        }
    }
    pares = 0;
    for (i = 0; i < 31; i++) {
        pares += (e[i] < d[i] ? e[i] : d[i]);
        /*
        if (e[i] < d[i]) {
            pares += e[i];
        }
        else {
            pares += d[i];
        }
        */
    }
    printf("%d\n", pares);
    return 0;
}